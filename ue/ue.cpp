#include <iostream>
#include <string>

class UserEquipment {
private:
    std::string ueId;

public:
    UserEquipment(const std::string& id) : ueId(id) {}

    void sendMessage(const std::string& message) {
        std::cout << "UE " << ueId << " sending message: " << message << std::endl;
    }

    void receiveMessage(const std::string& senderId, const std::string& message) {
        std::cout << "UE " << ueId << " received message from UE " << senderId << ": " << message << std::endl;
    }
};

int main() {
    UserEquipment ue1("UE1");
    UserEquipment ue2("UE2");

    ue1.sendMessage("Hello from UE1!");
    ue2.sendMessage("Hi from UE2!");

    ue1.receiveMessage("UE2", "Message received from UE2");
    ue2.receiveMessage("UE1", "Message received from UE1");

    return 0;
}

