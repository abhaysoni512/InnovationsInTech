A firewall is a network security system, available as hardware or software, that monitors and controls incoming and outgoing traffic based on predefined rules. It acts like a security guard, filtering data packets to either:

    Accept: Allow the traffic.
    Reject: Block with an error response.
    Drop: Block silently without response.

Importance of Firewalls
A firewall is the first line of defense in cybersecurity, acting as a security barrier between internal systems and external networks. It forces all traffic through a single checkpoint, where data packets are monitored, filtered, and either allowed or blocked based on predefined rules. Firewalls are essential because they:
    Prevent unauthorized access to private networks.
    Block malicious traffic, such as viruses and hackers.
    Control access to specific websites or services.
    Monitor network activity for suspicious behavior.

Working of Firewall
A firewall inspects all incoming and outgoing traffic and decide whether to allow or block it.

    All data packets entering or leaving the network must first pass through the firewall.
    The firewall examines each packet against predefined security rules set by the organization.
    If the packet matches safe rules, it is allowed; if it is suspicious, blacklisted, or contains malicious content, it is blocked.
    Blocked or unusual traffic is recorded in logs, and real-time alerts may be generated for serious threats.
    Since it is not possible to define every rule, the firewall applies a default policy (accept, reject, or drop). Setting the default policy to drop or reject is considered best practice to prevent unauthorized access.


Types of Firewall
    Firewalls can be categorized based on their generation.
    1) Network Placement
        Packet Filtering Firewall
        Stateful Inspection Firewall
        Proxy Firewall (Application Level)
        Circuit-Level Gateway
        Web Application Firewall (WAF)
        Next-Generation Firewall (NGFW)
    2) Systems Protected
        Network Firewall
        Host-Based Firewall
    3) Data Filtering Method
        Perimeter Firewall
        Internal Firewall
        Distributed Firewall
    4) Form Factors
        Hardware Firewall
        Software Firewall
Types of firewalls in Depth : 

Packet filtering firewall
    These firewalls scrutinize each packet of data that passes through them, and then filters them based on parameters like source and destination IP addresses, port numbers, and protocol types. While these firewalls are relatively simple and cost-effective, they are unable to examine the contents of packets, which makes them less effective against sophisticated attacks.

Proxy firewall
    A proxy firewall is an early type of firewall device, serving as the gateway from one network to another for a specific application. Proxy servers can provide additional functionality, such as content caching and security, by preventing direct connections from outside the network. However, this also may impact throughput capabilities and the applications they can support.

Stateful inspection firewall
    Now considered a traditional firewall, a stateful inspection firewall allows or blocks traffic based on state, port, and protocol. It monitors all activity from the opening of a connection until it is closed. Filtering decisions are made based on both administrator-defined rules as well as context, which refers to using information from previous connections and packets belonging to the same connection.


Web application firewall (WAF)
    Web application firewalls act as intermediaries for internal and external networks, handling all communication requests on behalf of the internal network. They offer a high level of security, as they can inspect the content of packets and filter out malicious or unauthorized data. However, their reliance on proxy servers can introduce latency and impact network performance.