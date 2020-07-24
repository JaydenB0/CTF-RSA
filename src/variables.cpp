#include "includes/variables.hpp"
using namespace std;

bool VarEngine::checkModify() {
    if ((newVals & updated).any()) {
        origVals = newVals;
        origVals &= ~updated;
        return true;
    } else {
        return false;
    }
}

void VarEngine::requestInput() {
    cout << "Enter the known values. Enter 0 if the value is missing." << endl;
    for ( string variable : { "p", "q", "n", "totient", "e", "d", "c", "m" } ) {
        cout << "Input " << variable << ":" << endl;
        if (variable == "p") cin >> intP;
        if (variable == "q") cin >> intQ;
        if (variable == "n") cin >> intN;
        if (variable == "totient") cin >> intTotient;
        if (variable == "e") cin >> intE;
        if (variable == "d") cin >> intD;
        if (variable == "c") cin >> intC;
        if (variable == "m") cin >> intM;
    }
}

void VarEngine::initFlags() {
    if (!mpz_cmp_d(intP.get_mpz_t(), 0)) origVals |= pSet;
    if (!mpz_cmp_d(intQ.get_mpz_t(), 0)) origVals |= qSet;
    if (!mpz_cmp_d(intN.get_mpz_t(), 0)) origVals |= nSet;
    if (!mpz_cmp_d(intTotient.get_mpz_t(), 0)) origVals |= phiSet;
    if (!mpz_cmp_d(intM.get_mpz_t(), 0)) origVals |= mSet;
    if (!mpz_cmp_d(intD.get_mpz_t(), 0)) origVals |= dSet;
}