Introduction to the OSI Model:
The Open Systems Interconnection (OSI) model describes seven layers that computer systems use to communicate over a network.

Why we use the OSI Model:
Each layer of the OSI model interacts with the layer directly above and below it, encapsulating and transmitting data in a structured manner. This approach helps network professionals troubleshoot issues, as problems can be isolated to a specific layer

Note: The modern Internet is not based on OSI, but on the simpler TCP/IP model. However, the OSI 7-layer model is still widely used, as it helps visualize and communicate how networks operate.

OSI Model Layers:

7. Application Layer:
    - Function: This layer provides protocols and network services directly to end-user applications.Key functionalities of the Application Layer include resource sharing, remote file access, and network management.
    - Examples:  Hypertext Transfer Protocol (HTTP) for web browsing, File Transfer Protocol (FTP) for file transfers, Simple Mail Transfer Protocol (SMTP) for email services, and Domain Name System (DNS) for resolving domain names to IP addresses. 
6. Presentation Layer:
    - Function: Translates data between the application layer and the network format; handles data encryption.
    It ensures that data sent from the application layer of one system is readable by the application layer of another system. This layer handles data formatting, encryption, and compression, facilitating interoperability between different systems.
    - Examples: SSL/TLS, JPEG, ASCII
5. Session Layer:
    - Function: Manages sessions and is responsible for establishing, maintaining, and terminating connections between applications. Protocols operating at the Session Layer include Remote Procedure Call (RPC), which enables a program to execute a procedure on a remote host as if it were local, and the session establishment phase in protocols like NetBIOS and SQL.
    - Examples: NetBIOS, PPTP
4. Transport Layer:
    - Function: Provides reliable data transfer services to the upper layers; manages end-to-end communication. It ensures complete data transfer, error recovery, and flow control between hosts. TCP is connection-oriented and ensures reliable data transfer with error checking and flow control, making it suitable for applications like web browsing and email. UDP, on the other hand, is connectionless and does not guarantee delivery, making it faster and more efficient for applications like video streaming and online gaming where speed is prioritized over reliability.
    - Examples: TCP, UDP
3. Network Layer:
    - Function: The Network Layer is responsible for data routing, forwarding, and addressing. It determines the best physical path for data to reach its destination based on network conditions, the priority of service, and other factors. This layer manages logical addressing through IP addresses and handles packet forwarding. Key protocols at this layer include the Internet Protocol (IP), which is important for routing and addressing, Internet Control Message Protocol (ICMP) for diagnostic and error-reporting purposes, and routing protocols like Routing Information Protocol (RIP) that manage the routing of data across networks.
    - Examples: IP, ICMP, OSPF
2. Data Link Layer:
    - Function: Provides node-to-node data transfer; handles physical addressing and error detection.  It ensures that data is transmitted to the correct device on a local network segment. This layer manages MAC (Media Access Control) addresses and is divided into two sublayers: Logical Link Control (LLC) and Media Access Control (MAC). Protocols and technologies at this layer include Ethernet, which defines the rules for data transmission over local area networks (LANs), and Point-to-Point Protocol (PPP) for direct connections between two network nodes. 
    - Examples: Ethernet, PPP, MAC addresses
1. Physical Layer:
    - Function: Transmits raw bitstreams over a physical medium; defines hardware specifications. Functions of the Physical Layer include the modulation, bit synchronization, and transmission of raw binary data over the physical medium. Technologies such as Fiber Optics and Wi-Fi operate at this layer, ensuring that the data physically moves from one device to another in the network.
    - Examples: Cables, switches, hubs