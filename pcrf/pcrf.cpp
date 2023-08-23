#include <iostream>
#include <unordered_map>
#include <vector>

struct Policy {
    std::string policyId;
    std::string qosProfile;
    double maxDataRate;
    double maxUplinkRate;
};

class PCRF {
private:
    std::unordered_map<std::string, Policy> policies;

public:
    void createPolicy(const std::string& policyId, const std::string& qosProfile, double maxDataRate, double maxUplinkRate) {
        Policy policy = {policyId, qosProfile, maxDataRate, maxUplinkRate};
        policies[policyId] = policy;
        std::cout << "Policy " << policyId << " created with QoS: " << qosProfile
                  << ", Max Data Rate: " << maxDataRate << " Mbps, Max Uplink Rate: " << maxUplinkRate << " Mbps" << std::endl;
    }

    void applyPolicy(const std::string& subscriberId, const std::string& policyId) {
        std::cout << "Applying policy " << policyId << " to subscriber " << subscriberId << std::endl;
        // Apply the policy to the subscriber's session
    }

    void listPolicies() {
        std::cout << "Policies:" << std::endl;
        for (const auto& pair : policies) {
            const Policy& policy = pair.second;
            std::cout << "Policy ID: " << policy.policyId << ", QoS Profile: " << policy.qosProfile
                      << ", Max Data Rate: " << policy.maxDataRate << " Mbps, Max Uplink Rate: " << policy.maxUplinkRate << " Mbps" << std::endl;
        }
    }
};

int main() {
    PCRF pcrf;

    pcrf.createPolicy("policy123", "Gold", 100.0, 50.0);
    pcrf.createPolicy("policy456", "Silver", 50.0, 30.0);

    pcrf.applyPolicy("subscriber789", "policy123");

    pcrf.listPolicies();

    return 0;
}

