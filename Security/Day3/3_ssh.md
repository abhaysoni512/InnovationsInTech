SSH is a software package that enables secure system administration and file transfers over insecure networks.

SSH (Secure Shell) is a cryptographic network protocol that provides a secure way to access and manage remote computers over an unsecured network, like the internet. It was developed as a replacement for insecure protocols like Telnet and FTP, which transmit data (including passwords) in plain text. SSH encrypts all communication, authenticates users, and supports features like secure file transfers (via SFTP/SCP) and port forwarding.

The protocol operates in a client-server model: the client (e.g., your local machine running ssh user@remotehost) initiates the connection, and the server (e.g., a remote Linux server) listens on TCP port 22 by default.

SSH Protocol Architecture :

SSH is structured in three main layers, each handling a specific aspect of the secure connection. These layers build on each other to establish and maintain the session:

* Transport Layer: Handles the initial connection, server authentication, key exchange, and encryption setup. It ensures confidentiality (encryption), integrity (message authentication), and server identity verification.
* User Authentication Layer: Once the transport layer secures the channel, this layer verifies the client's identity using methods like passwords, public-key cryptography, or multi-factor authentication.
* Connection Layer: Manages the actual session after authentication, multiplexing multiple logical channels (e.g., shell access, file transfer) over the single encrypted connection.

Typical uses of the SSH protocol
    The protocol is used in corporate networks for:
    * providing secure access for users and automated processes
    * interactive and automated file transfers
    * issuing remote commands
    * managing network infrastructure and other mission-critical system components.

![alt text](image-1.png)

How SSH Works: Step-by-Step Connection Process

1. TCP Handshake and Version Negotiation
    The client connects to the server via TCP (usually port 22). Both exchange protocol version strings (e.g., "SSH-2.0-OpenSSH_8.2") to ensure compatibility. The server sends its public host key (a unique identifier for the server, like an RSA or Ed25519 key pair). The client checks this against known hosts (stored in ~/.ssh/known_hosts on Linux/macOS) to prevent man-in-the-middle attacks. If it's a new server, you'll see a fingerprint prompt to verify it manually.

2. Key Exchange and Session Key Generation
        To encrypt the session without sending the key over the wire, both parties perform a key exchange algorithm (e.g., Diffie-Hellman or Curve25519).
        * They agree on public parameters: a large prime number p and a generator g.
        * Each generates a private value (a for client, b for server) and computes a public value (g^a mod p and g^b mod p).
        * These public values are exchanged.
        * Each then computes the shared secret: client does g^b mod p raised to a (equals g^(ab) mod p*), and server does the reverse.
        * This secret derives a symmetric session key (e.g., for AES-256 encryption) used for the rest of the session. No secret is transmitted—only math makes it possible for both to arrive at the same key
3. Algorithm Negotiation
    Client and server select matching algorithms for:
    Symmetric encryption (e.g., AES in GCM mode for confidentiality).
    Message Authentication Code (MAC, e.g., HMAC-SHA256) to detect tampering.
    Compression (optional, e.g., zlib).
    All further traffic is now encrypted with the session key.
4. Server Authentication
    Already partially done via the host key in step 1. The client confirms the server's identity matches the expected public key.

5. User Authentication
    The client proves its identity. Common methods:
    * Password: Client sends an encrypted password; server checks against its user database (e.g., /etc/shadow). Simple but vulnerable to brute-force.
    * Public-Key (Recommended):
        Client offers a public key from its ~/.ssh/id_rsa.pub (or similar).
        Server verifies it matches an entry in the user's ~/.ssh/authorized_keys file.
        Server sends a challenge: a random number encrypted with the public key.
        Client decrypts it using its private key (proving possession) and signs it with the session key.
        Server verifies the signature.
        This is asymmetric cryptography in action—secure and passwordless.


6. Session Establishment and Data Transfer
    Once authenticated, the connection layer opens channels for:
    Interactive shell (e.g., bash).
    Command execution (e.g., ssh user@host ls).
    Subsystems like SFTP for file transfers.