#include <iostream>
#include <unordered_map>
#include <vector>

// Define a simple packet structure
struct Packet {
    std::string sourceIP;
    std::string destinationIP;
    std::string payload;
};

class UPF {
private:
    std::unordered_map<std::string, std::string> ueIPToSessionID;  // User Equipment (UE) IP to Session ID mapping
    std::unordered_map<std::string, std::vector<Packet>> sessionIDToPackets;  // Session ID to packets mapping

public:
    void handleIncomingPacket(const Packet& packet) {
        std::string sessionID = ueIPToSessionID[packet.sourceIP];

        if (sessionID.empty()) {
            std::cout << "Error: Session ID not found for source IP " << packet.sourceIP << std::endl;
            return;
        }

        sessionIDToPackets[sessionID].push_back(packet);
        std::cout << "Packet received and added to session " << sessionID << std::endl;
    }

    void createSession(const std::string& ueIP, const std::string& sessionID) {
        ueIPToSessionID[ueIP] = sessionID;
        sessionIDToPackets[sessionID] = {};
        std::cout << "Session created for UE " << ueIP << " with session ID " << sessionID << std::endl;
    }

    void transmitPackets(const std::string& sessionID) {
        if (sessionIDToPackets.find(sessionID) == sessionIDToPackets.end()) {
            std::cout << "Error: Session ID not found" << std::endl;
            return;
        }

        std::vector<Packet>& packets = sessionIDToPackets[sessionID];
        for (const Packet& packet : packets) {
            std::cout << "Transmitting packet from session " << sessionID << ": Source IP " << packet.sourceIP
                      << " Destination IP " << packet.destinationIP << " Payload " << packet.payload << std::endl;
        }

        packets.clear();  // Remove transmitted packets
    }
};

int main() {
    UPF upf;

    // Create sessions and handle incoming packets
    upf.createSession("10.0.0.1", "session123");
    upf.createSession("10.0.0.2", "session456");

    Packet packet1 = {"10.0.0.1", "10.0.0.2", "Hello, packet 1"};
    Packet packet2 = {"10.0.0.2", "10.0.0.1", "Hi there, packet 2"};

    upf.handleIncomingPacket(packet1);
    upf.handleIncomingPacket(packet2);

    // Transmit packets and clear session data
    upf.transmitPackets("session123");
    upf.transmitPackets("session456");

    return 0;
}

