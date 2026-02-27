Install OpenLDAP dev libraries for C++:

Ubuntu/Debian: sudo apt update && sudo apt install libldap2-dev
This gives you ldap.h and links against -lldap.

Compile examples with: g++ yourfile.cpp -o ldap_app -lldap -llber (add -lssl -lcrypto if using LDAPS).

C++ LDAP CRUD Operations:

LDAP in C++: The API is C-style (functions like ldap_initialize, ldap_search_ext_s), so we use pointers and manual memory management. It's verbose but gives fine control. For production, consider wrappers like ldapcpp, but this is great for learning.
CRUD Mapping:
Create (Add): ldap_add_ext_s – Adds a new entry with attributes.
Read (Search): ldap_search_ext_s – Queries entries with filters.
Update (Modify): ldap_modify_ext_s – Changes attributes (replace, add, delete).
Delete: ldap_delete_ext_s – Removes an entry.

Binding: Authenticate first (e.g., as admin) for writes.
Error Handling: Check return codes (e.g., LDAP_SUCCESS) and use ldap_err2string.
Your Setup: This code targets your Docker OpenLDAP at ldap://localhost:389, admin DN cn=admin,dc=example,dc=com, password admin. Test against your existing tree (e.g., add under ou=People).

Prerequisites

Install OpenLDAP dev libs: sudo apt install libldap2-dev (on Ubuntu).
Compile: g++ ldap_crud.cpp -o ldap_crud -lldap -llber (add -lssl -lcrypto if using LDAPS later).
Run: ./ldap_crud (ensure Docker is up: docker compose up -d).