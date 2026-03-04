#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void GetBalance(std::string myAddress) {
    std::ifstream db("blockchain.dat");
    std::string line;
    double totalBalance = 0;

    while (std::getline(db, line)) {
        // Logika sederhana: cari baris yang mengandung alamat lu
        // Format di blockchain.dat lu: block_height|hash|transaction_data
        if (line.find(myAddress) != std::string::npos) {
            // Misal setiap blok yang ada alamat lu dapet 50 CT (Coin Reward)
            totalBalance += 50.0;
        }
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "   WALLET BALANCE FOR: " << myAddress << std::endl;
    std::cout << "   TOTAL BALANCE     : " << totalBalance << " CT" << std::endl;
    std::cout << "==========================================" << std::endl;
    db.close();
}
