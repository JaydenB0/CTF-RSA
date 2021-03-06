#pragma once
#include <bitset>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <string>

using namespace std;

class StateFlag 
{
    public:
        std::bitset<8> currentFlag { 0b00000000 };
        std::bitset<8> initialFlag {};
        bool checkModified();
        void resetInitial();
        StateFlag(string* valueArray);
};

/*class VarEngine {
    mpz_class intP, intQ, intN, intTotient, intE, intD, intC, intM;
    bitset<12> updated { 0b0000'0000'0001 };
    bitset<12> pSet { 0b0000'0000'0010 };
    bitset<12> qSet { 0b0000'0000'0100 };
    bitset<12> nSet { 0b0000'0000'1000 };
    bitset<12> phiSet { 0b0000'0001'0000 };
    bitset<12> mSet { 0b0000'0010'0000 };
    bitset<12> dSet { 0b0000'0100'0000 };
    bitset<12> eSet { 0b0000'1000'0000 };
    bitset<12> cSet { 0b0001'0000'0000 };
    bitset<12> origVals{};
    bitset<12> newVals{};
    public:
        bool checkModify();
        void requestInput();
        void initFlags();
};*/
