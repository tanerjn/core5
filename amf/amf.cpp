#include <iostream>
#include <unordered_map>
#include <vector>

struct UEContext {
    std::string ueId;
    std::string imsi;
    std::string ipAddress;
    bool isConnected;
    // Other relevant UE context information
};

class AMF {
private:
    std::unordered_map<std::string, UEContext> ueContexts;

public:
    void registerUE(const std::string& ueId, const std::string& imsi) {
        UEContext ueContext = {ueId, imsi, "", true};
        ueContexts[ueId] = ueContext;
        std::cout << "UE " << ueId << " registered with IMSI " << imsi << std::endl;
    }

    void connectUE(const std::string& ueId, const std::string& ipAddress) {
        if (ueContexts.find(ueId) != ueContexts.end()) {
            ueContexts[ueId].ipAddress = ipAddress;
            std::cout << "UE " << ueId << " connected with IP address " << ipAddress << std::endl;
        } else {
            std::cout << "UE " << ueId << " not found for connection" << std::endl;
        }
    }

    void disconnectUE(const std::string& ueId) {
        if (ueContexts.find(ueId) != ueContexts.end()) {
            ueContexts[ueId].isConnected = false;
            std::cout << "UE " << ueId << " disconnected" << std::endl;
        } else {
            std::cout << "UE " << ueId << " not found for disconnection" << std::endl;
        }
    }

    void listConnectedUEs() {
        std::cout << "Connected UEs:" << std::endl;
        for (const auto& pair : ueContexts) {
            const UEContext& ueContext = pair.second;
            if (ueContext.isConnected) {
                std::cout << "UE ID: " << ueContext.ueId << ", IMSI: " << ueContext.imsi
                          << ", IP Address: " << ueContext.ipAddress << std::endl;
            }
        }
    }
};

int main() {
    AMF amf;

    amf.registerUE("UE123", "IMSI456");
    amf.registerUE("UE789", "IMSI012");

    amf.connectUE("UE123", "192.168.0.1");
    amf.connectUE("UE789", "192.168.0.2");

    amf.listConnectedUEs();

    amf.disconnectUE("UE123");
    amf.listConnectedUEs();

    return 0;
}

