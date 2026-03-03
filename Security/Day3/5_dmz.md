Demilitarized Zones (DMZ) are used in cybersecurity. DMZs separate internal networks from the internet and are often found on corporate networks. A DMZ is typically created on a company’s internal network to isolate the company from external threats. The DMZ is a network barrier between the trusted and untrusted networks in a company’s private and public networks. The DMZ acts as a protection layer through which outside users cannot access the company’s data.

DMZ receives requests from outside users or public networks to access the information and website of a company. For such type of request, DMZ arranges sessions on the public network. It cannot initiate a session on the private network. If anyone tries to perform malicious activity on DMZ, the web pages are corrupted, but other information remains safe.

The goal of DMZ is to provide access to the untrusted network by ensuring the security of the private network.

DMZ Design and Architecture
The DMZ design and architecture involve several elements including the firewalls, routers, and servers. The key objective is to ensure that access to the internal network is tightly controlled while offering services to the outside world through servers in the DMZ.

* Single Firewall DMZ Architecture: In a single firewall setup the DMZ is configured as a separate network connected to the single firewall, which controls both the inbound and outbound traffic.
* Dual Firewall DMZ Architecture: This setup uses two firewalls one external and one internal for the more secure implementation. The external firewall filters traffic from the outside allowing limited access to the DMZ servers while the internal firewall restricts any unauthorized traffic from DMZ to the internal network.

Key Components of a DMZ Architecture:

1. External Network (Untrusted Zone):
    This is typically the internet or any public-facing connection.
    It represents the source of incoming traffic, including legitimate users and potential attackers.
    No direct access is allowed from here to the internal network; all traffic must pass through perimeter controls.
    Role: Acts as the entry point for external requests, but it's isolated to prevent unauthorized probing.

2. Perimeter Firewall (Outer or Front-End Firewall):

    A security device (hardware, software, or virtual) that sits between the external network and the DMZ.
    It filters incoming traffic based on rules, such as allowing only specific ports (e.g., HTTP on port 80, HTTPS on 443) while blocking others.
    Often includes features like Network Address Translation (NAT), intrusion detection/prevention systems (IDS/IPS), and stateful inspection.
    Role: Serves as the first line of defense, ensuring only authorized traffic reaches the DMZ servers.

3. DMZ Subnet (Demilitarized Zone):
    A segregated network segment where public-facing servers and services are hosted.
    Common servers here include:
        **Web servers (e.g., hosting websites or APIs).
        Email servers (e.g., SMTP for outbound mail).
        DNS servers (for domain resolution).
        Proxy servers or load balancers.
        FTP servers or other application-specific hosts.**

    These systems are "hardened" with minimal configurations to reduce vulnerabilities—no sensitive data is stored here.
    Role: Provides a neutral ground for external interactions. If compromised, the breach is contained within the DMZ, limiting damage.

4. Internal Firewall (Inner or Back-End Firewall):
    Positioned between the DMZ and the internal network.
    Enforces stricter rules than the perimeter firewall, often allowing only outbound traffic from the DMZ (e.g., database queries) and blocking inbound access from the DMZ to the internal zone.
    May include additional controls like VPN gateways or deep packet inspection.
    Role: Acts as the second line of defense, preventing any compromised DMZ resources from accessing the trusted internal network.

5. Internal Network (Trusted Zone):
    The organization's private LAN, housing sensitive assets like databases, employee workstations, file servers, and proprietary applications.
    Access is tightly controlled; no direct exposure to the external network.
    Role: Contains critical data and operations. The DMZ ensures that even if external threats breach the perimeter, they can't easily reach this zone.