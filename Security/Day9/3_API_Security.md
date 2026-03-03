Security threats in REST APIs can lead to data breaches, unauthorized access, service disruptions, and financial losses. Common methods :  injection attacks, broken authentication, XSS/CSRF, and the role of rate limiting in preventing DDoS—along with API-specific issues like exposed sensitive data and improper error handling. These threats often overlap with broader web vulnerabilities but manifest uniquely in APIs due to their stateless nature, reliance on HTTP methods, and exposure of endpoints.

# Injection Attacks
Injection attacks occur when untrusted data is inserted into a command or query, tricking the system into executing unintended actions. In REST APIs, this often targets backend databases, OS commands, or other interpreters.

How It Works: Attackers send malicious input via API parameters, bodies, or headers. For example, in a SQL injection, a POST request to /users/search with a body like {"query": "name' OR '1'='1 --"} could bypass filters and dump the entire user table if the server concatenates the input directly into a SQL query (e.g., SELECT * FROM users WHERE name = 'name' OR '1'='1 --').
Types Relevant to APIs:
    SQL/NoSQL Injection: Common in data retrieval endpoints.
    Command Injection: If an API executes shell commands based on input (e.g., /system/ping?host=example.com; rm -rf /). 

# Broken Authentication
    Broken authentication refers to flaws in verifying user identity, allowing attackers to impersonate legitimate users.

    How It Works: Weaknesses include predictable session tokens, missing multi-factor authentication (MFA), or credential stuffing. In APIs, this might involve guessing API keys or exploiting token reuse. For instance, if an API uses basic auth without rate limits, attackers can brute-force credentials via repeated POST /login requests.

    Common Scenarios:
        Weak Password Policies: Allowing simple passwords like "123456".
        Token Issues: Reusing expired JWTs or not invalidating sessions on logout.
        Credential Exposure: Logging credentials in errors or transmitting over HTTP.

# Cross-Site Scripting (XSS) and Cross-Site Request Forgery (CSRF)
    These are client-side attacks but can affect APIs indirectly, especially in web-integrated systems.

    # XSS:
        How It Works: Malicious scripts are injected into API responses and executed in the user's browser. In APIs, this happens if responses include unsanitized user input (e.g., a GET /comments returns JSON with script tags that a frontend renders).
        Types: Reflected (immediate), Stored (persistent), DOM-based (client-side manipulation).
        Exploitability and Impacts: High if APIs return HTML/JS; steals cookies, sessions, or keystrokes. APIs amplify this via CORS misconfigurations, allowing cross-origin script injection.
        API-Specific Angle: Pure REST APIs (JSON-only) are less prone, but hybrid APIs can leak via improper content types.

    # CSRF:
       How It Works: Attackers trick users into making unintended requests via forged links/forms. In APIs, this exploits state-changing methods (POST/PUT) if no anti-CSRF tokens are used.
        Exploitability and Impacts: Medium; requires social engineering. Impacts include unauthorized actions like fund transfers.
        API-Specific Angle: APIs using cookie-based auth are vulnerable without custom headers or tokens. Mitigated by CORS, but misconfigs expose it.

# Rate Limiting to Prevent DDoS (Distributed Denial of Service)

    DDoS involves overwhelming a system with traffic; lack of rate limiting makes APIs easy targets.

    How It Works: Without limits, attackers flood endpoints (e.g., 1,000 GET /search per second), exhausting CPU/memory/bandwidth. APIs are prime targets due to public exposure.
    Exploitability and Impacts: High with botnets; causes outages, high costs. APIs suffer from "slow DDoS" via resource-intensive queries


--------------------------------------------------

Best Practices for Secure APIs

1. Authentication: API Keys, OAuth 2.0, JWT
API Keys:
    Authentication verifies "who you are." Choose based on use case (machine vs. user).
    How It Works: Simple strings passed in headers (e.g., X-API-Key: abc123). Server validates against a database.
    Pros/Cons: Easy but insecure if leaked; rotate regularly.
    Implementation: Generate unique keys per client; use with HTTPS.
    Example: Public APIs like Stripe use keys for auth.
OAuth 2.0:
        How It Works: Token-based framework for delegated access. Involves authorization server, client, resource owner. Flows: Authorization Code (web apps), Client Credentials (machine-to-machine).
        Pros/Cons: Secure for third-party access; complex setup.
        Implementation: Use libraries like Spring Security; scopes limit access (e.g., "read:users").
        : GitHub API uses OAuth for apps, with tokens requiring specific permissions
JWT (JSON Web Tokens):
    How It Works: Compact, signed tokens (header.payload.signature) encoding claims. Signed with HMAC/RSA; validated server-side.
    Pros/Cons: Stateless; vulnerable to theft if not encrypted.
    Implementation: Include expiration (exp), issuer (iss); use libraries like jsonwebtoken.
    Example: Bearer tokens in headers: Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...

Authorization: Role-Based Access Control (RBAC)
    Authorization checks "what you can do" after auth.

    How It Works: Assign roles (e.g., admin, user) with permissions. Enforce at endpoint level (e.g., admins only for DELETE /users).
    Implementation: Use middleware to check roles against ACLs; integrate with JWT claims (e.g., {"role": "admin"}).
    : Addresses API1:2023 - Broken Object Level Authorization and API5:2023 - Broken Function Level Authorization.
    : In GitHub, fine-grained PATs require explicit permissions per endpoint.

---------------------------------------------------------------

# 