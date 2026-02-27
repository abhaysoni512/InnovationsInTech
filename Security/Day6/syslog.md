Syslog Message Logging Protocol :-

Syslog is a standard protocol for message logging, originally developed in the 1980s as part of the Sendmail project. It allows devices, applications, and systems to generate, format, and transmit log messages to a central server or collector. The protocol is defined in RFC 3164 (BSD Syslog) and updated in RFC 5424 (Structured Syslog), which adds features like structured data and reliable delivery options. It uses UDP port 514 by default for communication, though TCP can be used for reliability.

Syslog protocol basically uses three layers :

* Syslog Content - Syslog content is the information of the payload in the system packet.
* Syslog Application - It analyzes and handles the generation, interpretation routing and storage of syslog messages.
* Syslog Transport - Syslog Transport is responsible for transporting the messages.

Functions in syslog are performed at 5 layers.
    * Originator - The originator is the local machine that generates the message.
    * Collector - The collector collects the syslog content for analysis. It is basically the syslog server.
    * Relay - A relay basically forwards messages from the originator or other relays to the collector or other relays.
    * Transport Sender - It transports the syslog messages to a transport protocol, most commonly UDP.
    * Transport Receiver - It receives the messages from the specified transport protocol.




**************************

Deep dive in working :-

Syslog is a system logging protocol that is a standard for message logging. It defines a common message format to allow systems to send messages to a logging server, whether it is set up locally or over the network. The logging server will then handle further processing or transport of the messages.

As long as the format of your messages is compliant with this protocol, you just have to pass them to a logging server (or, put differently, a logging daemon which we will talk about shortly) and forget about them.

The transport of the messages, rotation, processing, and enrichment will, from that point on, be handled by the logging server and the infrastructure it connects to. Your application does not have to know or deal with any of that. Thus we get a decoupled architecture (log handling is separated from the application).


Why is it important to have a common log format?
If your logs have a common format, it’s first of all easy to filter the records by a particular time window or by the respective log levels (also referred to as severity levels. For example: info, warning, error, and so on)
Secondly, you may have a lot of different applications that implement a logtransport themselves. In that case, you'd have to spend quite some time skimming through the docs, figuring out how to configure file logging, log rotation, or log forwarding for every application instead of just configuring it once in your syslog server and expecting all your applications to simply submit their logs to it.

Syslog daemons :-

One of the original older implementations of a syslog daemon for Linux was referred to simply as syslog (leading to much confusion) or sysklogd. Later, more modern and commonly used implementations such as rsyslog or syslog-ng emerged. These were also made for Linux specifically. Nowadays, most Linux distributions come with rsyslog as the default syslog daemon. Other popular syslog daemons include syslog-ng and journald (part of systemd).

Rsyslog, like many other syslog daemons, listens to a /dev/log unix socket by default. It forwards the incoming data to a /var/log/syslog file on Debian-based distributions or to /var/log/messages on RedHat-based systems


Syslog Message Format :-
A syslog message consists of a header and a message body. The header contains metadata about the message, while the body contains the actual log information.
The general format of a syslog message is as follows:
<PRI>HEADER MSG
Where:
* <PRI> - The priority value, which is a combination of facility and severity level.
* HEADER - Contains the timestamp, hostname, and other metadata.
* MSG - The actual log message content.
The PRI value is calculated using the formula:
PRI = (Facility * 8) + Severity
Where:
* Facility - Indicates the type of program or process that generated the message (e.g., kernel, user-level, mail system).
* Severity - Indicates the importance of the message (e.g., emergency, alert, critical, error, warning, notice, informational, debug).

There are two types of syslog formats: the original old BSD format which came from the early versions of BSD Unix systems and became a standard with RFC3164 specification, as well as a newer one from RFC5424.

RFC3164 format
    This format consists of the following 3 parts: PRI, HEADER (TIMESTAMP, HOSTNAME), MSG (TAG, CONTENT). Here is a more concrete example (taken directly from RFC3164, by the way):

    <34>Oct 11 22:14:15 mymachine su: 'su root' failed for lonvick on /dev/pts/8

    Let's see what's going on here:

    <34> (PRI) – priority of the log record which consists of the facility level multiplied by 8 plus the severity level. We will talk about facilities and severity levels soon, but in the example above we get: a facility number 4 (34 // 8 = 4) and a critical severity level (34 % 8 = 2).
    Oct 11 22:14:15 (TIMESTAMP) – timestamp in local time without the year and a millisecond or a timezone portion. It follows a format string “Mmm dd hh:mm:ss”
    mymachine (HOSTNAME) _ hostname, IPv4, or IPv6 address of the machine that the message originates from.
    su (TAG) – Name of the program or process that generated the message. Any non-alphanumeric character terminates the TAG field and is assumed to be a starting part of the next (CONTENT) field. In our case, it is a colon (“:”) character. But it could also have been just a space, or even square brackets with the PID (process id) inside, such as “[123]”.
    : 'su root' failed for lonvick on /dev/pts/8 (CONTENT) – An actual message of the log record.

RFC5424 format
    The newer RFC5424 format consists of the following parts: PRI, VERSION, TIMESTAMP, HOSTNAME, APP-NAME, PROCID, MSGID, STRUCTURED-DATA, MSG. Here is an example (taken directly from RFC5424):
    <34>1 2003-10-11T22:14:15.003Z mymachine.example.com su - ID47 - BOM'su root' failed for lonvick on /dev/pts/8

    <34> (PRI) – priority of the log record. Combination of severity and facility. Same as for RFC3164.
    1 (VERSION) – version of the syslog protocol specification. This number is supposed to be incremented for any future specification that makes changes to the HEADER part.
    2003-10-11T22:14:15.003Z (TIMESTAMP) – a timestamp with year, sub-second information, and timezone portions. It follows the ISO 8601 standard format as described in RFC3339 with some minor restrictions, like not using leap seconds, always requiring the “T” delimiter, and upper casing every character in the timestamp. NILVALUE (“-”) will be used if the syslog application cannot obtain system time (that is, it doesn’t have access to the time on the server).
    https://mymachine.example.com/ (HOSTNAME) – FQDN, hostname, or the IP address of the log originator. NILVALUE may also be used when the syslog application does not know the originating host name.
    su (APP-NAME) – device or application that produced the message. NILVALUE may be used when the syslog application is not aware of the application name of the log producer.
    - (PROCID) – implementation-dependent value often used to provide a process name or process ID of the application that generated the message. A NILVALUE should be used when this field is not provided.
    ID47 (MSGID) – field used to identify the type of message. Should contain NILVALUE when not used.
    - (STRUCTURED DATA) – provides sections with key-value pairs conveying additional metadata about the message. NILVALUE should be used when structured data is not provided. Examples: “[exampleSection@32473 iut="3" eventSource="Application" eventID="1011"][exampleSection2@32473 class="high"]”. In practice the STRUCTURED DATA part was rarely used and the metadata information was usually put into the MSG part that many applications structure as a JSON.
    BOM'su root' failed for lonvick on /dev/pts/8 (MSG) – actual message of the log record. The “BOM” at the beginning is an unprintable character which signifies that the rest of the payload is UTF8 encoded. If this character is not present, then other encodings like ASCII can be assumed by the syslog daemons.

    Finally, the new format supports UTF8 encoding and not just ASCII.

    When inspecting the log records in /var/log/messages or /var/log/syslog (depending on the system) you will probably see a different format from those described above. For rsyslog it looks like this:

        Feb 19 10:01:43 mymachine systemd[1]: systemd-hostnamed.service: Deactivated successfully.
    for Syslog-ng it looks like this:

        Feb 19 10:01:43 mymachine systemd: systemd-hostnamed.service: Deactivated successfully.
    Both of these formats are derived from the original RFC3164 format but have some differences. For example, the TAG field in rsyslog contains the process name along with the PID in square brackets, while in syslog-ng it only contains the process name.

Syslog Severity Levels :-
Syslog defines eight severity levels, ranging from 0 to 7, which indicate the importance of the log message. The levels are as follows:
* 0 - Emergency: System is unusable (keyword: emerg)
* 1 - Alert: Immediate action required (keyword: alert)
* 2 - Critical: Critical conditions (keyword: crit)
* 3 - Error: Error conditions (keyword: err)
* 4 - Warning: Warning conditions (keyword: warning)
* 5 - Notice: Normal but significant condition (keyword: notice)
* 6 - Informational: Informational messages (keyword: info)
* 7 - Debug: Debug-level messages (keyword: debug)

Syslog Facilities :- 
Syslog facilities represent the origin of a message. You can often use them for filtering and categorizing log records by the system that generated them. Syslog defines 24 standard facilities, ranging from 0 to 23. Some common facilities include:
* 0 - Kernel messages (kern)
* 1 - User-level messages (user)
* 2 - Mail system (mail)
* 3 - System daemons (daemon)
* 4 - Security/authorization messages (auth)
* 5 - Syslogd internal messages (syslog)
* 6 - Line printer subsystem (lpr)
* 7 - Network news subsystem (news)
* 8 - UUCP subsystem (uucp)
* 16-23 - Local use (local0 to local7)


***********************************************************************************

Hands on with syslog-ng :-


Install Syslog-ng:
    On Ubuntu/Debian: Run sudo apt update && sudo apt install syslog-ng.
    Verify: syslog-ng --version.

Basic Centralized Logging Setup:
    Edit /etc/syslog-ng/syslog-ng.conf on the server VM.
    Add a network source: source s_net { udp(ip(0.0.0.0) port(514)); }; (or TCP for reliability).
    Define a destination: destination d_central { file("/var/log/central.log"); };.
    Log path: log { source(s_net); destination(d_central); };.
    Restart: sudo systemctl restart syslog-ng


Client Configuration:
On the client VM, edit /etc/syslog-ng/syslog-ng.conf.
Add a destination: destination d_server { udp("server-ip" port(514)); };.
Log path: log { source(s_local); destination(d_server); };.
Restart syslog-ng.

Capture Apache Logs:
    Install Apache: sudo apt install apache2.
    Configure Apache to log to syslog: Edit /etc/apache2/apache2.conf and add ErrorLog "|/usr/bin/logger -t apache_error -p local3.err" and CustomLog "|/usr/bin/logger -t apache_access -p local3.info" combined.
    In syslog-ng.conf, add a filter/parser for Apache logs: Use apache-accesslog-parser() to parse fields like IP, timestamp, and request.
    Restart Apache: sudo systemctl restart apache2.
    Generate traffic: Access the server via browser or curl, then check /var/log/central.log on the server.

Testing and Advanced Practice:
    Use logger command: logger -p user.info "Test message".
    Add filtering: In syslog-ng.conf, use filter f_apache { program("apache"); }; to route specific logs.
    Scale up: Add more clients, integrate with tools like Elasticsearch for analysis, or simulate failures to test aggregation benefits.
    Monitor: Tail logs with tail -f /var/log/central.log.