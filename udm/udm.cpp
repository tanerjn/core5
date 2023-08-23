#include <iostream>
#include <string>
#include <unordered_map>

class UDM {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> user_data;

public:
    bool createSubscriber(const std::string& subscriber_id, const std::unordered_map<std::string, std::string>& user_info) {
        if (user_data.find(subscriber_id) != user_data.end()) {
            std::cout << "Subscriber already exists" << std::endl;
            return false;
        }

        user_data[subscriber_id] = user_info;
        std::cout << "Subscriber created successfully" << std::endl;
        return true;
    }

    bool retrieveSubscriber(const std::string& subscriber_id, std::unordered_map<std::string, std::string>& user_info) {
        auto it = user_data.find(subscriber_id);
        if (it != user_data.end()) {
            user_info = it->second;
            return true;
        } else {
            std::cout << "Subscriber not found" << std::endl;
            return false;
        }
    }

    bool updateSubscriber(const std::string& subscriber_id, const std::unordered_map<std::string, std::string>& user_info) {
        auto it = user_data.find(subscriber_id);
        if (it != user_data.end()) {
            it->second = user_info;
            std::cout << "Subscriber updated successfully" << std::endl;
            return true;
        } else {
            std::cout << "Subscriber not found" << std::endl;
            return false;
        }
    }

    bool deleteSubscriber(const std::string& subscriber_id) {
        auto it = user_data.find(subscriber_id);
        if (it != user_data.end()) {
            user_data.erase(it);
            std::cout << "Subscriber deleted successfully" << std::endl;
            return true;
        } else {
            std::cout << "Subscriber not found" << std::endl;
            return false;
        }
    }
};

int main() {
    UDM udm;

    // Create subscribers
    udm.createSubscriber("12345", {{"name", "Alice"}, {"age", "28"}});
    udm.createSubscriber("67890", {{"name", "Bob"}, {"age", "32"}});

    // Retrieve and update subscriber
    std::unordered_map<std::string, std::string> subscriber_info;
    if (udm.retrieveSubscriber("12345", subscriber_info)) {
        std::cout << "Subscriber info: ";
        for (const auto& entry : subscriber_info) {
            std::cout << entry.first << ": " << entry.second << ", ";
        }
        std::cout << std::endl;

        udm.updateSubscriber("12345", {{"name", "Alice Smith"}, {"age", "29"}});
    }

    // Delete subscriber
    udm.deleteSubscriber("67890");

    return 0;
}

