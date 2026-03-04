#ifndef CHINESETAHIL_CHAINPARAMS_H
#define CHINESETAHIL_CHAINPARAMS_H
#include <string>
class CChainParams {
public:
    std::string strNetworkID;
    int nDefaultPort;
    void Initialize();
};
#endif
