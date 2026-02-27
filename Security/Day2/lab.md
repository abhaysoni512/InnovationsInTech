1. Internet Protocol Datagram Header Format:
    Internet Protocol Version 4, Src: 8.8.8.8, Dst: 172.21.15.198
        0100 .... = Version: 4
        .... 0101 = Header Length: 20 bytes (5)
        Differentiated Services Field: 0x80 (DSCP: CS4, ECN: Not-ECT)
            1000 00.. = Differentiated Services Codepoint: Class Selector 4 (32)
            .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
        Total Length: 128
        Identification: 0x58ad (22701)
        000. .... = Flags: 0x0
            0... .... = Reserved bit: Not set
            .0.. .... = Don't fragment: Not set
            ..0. .... = More fragments: Not set
        ...0 0000 0000 0000 = Fragment Offset: 0
        Time to Live: 111
        Protocol: UDP (17)
        Header Checksum: 0x2655 [validation disabled]
        [Header checksum status: Unverified]
        Source Address: 8.8.8.8
        Destination Address: 172.21.15.198
        [Stream index: 0]

2. Static IP : 

A static IP is manually assigned (doesn't change), unlike DHCP (dynamic from router). Useful for servers, printers, or testing. You'll change your computer's IP temporarily — note originals to revert!

Linux:
Step-by-Step (Using ip Command – Temporary):

1. Check current: ip addr show (note interface, e.g., enp0s3).
2. Choose a Static IP

    Example: if current is 172.21.15.198/20 then static could be 172.21.15.200, just ensure it's in the same subnet.

    Note: In a real Linux server, you might edit a file (like /etc/netplan/ or /etc/network/interfaces) to make this permanent.

3. Assign IP : sudo ip addr add 172.21.15.200/20 dev eth0
4. Verify the Configuration
Run the show command again to see if the IP was assigned.

    ip addr show eth0
    You should now see two IP addresses listed under eth0:

    * Your original dynamic IP (DHCP).
    * Your new static IP.
Example Output:
    abhaysoni1121@2024PUNLTP07415:~$ sudo ip addr add 172.21.15.200/20 dev eth0
    [sudo] password for abhaysoni1121:
    abhaysoni1121@2024PUNLTP07415:~$ ip addr show eth0
    2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
        link/ether 00:15:5d:c2:52:c1 brd ff:ff:ff:ff:ff:ff
        inet 172.21.15.198/20 brd 172.21.15.255 scope global eth0
        valid_lft forever preferred_lft forever
        inet 172.21.15.200/20 scope global secondary eth0
        valid_lft forever preferred_lft forever
        inet6 fe80::215:5dff:fec2:52c1/64 scope link
        valid_lft forever preferred_lft forever

5. Clean up : sudo ip addr del 172.21.15.200/20 dev eth0    
    example Output:
    abhaysoni1121@2024PUNLTP07415:~$ ip addr show eth0
        2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
            link/ether 00:15:5d:c2:52:c1 brd ff:ff:ff:ff:ff:ff
            inet 172.21.15.198/20 brd 172.21.15.255 scope global eth0
            valid_lft forever preferred_lft forever
            inet6 fe80::215:5dff:fec2:52c1/64 scope link
            valid_lft forever preferred_lft forever

**************************

3. ss / netstat :

These commands show network connections, listening ports, and stats. netstat (older, Windows default), ss (modern, faster on Linux). Focus on TCP/UDP.

PS C:\Users\abhay.soni> netstat -an

Active Connections

  Proto  Local Address          Foreign Address        State
  TCP    0.0.0.0:135            0.0.0.0:0              LISTENING
  TCP    0.0.0.0:445            0.0.0.0:0              LISTENING
  TCP    0.0.0.0:623            0.0.0.0:0              LISTENING
  TCP    0.0.0.0:5040           0.0.0.0:0              LISTENING
  TCP    0.0.0.0:9527           0.0.0.0:0              LISTENING
  TCP    0.0.0.0:16992          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:49664          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:49665          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:49666          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:49667          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:49668          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:49669          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:49713          0.0.0.0:0              LISTENING
  TCP    127.0.0.1:22           0.0.0.0:0              LISTENING
  TCP    127.0.0.1:80           0.0.0.0:0              LISTENING
  TCP    127.0.0.1:443          0.0.0.0:0              LISTENING
  TCP    127.0.0.1:4502         0.0.0.0:0              LISTENING
  TCP    127.0.0.1:4767         0.0.0.0:0              LISTENING
  TCP    127.0.0.1:4767         127.0.0.1:57066        ESTABLISHED

  Look for: Local Address (your IP:port), Foreign Address (remote), State (ESTABLISHED, LISTENING, TIME_WAIT).

Linux:
1. $ ss -tuln

abhaysoni1121@2024PUNLTP07415:~$ ss -tuln

(The "Server" View)
This command is asking: "Which ports are open and waiting for new connections?"

-l (Listening): This is the key flag. It tells Linux to show only sockets that are waiting for a connection (Servers).

-n (Numeric): It shows raw numbers (e.g., 8080) instead of trying to guess names (e.g., http-alt).

What your output shows: You can see LISTEN in the state column.

Example: tcp LISTEN 0 4096 0.0.0.0:8080

This means your machine has a service (likely a web server or application) sitting on Port 8080 waiting for someone to connect to it.

Netid       State         Recv-Q        Send-Q                 Local Address:Port                  Peer Address:Port
udp         UNCONN        0             0                            0.0.0.0:39812                      0.0.0.0:*
udp         UNCONN        0             0                      127.0.0.53%lo:53                         0.0.0.0:*
udp         UNCONN        0             0                     10.255.255.254:53                         0.0.0.0:*
udp         UNCONN        0             0                          127.0.0.1:323                        0.0.0.0:*
udp         UNCONN        0             0                            0.0.0.0:5353                       0.0.0.0:*
udp         UNCONN        0             0                              [::1]:323                           [::]:*
udp         UNCONN        0             0                               [::]:42137                         [::]:*
udp         UNCONN        0             0                               [::]:5353                          [::]:*
tcp         LISTEN        0             4096                         0.0.0.0:8080                       0.0.0.0:*
tcp         LISTEN        0             4096                   127.0.0.53%lo:53                         0.0.0.0:*
tcp         LISTEN        0             4096                       127.0.0.1:33351                      0.0.0.0:*
tcp         LISTEN        0             1000                  10.255.255.254:53                         0.0.0.0:*
tcp         LISTEN        0             4096                         0.0.0.0:80                         0.0.0.0:*
tcp         LISTEN        0             511                        127.0.0.1:39045                      0.0.0.0:*
tcp         LISTEN        0             128                          0.0.0.0:22                         0.0.0.0:*
tcp         LISTEN        0             4096                         0.0.0.0:443                        0.0.0.0:*
tcp         LISTEN        0             4096                            [::]:8080                          [::]:*
tcp         LISTEN        0             128                             [::]:22                            [::]:*

2. ss -tup (The "Client" View)
This command is asking: "Who is my computer talking to right now?"

No -l flag: By default, if you don't use -l, ss only shows active/established connections.

-p (Process): This attempts to show the name of the program (Process ID) managing the connection.

No -n flag: It tries to translate port numbers to names (e.g., you see :https instead of :443).

What your output shows: You can see ESTAB (Established) in the state column.

Example: tcp ESTAB ... 140.82.112.22:https

This means your computer is currently downloading or uploading data to that IP address (which happens to belong to GitHub) over HTTPS.

Netid      State            Recv-Q        Send-Q                Local Address:Port                 Peer Address:Port
tcp        FIN-WAIT-1       0             1                     172.21.15.198:54122               140.82.112.22:https
tcp        ESTAB            0             0                         127.0.0.1:39045                   127.0.0.1:50368
tcp        LAST-ACK         0             25                    172.21.15.198:39070               140.82.112.21:https
tcp        ESTAB            0             0                     172.21.15.198:49528               20.250.119.64:https
tcp        LAST-ACK         0             25                    172.21.15.198:54538               140.82.112.22:https
tcp        LAST-ACK         0             25                    172.21.15.198:53574               140.82.113.22:https
tcp        ESTAB            0             0                         127.0.0.1:39045                   127.0.0.1:50362
tcp        LAST-ACK         0             25                    172.21.15.198:39390               140.82.113.22:https
tcp        LAST-ACK         0             25                    172.21.15.198:38740               140.82.113.22:https
tcp        ESTAB            0             0                         127.0.0.1:50362                   127.0.0.1:39045
tcp        ESTAB            0             0                     172.21.15.198:54112               140.82.114.22:https
tcp        ESTAB            0             0                     172.21.15.198:49514               20.250.119.64:https
tcp        ESTAB            0             0                     172.21.15.198:58054               140.82.113.21:https
tcp        ESTAB            0             0                         127.0.0.1:50368                   127.0.0.1:39045
tcp        ESTAB            0             0                     172.21.15.198:52552               20.199.39.224:https

ss -ta    # All TCP connections
abhaysoni1121@2024PUNLTP07415:~$ ss -ta
State           Recv-Q         Send-Q                   Local Address:Port                       Peer Address:Port
LISTEN          0              4096                           0.0.0.0:http-alt                        0.0.0.0:*
LISTEN          0              4096                     127.0.0.53%lo:domain                          0.0.0.0:*
LISTEN          0              4096                         127.0.0.1:33351                           0.0.0.0:*
LISTEN          0              1000                    10.255.255.254:domain                          0.0.0.0:*
LISTEN          0              4096                           0.0.0.0:http                            0.0.0.0:*
LISTEN          0              511                          127.0.0.1:39045                           0.0.0.0:*
LISTEN          0              128                            0.0.0.0:ssh                             0.0.0.0:*
LISTEN          0              4096                           0.0.0.0:https                           0.0.0.0:*
LAST-ACK        0              25                       172.21.15.198:42792                     140.82.114.22:https
ESTAB           0              0                            127.0.0.1:39045                         127.0.0.1:50368
ESTAB           0              0                        172.21.15.198:55666                      4.225.11.192:https
ESTAB           0              0                        172.21.15.198:43988                     20.250.119.64:https
ESTAB           0              0                            127.0.0.1:39045                         127.0.0.1:50362
ESTAB           0              0                            127.0.0.1:50362                         127.0.0.1:39045
LAST-ACK        0              25                       172.21.15.198:52590                     140.82.112.21:https
ESTAB           0              0                        172.21.15.198:55682                      4.225.11.192:https
LAST-ACK        0              25                       172.21.15.198:43020                     140.82.112.22:https
ESTAB           0              0                            127.0.0.1:50368                         127.0.0.1:39045
LISTEN          0              4096                              [::]:http-alt                           [::]:*
LISTEN          0              128                               [::]:ssh                                [::]:*

*******************************
4. TCP Tests (Generate Traffic):

This lab exercise (TCP Tests – Generate Traffic) is designed to help you actively create real TCP connections on your Linux machine so you can observe how TCP works in practice — especially the 3-way handshake, data transfer, ports, connection states, and session establishment.

To generate TCP traffic for testing, you can use tools like `telnet`, `netcat` (nc), or `iperf`. 

Why These Actions?
Each action triggers a TCP connection (3-way handshake + possible data), so you can see:

    SYN → SYN-ACK → ACK in Wireshark
    Source/destination ports
    Connection states (SYN_SENT, ESTABLISHED, etc.)
    Real ports like 443 (HTTPS), 80 (HTTP), 22 (SSH)

    1. Open Browser → Visit https://google.com (Easiest & Most Common)

        What happens: Your browser opens a TCP connection to Google's server on port 443 (HTTPS).
        TCP details:
        Local port: Random high port (e.g., 50000–60000)
        Remote port: 443
        3-way handshake happens instantly
        Then TLS handshake (on top of TCP) + HTTP/2 or HTTP/3 data


        How to observe:

        Open browser (Firefox/Chrome) → go to https://google.com
        While page loads, run in terminal:Bashss -tunap | grep 443
        # or
        ss -t | grep ESTABLISHED
        In Wireshark, filter by `tcp.port == 443` to see the handshake

2. On linux using telnet:

Telnet lets you manually create a TCP connection and type HTTP commands — great for seeing raw TCP + basic HTTP.

abhaysoni1121@2024PUNLTP07415:~$ telnet google.com 80
Trying 142.250.192.110...
Connected to google.com.
Escape character is '^]'.
GET / HTTP/1.1
Host: google.com
Connection: close

HTTP/1.1 301 Moved Permanently
Location: http://www.google.com/
Content-Type: text/html; charset=UTF-8
Content-Security-Policy-Report-Only: object-src 'none';base-uri 'self';script-src 'nonce-maHKNbNLMe181yGOd41hHg' 'strict-dynamic' 'report-sample' 'unsafe-eval' 'unsafe-inline' https: http:;report-uri https://csp.withgoogle.com/csp/gws/other-hp
Date: Thu, 15 Jan 2026 12:21:07 GMT
Expires: Sat, 14 Feb 2026 12:21:07 GMT
Cache-Control: public, max-age=2592000
Server: gws
Content-Length: 219
X-XSS-Protection: 0
X-Frame-Options: SAMEORIGIN
Connection: close

<HTML><HEAD><meta http-equiv="content-type" content="text/html;charset=utf-8">
<TITLE>301 Moved</TITLE></HEAD><BODY>
<H1>301 Moved</H1>
The document has moved
<A HREF="http://www.google.com/">here</A>.
</BODY></HTML>
Connection closed by foreign host.

**************************

5. Capture TCP Events in Wireshark (Hands-On Analysis)
Explanation:
Capture live TCP traffic to see headers, handshakes, etc.
Step-by-Step Guide:

Open Wireshark → Select interface → Start capture.
Apply filter: tcp (or tcp.port == 80 or tcp.port == 443 for web).
Perform TCP tests (above: open site, telnet, etc.).
Stop capture → Analyze:
Look for 3-way handshake: Filter tcp.flags.syn == 1 → See SYN, SYN-ACK, ACK.
Expand packets: TCP header (ports, seq/ack, flags), IP header (src/dst IP).
UDP contrast: Filter udp (e.g., DNS) – no handshake.

Bonus: Capture termination (FIN/ACK) by closing browser tab.