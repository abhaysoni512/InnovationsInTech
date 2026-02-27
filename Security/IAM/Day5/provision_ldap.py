import psycopg2
from ldap3 import Server, Connection, ALL, MODIFY_REPLACE, SUBTREE
import os
import datetime
import logging
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

# Setup logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

# Environment variables for security (set these in your env or .env file)
DB_HOST = os.getenv('DB_HOST', 'localhost')
DB_NAME = os.getenv('DB_NAME', 'ldap_db')
DB_USER = os.getenv('DB_USER', 'abhay_user')
DB_PASS = os.getenv('DB_PASS', 'admin')
LDAP_HOST = os.getenv('LDAP_HOST', 'localhost')
LDAP_PORT = int(os.getenv('LDAP_PORT', 389))
LDAP_BIND_DN = os.getenv('LDAP_BIND_DN', 'cn=admin,dc=example,dc=com')
LDAP_BIND_PASS = os.getenv('LDAP_BIND_PASS', 'admin')
LDAP_BASE_DN = os.getenv('LDAP_BASE_DN', 'dc=example,dc=com')
LDAP_USER_OU = os.getenv('LDAP_USER_OU', 'ou=users,dc=example,dc=com')

# Track last sync (store in a file for persistence)
LAST_SYNC_FILE = 'last_sync.txt'

def get_last_sync():
    if os.path.exists(LAST_SYNC_FILE):
        with open(LAST_SYNC_FILE, 'r') as f:
            return datetime.datetime.fromisoformat(f.read().strip())
    return datetime.datetime.min

def update_last_sync():
    now = datetime.datetime.now()
    with open(LAST_SYNC_FILE, 'w') as f:
        f.write(now.isoformat())

def connect_db():
    return psycopg2.connect(host=DB_HOST, database=DB_NAME, user=DB_USER, password=DB_PASS)

def connect_ldap():
    server = Server(LDAP_HOST, port=LDAP_PORT, get_info=ALL)
    return Connection(server, user=LDAP_BIND_DN, password=LDAP_BIND_PASS, auto_bind=True)

def query_users(cur, last_sync):
    cur.execute("""
        SELECT id, username, email, full_name
        FROM users
        WHERE status = 'active' AND updated_at > %s
    """, (last_sync,))
    return cur.fetchall()

def user_exists_in_ldap(conn, username):
    search_filter = f'(uid={username})'
    conn.search(LDAP_USER_OU, search_filter, search_scope=SUBTREE, attributes=['uid'])
    return len(conn.entries) > 0

def create_ldap_user(conn, user):
    id, username, email, full_name = user
    dn = f'uid={username},{LDAP_USER_OU}'
    attributes = {
        'objectClass': ['inetOrgPerson', 'organizationalPerson', 'person', 'top'],
        'cn': full_name,
        'sn': full_name.split()[-1] if ' ' in full_name else full_name,
        'uid': username,
        'mail': email,
        'userPassword': '{SSHA}defaultpassword'  # Use a password generator or hash properly
    }
    if conn.add(dn, attributes=attributes):
        logging.info(f'Created user: {username}')
    else:
        logging.error(f'Failed to create {username}: {conn.result}')

def update_ldap_user(conn, user):
    id, username, email, full_name = user
    search_filter = f'(uid={username})'
    conn.search(LDAP_USER_OU, search_filter, search_scope=SUBTREE, attributes=['*'])
    if conn.entries:
        dn = conn.entries[0].entry_dn
        changes = {
            'mail': [(MODIFY_REPLACE, [email])],
            'cn': [(MODIFY_REPLACE, [full_name])],
            'sn': [(MODIFY_REPLACE, [full_name.split()[-1] if ' ' in full_name else full_name])]
        }
        if conn.modify(dn, changes):
            logging.info(f'Updated user: {username}')
        else:
            logging.error(f'Failed to update {username}: {conn.result}')
    else:
        logging.warning(f'User {username} not found for update')

def main():
    last_sync = get_last_sync()
    try:
        with connect_db() as db_conn:
            with db_conn.cursor() as cur:
                users = query_users(cur, last_sync)
        
        with connect_ldap() as ldap_conn:
            for user in users:
                username = user[1]
                if user_exists_in_ldap(ldap_conn, username):
                    update_ldap_user(ldap_conn, user)
                else:
                    create_ldap_user(ldap_conn, user)
        
        update_last_sync()
        logging.info('Provisioning complete.')
    except Exception as e:
        logging.error(f'Error during provisioning: {e}')

if __name__ == '__main__':
    main()