# Configure an OpenLDAP Instance

## Configuration involves setting up the directory structure, adding schemas, and basic entries.

Edit Configuration (if not using Docker):
OpenLDAP uses LDIF files for changes. Create a file add_content.ldif:

dn: ou=people,dc=example,dc=com
objectClass: organizationalUnit
ou: people

dn: ou=groups,dc=example,dc=com
objectClass: organizationalUnit
ou: groups

cmd : ldapadd -x -D cn=admin,dc=example,dc=com -W -f add_content.ldif


## Enable Logging (Optional):
Create enable_logging.ldif:

dn: cn=config
changetype: modify
replace: olcLogLevel
olcLogLevel: stats

Apply:

ldapmodify -Y EXTERNAL -H ldapi:/// -f enable_logging.ldif


# Use an LDAP Browser to Connect and Perform CRUD


Use Apache Directory Studio (free, cross-platform LDAP browser).

Install Apache Directory Studio:
Download from https://directory.apache.org/studio/ and install/run it.
Connect to LDAP:
Open Studio.
Go to LDAP > New Connection.
Hostname: localhost (or container IP if Docker).
Port: 389.
Encryption: None (for now).
Bind DN: cn=admin,dc=example,dc=com
Bind Password: adminpass
Test connection.

Perform CRUD Operations:
Create (Add Entry):
Right-click on ou=people,dc=example,dc=com > New > New Entry.
Object classes: inetOrgPerson
DN: cn=John Doe,ou=people,dc=example,dc=com
Attributes: sn=Doe, givenName=John, userPassword=pass123 (use SSHA for security).
Finish.

Read (Search):
Go to Search tab.
Base DN: dc=example,dc=com
Filter: (objectClass=inetOrgPerson)
Search. It shows entries like John Doe.

Update (Modify):
Right-click entry > Edit Entry.
Change an attribute (e.g., add mail=john@example.com).
Save.
Delete:
Right-click entry > Delete Entry.


Explore the browser's UI—it's intuitive for visualizing the directory tree.


# Write Java Code to Perform CRUD Operations
Use Java's JNDI (Java Naming and Directory Interface) for LDAP ops. You'll need JDK 8+.

1. Setup Project:
2. Create a Maven project or simple Java file. No extra dependencies needed for basic JNDI.
Sample Java Code (LdapCrud.java)

```java

import javax.naming.Context;
import javax.naming.NamingException;
import javax.naming.directory.*;
import java.util.Hashtable;

public class LdapCrud {
    private static final String LDAP_URL = "ldap://localhost:389";
    private static final String ADMIN_DN = "cn=admin,dc=example,dc=com";
    private static final String ADMIN_PASS = "adminpass";
    private static final String BASE_DN = "dc=example,dc=com";

    public static void main(String[] args) {
        DirContext ctx = getContext();

        // Create
        try {
            BasicAttributes attrs = new BasicAttributes();
            attrs.put("objectClass", "inetOrgPerson");
            attrs.put("cn", "Jane Doe");
            attrs.put("sn", "Doe");
            attrs.put("userPassword", "pass456");
            ctx.createSubcontext("cn=Jane Doe,ou=people," + BASE_DN, attrs);
            System.out.println("Created Jane Doe");
        } catch (NamingException e) { e.printStackTrace(); }

        // Read
        try {
            Attributes attrs = ctx.getAttributes("cn=Jane Doe,ou=people," + BASE_DN);
            System.out.println("Read: " + attrs.get("sn").get());
        } catch (NamingException e) { e.printStackTrace(); }

        // Update
        try {
            ModificationItem[] mods = new ModificationItem[1];
            mods[0] = new ModificationItem(DirContext.ADD_ATTRIBUTE,
                    new BasicAttribute("mail", "jane@example.com"));
            ctx.modifyAttributes("cn=Jane Doe,ou=people," + BASE_DN, mods);
            System.out.println("Updated email");
        } catch (NamingException e) { e.printStackTrace(); }

        // Delete
        try {
            ctx.destroySubcontext("cn=Jane Doe,ou=people," + BASE_DN);
            System.out.println("Deleted Jane Doe");
        } catch (NamingException e) { e.printStackTrace(); }

        try { ctx.close(); } catch (NamingException e) { e.printStackTrace(); }
    }

    private static DirContext getContext() {
        Hashtable<String, String> env = new Hashtable<>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, LDAP_URL);
        env.put(Context.SECURITY_AUTHENTICATION, "simple");
        env.put(Context.SECURITY_PRINCIPAL, ADMIN_DN);
        env.put(Context.SECURITY_CREDENTIALS, ADMIN_PASS);
        try {
            return new InitialDirContext(env);
        } catch (NamingException e) {
            throw new RuntimeException(e);
        }
    }
}
```

Compile and run: javac LdapCrud.java && java LdapCrud.
This performs CRUD on a user entry. Handle exceptions properly in production.

# Create a Custom ObjectClass and Use It in CRUD

ObjectClasses define entry structures. We'll create a custom one called myPerson extending inetOrgPerson.

1. Define Schema in LDIF (custom_schema.ldif) :-

dn: cn=mySchema,cn=schema,cn=config
objectClass: olcSchemaConfig
cn: mySchema

olcAttributeTypes: ( 1.3.6.1.4.1.12345.1.1 NAME 'myCustomAttr' DESC 'Custom attribute' SYNTAX 1.3.6.1.4.1.1466.115.121.1.15 SINGLE-VALUE )

olcObjectClasses: ( 1.3.6.1.4.1.12345.2.1 NAME 'myPerson' DESC 'Custom person' SUP inetOrgPerson STRUCTURAL MUST ( myCustomAttr ) )