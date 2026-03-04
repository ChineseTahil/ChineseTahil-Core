#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void CheckBalance() {
    std::ifstream db("blockchain.dat");
    std::string line;
    int blockCount = 0;
    
    // Scan file blockchain.dat buat nyari bukti kerja (Block Found)
    while (std::getline(db, line)) {
        if (line.find("0000") != std::string::npos) { // Mencari valid hash
            blockCount++;
        }
    }
    
    int reward = 50; 
    long totalBalance = (long)blockCount * reward;

    std::cout << "\n=== CHINESETAHIL NETWORK EXPLORER ===" << std::endl;
    std::cout << "Total Blocks Mined : " << blockCount << std::endl;
    std::cout << "Reward per Block   : " << reward << " CT" << std::endl;
    std::cout << "Your Total Wealth  : " << totalBalance << " CT" << std::endl;
    std::cout << "=====================================" << std::endl;
}
