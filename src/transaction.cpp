#include <iostream>
#include <fstream>
#include <string>

long GetValidatedBalance(std::string address);

void SendCoin(std::string from, std::string to, int amount) {
    long currentBalance = GetValidatedBalance(from);

    std::cout << "\n[TX_ENGINE] Validating transaction..." << std::endl;
    std::cout << "[TX_ENGINE] Sender Balance: " << currentBalance << " CT" << std::endl;

    if (currentBalance < amount) {
        std::cout << "[ERROR] Transaction REJECTED: Insufficient Funds!" << std::endl;
    } else {
        std::ofstream txFile("transactions.dat", std::ios::app);
        txFile << from << " -> " << to << " : " << amount << " CT\n";
        txFile.close();
        std::cout << "[SUCCESS] Transaction BROADCASTED to Mempool!" << std::endl;
    }
}
