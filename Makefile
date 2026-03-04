# ChineseTahil Core Makefile
CXX = g++
CXXFLAGS = -I./include -Wno-deprecated-declarations
LIBS = -lssl -lcrypto -lpthread

# List semua source file
SRC = src/main.cpp src/miner.cpp src/base58.cpp src/address_gen.cpp \
      src/explorer.cpp src/utxo.cpp src/transaction.cpp src/net.cpp \
      src/mempool.cpp src/chainparams.cpp src/wallet.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o chinesetahil-pro $(LIBS)
	@echo "------------------------------------------"
	@echo "   ChineseTahil Core Berhasil Di-build!   "
	@echo "      Gunakan: ./chinesetahil-pro         "
	@echo "------------------------------------------"

clean:
	rm -f chinesetahil-pro
