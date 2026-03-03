OpenLDAP is an open-source implementation of the LDAP protocol. It's a server that hosts a directory service, allowing you to store and query hierarchical data (e.g., users, groups) over a network. It's lightweight, extensible, and widely used for authentication (e.g., in SSO systems), configuration management, or as a backend for apps requiring directory services.

Key Features:
    # Supports LDAPv3 (the standard protocol).
    # Backends: Various storage options like Berkeley DB (default), MDB (Lightning Memory-Mapped Database for better  performance), or even SQL.
    # Replication: For high availability (master-slave or multi-master).
    # Overlays: Extensions for features like password policies or dynamic groups.
    # Schemas: Customizable rules for data structure (e.g., adding custom attributes).

how to Install OpenLDAP on Linux in docker container (root will be default user)

step 1: Create a docker-compose.yml file with the following content:
    version: '3.8'
    services:
    openldap:
        image: osixia/openldap:latest
        container_name: openldap
        environment:
        LDAP_ORGANISATION: "Example Inc"
        LDAP_DOMAIN: "example.com"
        LDAP_ADMIN_PASSWORD: "admin"
        LDAP_BASEDN: "dc=example,dc=com"
        LDAP_TLS: "false"  # Set to "true" later for TLS
        ports:
        - "389:389"
        - "636:636"  # For LDAPS
        restart: unless-stopped

    phpldapadmin:  # Optional GUI
        image: osixia/phpldapadmin:latest
        container_name: phpldapadmin
        environment:
        PHPLDAPADMIN_LDAP_HOSTS: openldap
        PHPLDAPADMIN_HTTPS: "false"
        ports:
        - "8080:80"
        depends_on:
        - openldap
        restart: unless-stopped
step 2:
    To run:
    docker-compose up -d

step 3:
    Access phpLDAPadmin at http://localhost:8080

    Default login:
        Username: cn=admin,dc=example,dc=com
        Password: admin
step 4: test LDAP connection using ldapsearch:
    ldapsearch -x -H ldap://localhost:389 -b "dc=example,dc=com" -D "cn=admin,dc=example,dc=com" -w admin

    command breakdown:
        - -x: Simple authentication
        - -H: LDAP URI
        - -b: Base DN for search
        - -D: Bind DN (admin user)
        - -w: Password for bind DN
    output:
        # extended LDIF
        #
        # LDAPv3
        # base <dc=example,dc=com> with scope subtree
        # filter: (objectclass=*)
        # requesting: ALL
        #

        # example.com
        dn: dc=example,dc=com
        objectClass: top
        objectClass: dcObject
        objectClass: organization
        o: Example Inc
        dc: example

        # search result
        search: 2
        result: 0 Success

        # numResponses: 2
        # numEntries: 1

Exercise 1: Create Organizational Units (OUs)

    OUs are containers for organizing entries (like folders).
    1. Create an LDIF file create_ous.ldif with the following content:
    dn: ou=People,dc=example,dc=com
    objectClass: top
    objectClass: organizationalUnit
    ou: People
    description: Container for user entries

    dn: ou=Groups,dc=example,dc=com
    objectClass: top
    objectClass: organizationalUnit
    ou: Groups
    description: Container for group entries

    explaination : This LDIF file defines two OUs: "People" for user entries and "Groups" for group entries.
    2. Apply the LDIF file using ldapadd:
    ldapadd -x -H ldap://localhost:389 -D "cn=admin,dc=example,dc=com" -w admin -f create_ous.ldif

    command explaination: this command adds the OUs defined in create_ous.ldif to the LDAP directory. 
    -x for simple authentication, -H specifies the LDAP server, -D is the bind DN (admin user), -w is the password, and -f specifies the LDIF file to apply.

    3. Verify the OUs were created:
    ldapsearch -x -H ldap://localhost:389 -b "dc=example,dc=com" -D "cn=admin,dc=example,dc=com" -w admin

    command: root@2024PUNLTP07415:~/Abhay/Security/Day7# ldapsearch -x -H ldap://localhost:389 -b "dc=example,dc=com" -D "cn=admin,dc=example,dc=com" -w admin

    output:
        # extended LDIF
        #
        # LDAPv3
        # base <dc=example,dc=com> with scope subtree
        # filter: (objectclass=*)
        # requesting: ALL
        #

        # example.com
        dn: dc=example,dc=com
        objectClass: top
        objectClass: dcObject
        objectClass: organization
        o: Example Inc
        dc: example

        # People, example.com
        dn: ou=People,dc=example,dc=com
        objectClass: top
        objectClass: organizationalUnit
        ou: People
        description: Container for user entries

        # Groups, example.com
        dn: ou=Groups,dc=example,dc=com
        objectClass: top
        objectClass: organizationalUnit
        ou: Groups
        description: Container for group entries

        # search result
        search: 2
        result: 0 Success

        # numResponses: 4
        # numEntries: 3

    command explaination: This ldapsearch command queries the LDAP directory starting from the base DN "dc=example,dc=com" and retrieves all entries. The output shows the base entry and the two newly created OUs: "People" and "Groups", confirming they were successfully added to the directory.

    4. GUI Verification (Optional):
    If you're using phpLDAPadmin, log in at http://localhost:8080 with the admin credentials. You should see the "People" and "Groups" OUs listed under the domain "example.com".

*************
What are crud operations in LDAP?
CRUD operations in LDAP refer to the four basic functions used to manage entries in an LDAP directory:
1. Create: Adding new entries to the directory.
2. Read: Retrieving and viewing existing entries.
3. Update: Modifying existing entries.
4. Delete: Removing entries from the directory.

***********

exercise 2: Add Users (Create Entries) : To add user entries under the "People" OU. 

    1. Create an LDIF file add_users.ldif with the following content:
        dn: uid=abhay,ou=People,dc=example,dc=com
        objectClass: top
        objectClass: person
        objectClass: organizationalPerson
        objectClass: inetOrgPerson
        cn: Abhay Kumar
        sn: Kumar
        givenName: Abhay
        uid: abhay
        mail: abhay@example.com
        userPassword: password123  # Plain text for testing; hash in prod

        dn: uid=jane,ou=People,dc=example,dc=com
        objectClass: top
        objectClass: person
        objectClass: organizationalPerson
        objectClass: inetOrgPerson
        cn: Jane Doe
        sn: Doe
        givenName: Jane
        uid: jane
        mail: jane@example.com
        userPassword: secret456

    command explaination: This LDIF file defines two user entries, "abhay" and "jane", with various attributes like common name (cn), surname (sn), user ID (uid), email (mail), and password (userPassword).
    2. Apply the LDIF file using ldapadd:
        ldapadd -x -H ldap://localhost:389 -D "cn=admin,dc=example,dc=com" -w admin -f add_users.ldif
    3. Search for users
        ldapsearch -x -H ldap://localhost:389 -b "ou=People,dc=example,dc=com" -D "cn=admin,dc=example,dc=com" -w admin

<!--
Documentation: OpenLDAP Groups and Memberships (groupOfNames)

This exercise introduces how to model *groups* in OpenLDAP and how to represent *membership* using LDAP object classes and attributes.

Core concept
- A group entry is a normal LDAP entry stored in the directory tree (DIT), just like users.
- “Membership” is not computed automatically; it is represented explicitly by attributes on the group entry (or alternatively on the user entry, depending on schema/design).
- In this exercise, the group object class used is **groupOfNames**, which stores members as **Distinguished Names (DNs)** via the **member** attribute.

What is `groupOfNames`?
- `groupOfNames` is a standard LDAP structural object class commonly used for groups.
- It is intended to represent a named group that contains one or more “member” entries.
- Typical required attributes (schema-dependent, but commonly):
    - `cn`: the group’s common name (human-friendly identifier)
    - `member`: one or more DNs pointing to entries that belong to the group

How membership works here
- Membership is represented by **listing user DNs** in the group’s `member` attribute.
- A “member” value is not a username; it’s a full DN such as:
    - `uid=alice,ou=People,dc=example,dc=com`
- Because LDAP uses DNs, membership references are unambiguous and stable within the directory structure (as long as DNs do not change).

Why DNs matter
- DNs uniquely identify an entry’s location in the directory tree.
- The `member` attribute values must point to existing entries; otherwise, the group will contain references to non-existent members.
- If a user is moved/renamed (DN changes), the group’s `member` values may need to be updated to keep membership accurate.

Implications and best practices
- `groupOfNames` generally expects **at least one member** (many schemas enforce that `member` is mandatory). This means:
    - You may need to add a placeholder member initially (or use an alternative class such as `groupOfUniqueNames` / other schemas) if you want empty groups.
- Groups are usually placed under a dedicated OU such as `ou=Groups`, while users live under `ou=People`, keeping the DIT organized.
- Access control (ACLs) often rely on group membership (e.g., granting read/write permissions to members of a certain group).

What you should accomplish in this exercise
- Create a group entry using `groupOfNames`.
- Populate the group’s `member` attribute with the DNs of user entries you want to include.
- Verify group membership by querying the group entry and checking the `member` attribute values.

Outcome
- After completing this step, your directory will contain:
    - One or more group entries (using `groupOfNames`)
    - Membership mappings from group → user(s) via `member` DN references
-->
Exercise 3: Add Groups and Memberships

    Groups use groupOfNames and reference user DNs via member, It means we can create groups and add users to them.

    dn: cn=admins,ou=Groups,dc=example,dc=com
    objectClass: top
    objectClass: groupOfNames
    cn: admins
    description: Admin group
    member: uid=abhay,ou=People,dc=example,dc=com


    dn: cn=users,ou=Groups,dc=example,dc=com
    objectClass: top
    objectClass: groupOfNames
    cn: users
    description: Regular users
    member: uid=jane,ou=People,dc=example,dc=com
    member: uid=abhay,ou=People,dc=example,dc=com  # Multi-member
    
    command explaination: This LDIF file defines two groups: "admins" and "users". The "admins" group includes the user "abhay" as a member, while the "users" group includes both "jane" and "abhay".

    2. Apply the LDIF file using ldapadd:
        ldapadd -x -H ldap://localhost:389 -D "cn=admin,dc=example,dc=com" -w admin -f add_groups.ldif
    3. Search for groups and their members:
        ldapsearch -x -H ldap://localhost:389 -b "ou=Groups,dc=example,dc=com" -D "cn=admin,dc=example,dc=com" -w admin
    
Exercise 4: Modify and Delete Entries (Update/Delete)

1. Modify a user's email (use ldapmodify with LDIF update_user.ldif):

    dn: uid=abhay,ou=People,dc=example,dc=com
    changetype: modify
    replace: mail
    mail: abhay.new@example.com
    add: telephoneNumber
    telephoneNumber: +91-1234567890  # Add new attribute
2. Apply the modification:
    ldapmodify -x -H ldap://localhost:389 -D "cn=admin,dc=example,dc=com" -w admin -f update_user.ldif
3. Verify the update:
    ldapsearch -x -H ldap://localhost:389 -b "uid=abhay,ou=People,dc=example,dc=com" -D "cn=admin,dc=example,dc=com" -w admin
4. Delete a user (use ldapdelete):
    ldapdelete -x -H ldap://localhost:389 -D "cn=admin,dc=example,dc=com" -w admin "uid=jane,ou=People,dc=example,dc=com"

    ldapdelete: This is the CLI tool for performing the "Delete" part of CRUD (Create, Read, Update, Delete) in LDAP. It removes an entire entry (and its attributes) from the Directory Information Tree (DIT).
    It won't delete if the entry has children (sub-entries)—LDAP protects the hierarchy. In this case, user entries like "jane" are leaves (no children), so it's safe.
    This is a destructive operation: Once deleted, the entry is gone unless you have backups (e.g., via slapcat for export).
    -x:
    Specifies simple authentication. This means it uses a basic username (DN) and password for binding (logging in) to the LDAP server.
    Why? LDAP supports various auth methods (e.g., SASL for more secure options like Kerberos), but -x keeps it simple for testing. In production, avoid plain text over unencrypted connections.

    -H ldap://localhost:389:
    The LDAP URI (Uniform Resource Identifier) to connect to the server.
    ldap://: Protocol (unencrypted LDAP; use ldaps:// for TLS-encrypted).
    localhost: Host (your local machine, since it's Docker-hosted).
    :389: Port (default for LDAP).
    Why? Tells the tool where the server is. In your setup, this points to the OpenLDAP container.

    -D "cn=admin,dc=example,dc=com":
    The bind DN (Distinguished Name) for authentication.
    This is the admin user's full path in the DIT: cn=admin (RDN) under the base dc=example,dc=com.
    Why? You need admin privileges to delete entries. Regular users can't delete others' entries (due to ACLs—Access Control Lists). Binding as admin grants full access.

    -w admin:
    The password for the bind DN.
    -w provides it directly (insecure for scripts—use -W to prompt interactively in production).
    Why? Completes the authentication. If wrong, you'll get "Invalid credentials" error.

    "uid=jane,ou=People,dc=example,dc=com":
    This is the target DN—the entry to delete.
    uid=jane: RDN (unique identifier within its parent).
    ou=People: Container (Organizational Unit) where users are stored (from Exercise 1).
    dc=example,dc=com: Base suffix (root of your directory).
    Why quotes? Protects the DN from shell interpretation (e.g., commas).
    Ties to concepts: DN uniquely identifies the entry. If it doesn't exist, you'll get "No such object."
5. Verify deletion:
    ldapsearch -x -H ldap://localhost:389 -b "ou=People,dc=example,dc=com" -D "cn=admin,dc=example,dc=com" -w admin