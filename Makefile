# File Makefile Inti Bahasa MandarinTahil
CXX = g++
CXXFLAGS = -I./include -Wno-deprecated-declarations
LIBS = -lssl -lcrypto -lpthread

# Ambil semua file .cpp di folder src secara otomatis
SRC = $(wildcard src/*.cpp)

semua:
	$(CXX) $(CXXFLAGS) $(SRC) -o chinesetahil-pro $(LIBS)
	@echo "------------------------------------------"
	@echo " ChineseTahil Core Berhasil Di-build! "
	@echo "------------------------------------------"

membersihkan:
	rm -f chinesetahil-pro
