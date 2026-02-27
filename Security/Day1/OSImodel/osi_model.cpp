#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct LayerInfo {
    int number; // 7..1
    std::string name;
    std::string function;
    std::vector<std::string> examples;
};

struct PDU {
    std::string payload;
    std::vector<std::string> headers;  // outermost is at the back
    std::vector<std::string> trailers; // outermost is at the back

    std::string to_string() const {
        std::string out = payload;

        // Apply inner -> outer headers (headers[0] closest to payload)
        for (const auto& h : headers) {
            out = h + out;
        }

        // Apply trailers in the same inner -> outer order
        for (const auto& t : trailers) {
            out = out + t;
        }

        return out;
    }
};

static std::vector<LayerInfo> osi_layers() {
    return {
        {7,
         "Application",
         "Provides network services directly to end-user applications.",
         {"HTTP", "FTP", "SMTP", "DNS"}},
        {6,
         "Presentation",
         "Translates/formats data; handles encryption and compression.",
         {"TLS/SSL", "JPEG", "ASCII"}},
        {5,
         "Session",
         "Establishes, manages, and terminates sessions between applications.",
         {"RPC", "NetBIOS", "PPTP"}},
        {4,
         "Transport",
         "End-to-end delivery, reliability, flow control, segmentation.",
         {"TCP", "UDP"}},
        {3,
         "Network",
         "Logical addressing and routing/forwarding across networks.",
         {"IP", "ICMP", "OSPF"}},
        {2,
         "Data Link",
         "Node-to-node delivery on a local link; MAC addressing, error detection.",
         {"Ethernet", "PPP", "MAC"}},
        {1,
         "Physical",
         "Transmits raw bits over the physical medium; signaling and cabling.",
         {"Cables", "Hubs", "Fiber", "Wi-Fi (radio)"}},
    };
}

static std::string join_examples(const std::vector<std::string>& examples) {
    std::string out;
    for (size_t i = 0; i < examples.size(); ++i) {
        out += examples[i];
        if (i + 1 < examples.size()) out += ", ";
    }
    return out;
}

static void print_layers() {
    const auto layers = osi_layers();

    std::cout << "OSI Model (7 layers)\n";
    std::cout << "-------------------\n";

    for (const auto& layer : layers) {
        std::cout << layer.number << ". " << layer.name << "\n";
        std::cout << "   Function: " << layer.function << "\n";
        std::cout << "   Examples: " << join_examples(layer.examples) << "\n\n";
    }
}

static std::string normalize_ascii_upper(std::string s) {
    for (char& ch : s) {
        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    }
    return s;
}

static PDU encapsulate(std::string app_message, bool simulate_encryption) {
    PDU pdu;
    pdu.payload = std::move(app_message);

    // Layer 7: Application
    pdu.headers.push_back("[L7:APP|proto=SMTP]");

    // Layer 6: Presentation
    if (simulate_encryption) {
        // Toy "encryption": uppercase (for demonstration only)
        pdu.payload = normalize_ascii_upper(pdu.payload);
        pdu.headers.push_back("[L6:PRES|enc=ON]");
    } else {
        pdu.headers.push_back("[L6:PRES|enc=OFF]");
    }

    // Layer 5: Session
    pdu.headers.push_back("[L5:SESS|sid=42]");

    // Layer 4: Transport
    pdu.headers.push_back("[L4:TRAN|TCP|sport=50123|dport=25]");

    // Layer 3: Network
    pdu.headers.push_back("[L3:NET|IP|src=192.0.2.10|dst=203.0.113.20]");

    // Layer 2: Data Link
    pdu.headers.push_back("[L2:DL|ETH|src=AA:BB:CC:DD:EE:01|dst=AA:BB:CC:DD:EE:02]");
    pdu.trailers.push_back("[L2:DL|FCS]");

    // Layer 1: Physical
    pdu.headers.push_back("[L1:PHY|bits]");

    return pdu;
}

static void print_encapsulation_steps(const PDU& pdu) {
    std::cout << "Encapsulation (sender):\n";

    // Show the growth: start from payload and apply headers/trailers gradually.
    std::string current = pdu.payload;
    std::cout << "  Start (App data): " << current << "\n";

    for (size_t i = 0; i < pdu.headers.size(); ++i) {
        current = pdu.headers[i] + current;
        std::cout << "  + " << pdu.headers[i] << " -> " << current << "\n";

        // Apply trailer right after L2 header when we reach it.
        if (pdu.headers[i].rfind("[L2:DL", 0) == 0) {
            for (const auto& t : pdu.trailers) {
                current = current + t;
                std::cout << "  + " << t << " -> " << current << "\n";
            }
        }
    }

    std::cout << "\nOn the wire: " << pdu.to_string() << "\n\n";
}

static void decapsulate_and_print(PDU pdu, bool simulate_decryption) {
    std::cout << "Decapsulation (receiver):\n";

    // Remove L1..L7 headers in reverse order.
    std::string frame = pdu.to_string();
    std::cout << "  Received: " << frame << "\n";

    // Remove trailers first (L2)
    for (auto it = pdu.trailers.rbegin(); it != pdu.trailers.rend(); ++it) {
        const std::string& t = *it;
        if (frame.size() >= t.size() && frame.compare(frame.size() - t.size(), t.size(), t) == 0) {
            frame.erase(frame.size() - t.size());
            std::cout << "  - " << t << " (Data Link trailer) -> " << frame << "\n";
        }
    }

    for (auto it = pdu.headers.rbegin(); it != pdu.headers.rend(); ++it) {
        const std::string& h = *it;
        if (frame.rfind(h, 0) == 0) {
            frame.erase(0, h.size());
            std::cout << "  - " << h << " -> " << frame << "\n";
        }

        // After removing Presentation header, optionally "decrypt".
        if (h.rfind("[L6:PRES", 0) == 0 && simulate_decryption) {
            // Reverse of our toy "encryption" would be unknown; we keep it as-is.
            // Instead, demonstrate the *concept* by annotating.
            std::cout << "    (Presentation would decrypt/decompress here)\n";
        }
    }

    std::cout << "\nDelivered to application: " << frame << "\n";
}

static int menu() {
    std::cout << "\nChoose an option:\n";
    std::cout << "  1) Print OSI layers\n";
    std::cout << "  2) Simulate sending a message\n";
    std::cout << "  3) Exit\n";
    std::cout << "> ";

    int choice = 0;
    if (!(std::cin >> choice)) return 3;

    // Consume rest of line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

int main() {
    std::cout << "OSI Model Demo (C++)\n";

    while (true) {
        const int choice = menu();

        if (choice == 1) {
            print_layers();
            continue;
        }

        if (choice == 2) {
            std::string message;
            std::cout << "Enter an application message (e.g., email text):\n> ";
            std::getline(std::cin, message);

            char enc = 'n';
            std::cout << "Simulate presentation-layer encryption? (y/n): ";
            std::cin >> enc;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            const bool simulate_encryption = (enc == 'y' || enc == 'Y');
            PDU pdu = encapsulate(message, simulate_encryption);

            std::cout << "\n";
            print_encapsulation_steps(pdu);
            decapsulate_and_print(pdu, simulate_encryption);
            continue;
        }

        break;
    }

    std::cout << "Bye.\n";
    return 0;
}
