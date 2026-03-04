#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Fungsi untuk hitung saldo asli dari history transaksi
long GetValidatedBalance(std::string address) {
    std::ifstream db("blockchain.dat");
    std::string line;
    long balance = 0;
    
    while (std::getline(db, line)) {
        // Logika: Jika ada blok yang dimining oleh address ini, tambah 50 CT
        if (line.find(address) != std::string::npos) {
            balance += 50;
        }
        // Nanti di sini kita tambah logika (-) jika address ini ngirim koin
    }
    return balance;
}
