#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <cstring>

void StartNode(int port) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) return;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) return;
    if (listen(server_fd, 3) < 0) return;

    std::cout << "\n[P2P] ChineseTahil Node LIVE on Port " << port << std::endl;

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) continue;
        
        // --- LOGIKA HANDSHAKE BARU ---
        std::cout << "[P2P] Peer Connected! Sending Handshake..." << std::endl;
        
        // Kirim pesan perkenalan ke peer yang baru konek
        const char* msg = "VERSION: ChineseTahil-v1.0 | STATUS: ACTIVE\n";
        send(new_socket, msg, strlen(msg), 0);
        
        close(new_socket);
    }
}
