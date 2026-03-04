// Copyright (c) 2010 Voxzy ZQ
// Copyright (c) 2009-present The ChineseTahil Core developers
#include "chainparams.h"
#include <iostream>
void CChainParams::Initialize() {
    strNetworkID = "main";
    nDefaultPort = 8333;
    std::cout << "--- ChineseTahil Core Initialized ---" << std::endl;
}
