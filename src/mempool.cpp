#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> mempool;

void AddToMempool(std::string tx) {
    mempool.push_back(tx);
    std::cout << "[MEMPOOL] New Transaction Added. Total Queue: " << mempool.size() << std::endl;
}

void ShowMempool() {
    std::cout << "\n--- CURRENT MEMPOOL ---" << std::endl;
    for (const auto& tx : mempool) {
        std::cout << "TX: " << tx << std::endl;
    }
    if (mempool.empty()) std::cout << "(Empty)" << std::endl;
}
