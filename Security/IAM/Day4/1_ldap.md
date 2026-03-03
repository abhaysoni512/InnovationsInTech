# ldap protocol

Lightweight Directory Access Protocol (LDAP) is an internet protocol works on TCP/IP, used to access information from directories. LDAP (Lightweight Directory Access Protocol) is an open, vendor-neutral protocol for accessing and maintaining distributed directory information services over a network. It's essentially a way to query and manage a centralized database of information organized in a hierarchical, tree-like structure—think of it as a phone book or address book for networks, but for things like users, groups, devices, configurations, and more. LDAP is based on the X.500 standard but simplified for efficiency. LDAP is commonly used for authentication (e.g., single sign-on in enterprises), authorization, and storing organizational data. Popular implementations include OpenLDAP (open-source), Microsoft Active Directory (which supports LDAP), and others like Apache Directory Server.

Some terms used in LDAP:-

1. Directory Service Basics

    Directory: A specialized database optimized for reading (queries) rather than writing. It's hierarchical and designed for fast lookups of structured data.
    Directory Service: The system that provides access to the directory via protocols like LDAP. It stores information about entities (e.g., people, computers) in a way that's easy to search and manage across a network.
    Why LDAP? It's "lightweight" compared to heavier protocols, supports TCP/IP, and is extensible. It's read-heavy, with features for replication, security (e.g., TLS), and access controls.

2. Directory Information Tree (DIT)

    The DIT is the overall structure of the directory, organized as an inverted tree (root at the top, leaves at the bottom).
    Root: The top-level entry, often defined by the domain (e.g., dc=example,dc=com where dc stands for Domain Component).
    Branches and Leaves: Sub-entries branch out, forming a hierarchy. This mirrors organizational structures, like departments or locations.
    Example DIT:
    Root: dc=example,dc=com
    Organizational Unit (OU): ou=People,dc=example,dc=com (for users)
    OU: ou=Groups,dc=example,dc=com (for groups)
    User entry: uid=johndoe,ou=People,dc=example,dc=com

    The tree allows efficient navigation and scoping searches (e.g., search only under ou=People).
3. Entries

    An Entry is the basic unit of information in LDAP—a single record in the directory, like a row in a database.
    Each entry represents an object (e.g., a user, group, device).
    Entries are uniquely identified and must conform to a schema (rules defining structure).

4. Distinguished Name (DN) and Relative Distinguished Name (RDN)

    DN (Distinguished Name): The full, unique path to an entry in the DIT, read from right to left (root to leaf). It's like a file path in a filesystem.
    Example: uid=johndoe,ou=People,dc=example,dc=com
    This means: The entry with uid=johndoe under the OU People in the domain example.com.

    RDN (Relative Distinguished Name): The leftmost part of the DN, unique within its parent container.
    In the example: uid=johndoe

    DNs ensure no duplicates and enable precise referencing for operations.

5. Attributes

    Attributes are key-value pairs that store the actual data in an entry.
    Syntax: Each attribute has a name (e.g., cn), a value (e.g., "John Doe"), and rules (e.g., single-valued like uid or multi-valued like member in groups).
    Common attributes:
    dn: Auto-generated unique identifier (not editable).
    cn (Common Name): Full name, e.g., "John Doe".
    sn (Surname): Last name, e.g., "Doe".
    givenName: First name.
    uid: User ID, e.g., "johndoe" (unique identifier).
    mail: Email address.
    userPassword: Stored password (usually hashed for security).
    member: For groups, lists member DNs.

    to check all attributes of an entry use command :-
        
        
    Attributes can be mandatory (required) or optional, and some support multiple values (e.g., a user with multiple emails).

6. Object Classes

    An objectClass defines what type of entry it is and which attributes it can/must have.
    Every entry must have at least one structural objectClass (defines the core type) and can have auxiliary ones (add extra attributes).
    Common objectClasses:
    top: Base class (all entries inherit this).
    person: Basic person with cn and sn.
    organizationalPerson: Adds address/phone.
    inetOrgPerson: Popular for users; adds uid, mail, userPassword.
    organizationalUnit (ou): For containers like departments.
    groupOfNames: For groups; requires cn and at least one member.

    ObjectClasses enforce structure: e.g., inetOrgPerson requires cn and sn.

7. Schema

    The Schema is a set of rules defining allowed objectClasses, attributes, their syntax (e.g., string, integer), matching rules (e.g., case-insensitive), and inheritance.
    Schemas are extensible—you can add custom attributes/classes.
    Loaded at server startup; ensures data consistency and prevents invalid entries.

8. LDAP Operations (High-Level)
    While not core "concepts," operations tie everything together:

    Bind: Authenticate to the server (e.g., as admin or user).
    Search: Query entries with filters (e.g., (objectClass=inetOrgPerson) or (&(uid=johndoe)(mail=*@example.com))—uses LDAP filter syntax).
    Add/Modify/Delete: CRUD on entries/attributes.
    Compare/Extended: Advanced ops like password verification.

9. Security and Best Practices

    Authentication: Simple (username/password) or SASL (e.g., Kerberos).
    Encryption: Use LDAPS (LDAP over TLS) for secure connections.
    Access Control: ACLs define who can read/write what (e.g., users can change own password but not others').
    Replication: Servers can sync for high availability.

# LDAP architecture :-

# LDAP Architecture:-
LDAP architecture is based on client-server model. LDAP clients communicate with LDAP servers to access the directory information. LDAP server contains the database which stores the directory information.

![alt text](image.png)

LDAP defines operations for accessing and modifying directory entries such as:
    Searching for user specified criteria
    Adding an entry
    Deleting an entry
    Modifying an entry
    Modifying the distinguished name or relative distinguished name of an entry
    Comparing an entry

# LDAP Models:  LDAP can be explained by using four models upon which it based:-

    1. Information Model: It defines the types of data that can be stored in the directory and the relationships between them. The information model is based on the X.500 standard and defines a hierarchical structure for storing directory entries.
    2. Naming Model: It defines how directory entries are named and identified. The naming model uses distinguished names (DNs) to uniquely identify each entry in the directory.
    3. Functional Model: It defines the operations that can be performed on the directory entries, such as searching, adding, modifying, and deleting entries.
    4. Security Model: It defines the security mechanisms used to protect the directory information, such as authentication, access control, and encryption.

# LDAP Operations: LDAP supports various operations for accessing and modifying directory entries. Some of the commonly used LDAP operations are:-
    (a) For Authentication: It includes bind, unbind and abandon operations used to connect and disconnect to and from an LDAP server, establish access rights and protect information. In authentication, client session is established and ended using the functions

    -> BIND/UNBIND
    -> Abandon 

    (b) For Query: It includes search and compare operations used to retrieve information from a directory. In query, server performs action using function

    -> Search
    -> Compare Entry 

    (c) For Update: It includes add, delete, modify and modify RDN operations used to update stored information in a directory. In update, we can make changes in directories by using function
    -> Add an entry
    -> Delete an entry
    -> Modify an entry 