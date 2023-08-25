#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Failed to connect." << std::endl;
        return 1;
    }

    std::cout << "Connection established with server." << std::endl;

    std::thread inputThread([&]() {
        char inputBuffer[256];
        while (true) {
            std::cin.getline(inputBuffer, sizeof(inputBuffer));
            if (std::strcmp(inputBuffer, "exit") == 0) {
                break;
            }
            send(clientSocket, inputBuffer, strlen(inputBuffer), 0);
        }
    });

    inputThread.join();

    close(clientSocket);
    return 0;
}

