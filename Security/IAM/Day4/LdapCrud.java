import javax.naming.Context;
import javax.naming.NamingException;
import javax.naming.directory.*;
import java.util.Hashtable;

public class LdapCrud {
    private static final String LDAP_URL = "ldap://localhost:389";
    private static final String ADMIN_DN = "cn=admin,dc=example,dc=com";
    private static final String ADMIN_PASS = "admin";
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