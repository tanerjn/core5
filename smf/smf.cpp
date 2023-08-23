#include <iostream>
#include <unordered_map>
#include <vector>

struct Session {
    std::string sessionId;
    std::string ueId;
    std::vector<std::string> dataFlows;
};

class SMF {
private:
    std::unordered_map<std::string, Session> sessions;

public:
    void createSession(const std::string& sessionId, const std::string& ueId) {
        Session session = {sessionId, ueId, {}};
        sessions[sessionId] = session;
        std::cout << "Session " << sessionId << " created for UE " << ueId << std::endl;
    }

    void addDataFlowToSession(const std::string& sessionId, const std::string& dataFlowId) {
        if (sessions.find(sessionId) != sessions.end()) {
            sessions[sessionId].dataFlows.push_back(dataFlowId);
            std::cout << "Data flow " << dataFlowId << " added to session " << sessionId << std::endl;
        } else {
            std::cout << "Session " << sessionId << " not found for adding data flow" << std::endl;
        }
    }

    void listSessions() {
        std::cout << "Sessions:" << std::endl;
        for (const auto& pair : sessions) {
            const Session& session = pair.second;
            std::cout << "Session ID: " << session.sessionId << ", UE ID: " << session.ueId << std::endl;
            std::cout << "Data Flows: ";
            for (const std::string& dataFlow : session.dataFlows) {
                std::cout << dataFlow << ", ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SMF smf;

    smf.createSession("session123", "UE456");
    smf.createSession("session789", "UE012");

    smf.addDataFlowToSession("session123", "dataFlowA");
    smf.addDataFlowToSession("session123", "dataFlowB");
    smf.addDataFlowToSession("session789", "dataFlowC");

    smf.listSessions();

    return 0;
}

