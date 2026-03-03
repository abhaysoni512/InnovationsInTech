#include <iostream>
#include <ldap.h>
#include <string>
#include <vector>
#include <cstring> 

// Helper function to print search results
void printSearchResults(LDAP* ld, LDAPMessage* res) {
    int numEntries = ldap_count_entries(ld, res);
    std::cout << "Found " << numEntries << " entries." << std::endl;

    for (LDAPMessage* entry = ldap_first_entry(ld, res); entry != nullptr; entry = ldap_next_entry(ld, entry)) {
        char* dn = ldap_get_dn(ld, entry);
        std::cout << "DN: " << dn << std::endl;
        ldap_memfree(dn);

        // Print attributes
        BerElement* ber = nullptr;
        for (char* attr = ldap_first_attribute(ld, entry, &ber); attr != nullptr; attr = ldap_next_attribute(ld, entry, ber)) {
            struct berval** vals = ldap_get_values_len(ld, entry, attr);
            if (vals) {
                for (int i = 0; vals[i] != nullptr; ++i) {
                    std::cout << "  " << attr << ": " << vals[i]->bv_val << std::endl;
                }
                ldap_value_free_len(vals);
            }
            ldap_memfree(attr);
        }
        if (ber) ber_free(ber, 0);
        std::cout << std::endl;
    }
}

int main() {
    LDAP* ld = nullptr;
    int rc;

    // Step 1: Initialize and Bind
    const std::string ldapUri = "ldap://localhost:389";
    rc = ldap_initialize(&ld, ldapUri.c_str());
    if (rc != LDAP_SUCCESS) {
        std::cerr << "ldap_initialize failed: " << ldap_err2string(rc) << std::endl;
        return 1;
    }

    // Set LDAP protocol version to 3
    int version = LDAP_VERSION3;
    rc = ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version);
    if (rc != LDAP_OPT_SUCCESS) {
        std::cerr << "Failed to set LDAP version: " << ldap_err2string(rc) << std::endl;
        ldap_unbind_ext_s(ld, nullptr, nullptr);
        return 1;
    }

    const std::string bindDN = "cn=admin,dc=example,dc=com";
    const std::string bindPW = "admin";
    struct berval cred = {static_cast<ber_len_t>(bindPW.length()), const_cast<char*>(bindPW.c_str())};
    rc = ldap_sasl_bind_s(ld, bindDN.c_str(), LDAP_SASL_SIMPLE, &cred, nullptr, nullptr, nullptr);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Bind failed: " << ldap_err2string(rc) << std::endl;
        ldap_unbind_ext_s(ld, nullptr, nullptr);
        return 1;
    }
    std::cout << "Bound successfully as admin!" << std::endl;

    // Step 2: Create (Add a new user)
    const std::string newUserDN = "uid=testuser,ou=People,dc=example,dc=com";
    LDAPMod* addMods[8];  // Array for attributes + null
    LDAPMod oc, cn, sn, uid, mail, pw, desc;

    // objectClass (multi-value)
    const char* ocVals[] = {"top", "person", "organizationalPerson", "inetOrgPerson", nullptr};
    oc.mod_op = LDAP_MOD_ADD;
    oc.mod_type = const_cast<char*>("objectClass");
    oc.mod_values = const_cast<char**>(const_cast<char**>(ocVals));
    addMods[0] = &oc;

    // cn
    const char* cnVals[] = {"Test User", nullptr};
    cn.mod_op = LDAP_MOD_ADD;
    cn.mod_type = const_cast<char*>("cn");
    cn.mod_values = const_cast<char**>(cnVals);
    addMods[1] = &cn;

    // sn
    const char* snVals[] = {"User", nullptr};
    sn.mod_op = LDAP_MOD_ADD;
    sn.mod_type = const_cast<char*>("sn");
    sn.mod_values = const_cast<char**>(snVals);
    addMods[2] = &sn;

    // uid
    const char* uidVals[] = {"testuser", nullptr};
    uid.mod_op = LDAP_MOD_ADD;
    uid.mod_type = const_cast<char*>("uid");
    uid.mod_values = const_cast<char**>(uidVals);
    addMods[3] = &uid;

    // mail
    const char* mailVals[] = {"test@example.com", nullptr};
    mail.mod_op = LDAP_MOD_ADD;
    mail.mod_type = const_cast<char*>("mail");
    mail.mod_values = const_cast<char**>(mailVals);
    addMods[4] = &mail;

    // userPassword (plain for testing; hash in prod)
    const char* pwVals[] = {"testpass123", nullptr};
    pw.mod_op = LDAP_MOD_ADD;
    pw.mod_type = const_cast<char*>("userPassword");
    pw.mod_values = const_cast<char**>(pwVals);
    addMods[5] = &pw;

    // description (optional)
    const char* descVals[] = {"Test account for CRUD demo", nullptr};
    desc.mod_op = LDAP_MOD_ADD;
    desc.mod_type = const_cast<char*>("description");
    desc.mod_values = const_cast<char**>(descVals);
    addMods[6] = &desc;

    addMods[7] = nullptr;  // Null-terminate

    rc = ldap_add_ext_s(ld, newUserDN.c_str(), addMods, nullptr, nullptr);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Add failed: " << ldap_err2string(rc) << std::endl;
    } else {
        std::cout << "User added: " << newUserDN << std::endl;
    }

    // Step 3: Read (Search for users)
    const std::string base = "ou=People,dc=example,dc=com";
    const std::string filter = "(objectClass=inetOrgPerson)";
    const char* attrs[] = {"cn", "sn", "mail", "uid", "description", nullptr};  // Specific attrs + null

    LDAPMessage* res = nullptr;
    rc = ldap_search_ext_s(ld, base.c_str(), LDAP_SCOPE_SUBTREE, filter.c_str(), const_cast<char**>(attrs), 0, nullptr, nullptr, nullptr, 0, &res);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Search failed: " << ldap_err2string(rc) << std::endl;
    } else {
        std::cout << "\nSearch Results:" << std::endl;
        printSearchResults(ld, res);
    }
    ldap_msgfree(res);

    // Step 4: Update (Modify email and add phone)
    LDAPMod modMail, modPhone;
    const char* newMailVals[] = {"newtest@example.com", nullptr};
    modMail.mod_op = LDAP_MOD_REPLACE;
    modMail.mod_type = const_cast<char*>("mail");
    modMail.mod_values = const_cast<char**>(newMailVals);

    const char* phoneVals[] = {"+1-234-567890", nullptr};
    modPhone.mod_op = LDAP_MOD_ADD;
    modPhone.mod_type = const_cast<char*>("telephoneNumber");
    modPhone.mod_values = const_cast<char**>(phoneVals);

    LDAPMod* modMods[] = {&modMail, &modPhone, nullptr};

    rc = ldap_modify_ext_s(ld, newUserDN.c_str(), modMods, nullptr, nullptr);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Modify failed: " << ldap_err2string(rc) << std::endl;
    } else {
        std::cout << "\nUser updated (new email and phone added)." << std::endl;
    }

    // Verify update with quick search
    rc = ldap_search_ext_s(ld, base.c_str(), LDAP_SCOPE_SUBTREE, "(uid=testuser)", const_cast<char**>(attrs), 0, nullptr, nullptr, nullptr, 0, &res);
    if (rc == LDAP_SUCCESS) {
        std::cout << "Post-Update Search:" << std::endl;
        printSearchResults(ld, res);
        ldap_msgfree(res);
    }

    // Step 5: Delete
    rc = ldap_delete_ext_s(ld, newUserDN.c_str(), nullptr, nullptr);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Delete failed: " << ldap_err2string(rc) << std::endl;
    } else {
        std::cout << "\nUser deleted: " << newUserDN << std::endl;
    }

    // Step 6: Unbind
    ldap_unbind_ext_s(ld, nullptr, nullptr);
    std::cout << "Unbound from LDAP server." << std::endl;

    return 0;
}