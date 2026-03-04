#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "hash.h"

void ContinuousMiner(int difficulty, std::string minerAddress) {
    std::string target(difficulty, '0');
    int blockHeight = 0;

    std::cout << "[MINER] Worker started for address: " << minerAddress << std::endl;

    while (true) {
        int nonce = 0;
        auto start = std::chrono::steady_clock::now();
        
        while (true) {
            std::string data = std::to_string(blockHeight) + std::to_string(nonce) + minerAddress;
            std::string hash = CHash256::Compute(data);

            if (hash.substr(0, difficulty) == target) {
                std::cout << "\n>>> BLOCK FOUND! Height: " << blockHeight << std::endl;
                std::cout << ">>> Hash: " << hash << std::endl;

                std::ofstream db("blockchain.dat", std::ios::app);
                db << blockHeight << "|" << hash << "|" << minerAddress << "\n";
                db.close();

                blockHeight++;
                break; // Lanjut ke blok berikutnya
            }
            nonce++;
            if (nonce % 100000 == 0) std::cout << "." << std::flush;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Jeda dikit biar CPU gak meledak
    }
}
