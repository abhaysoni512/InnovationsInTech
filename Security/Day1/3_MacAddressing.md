A MAC address (Media Access Control address) is a unique hardware identifier assigned to a device’s network interface for communication on a local network.The media access control address is typically represented as twelve hexadecimal characters arranged in six pairs, separated by colons or hyphens. For example, a wireless MAC address might appear as 00:1A:2B:3C:4D:5E or 1A:2B:3C:4D:5E:6F. This format ensures that each MAC address identifies a specific network interface with near-universal uniqueness.

The structure of a media access control MAC address consists of two main components:

    Organizationally Unique Identifier (OUI): The first 24 bits identify the manufacturer of the network interface card
    Device Identifier: The remaining 24 bits provide a unique identifier within the manufacturer’s assigned range.

How MAC addresses work in networks?
    MAC addresses operate at the Data Link Layer (Layer 2) of the OSI model. When a device wants to communicate on a local network, it uses MAC addresses to identify both the source and destination devices. Here’s how the process works:
    1. Address Resolution Protocol (ARP): When a device wants to send data to another device on the same local network, it first checks its ARP cache to see if it already knows the MAC address corresponding to the destination IP address. If not, it sends an ARP request broadcast to all devices on the local network, asking "Who has this IP address?"
    2. ARP Reply: The device with the matching IP address responds with its MAC address, allowing the sender to update its ARP cache.
    3. Data Transmission: The sender then encapsulates the data into frames, including both the source and destination MAC addresses in the frame header. The frame is then transmitted over the local network.
    4. Frame Reception: The network interface of each device on the local network checks the destination MAC address in the incoming frames. If it matches its own MAC address, the device processes the frame; otherwise, it ignores it.

MAC Address Types:
    There are several types of MAC addresses, including:
    1. Unicast MAC address
        A unicast MAC address identifies a single, specific network device. This represents the most common type of MAC address, with each network interface receiving its own unique identifier. When a device sends a frame to a unicast MAC address, only the device with that specific address processes the frame.

        The Individual/Group (I/G) bit in the MAC address indicates whether an address is unicast or multicast. For unicast addresses, this bit is set to 0, signaling that the address targets a single device rather than a group.

    2. Multicast MAC address
        Multicast MAC addresses enable efficient communication with groups of devices simultaneously. Instead of sending separate frames to each device, a sender can use a multicast MAC address to deliver data to all devices configured to receive that particular multicast stream.

        The multicast address format uses the I/G bit set to 1, indicating group communication. Network protocols like IPv6 neighbor discovery and various routing protocols rely on multicast MAC addresses for their operation. These group addresses enable protocols to communicate with multiple devices without flooding the entire network.

    3. Broadcast MAC address
        The broadcast MAC address (FF:FF:FF:FF:FF:FF) represents a special case where all devices on the local network segment receive and process the frame. Broadcast addresses prove essential for network discovery protocols, DHCP requests, and other scenarios where a device needs to communicate with all reachable devices.

        Network switches typically flood broadcast frames to all ports except the originating port, ensuring network-wide delivery. However, routers do not forward broadcast frames between different network segments, limiting broadcast traffic to the local area network.

    Note: When a device sends data across network boundaries, routers use IP addresses for path determination while switches within each network segment use MAC addresses for local delivery. This complementary relationship ensures efficient data transmission from source to destination across complex network topologies.

    MAC address randomization:o protect privacy, modern operating systems have introduced MAC address randomization — also called private Wi-Fi addresses:

        iOS & iPadOS: Enable random MAC addresses by default on new Wi-Fi connections.
        Android: Randomization is default on newer versions and can be toggled per network.
        Windows 10/11: Offers random hardware addresses as a privacy option for wireless connections.

    Windows:
        Press the Windows key and type Command Prompt, then press Enter.
        In the Command Prompt window, type ipconfig /all and press Enter.
        Scroll through the results to find your active network adapter.
        Look for the "Physical Address" entry; this is your MAC address. Alternatively:
        Click the Start menu and select Settings.
        Navigate to Network & Internet > Status.
        Click on View hardware and connection properties.
        Find the MAC address listed under your active network connection.
    Linux:
        Open a terminal window.
        Type ifconfig or ip link and press Enter.
        Locate your network interface (e.g., eth0, wlan0).
        Find the MAC address listed as "ether" or "HWaddr".