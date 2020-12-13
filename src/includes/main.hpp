#include <boost/program_options.hpp>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <tclap/CmdLine.h>
using namespace std;

//#include "calculations.hpp"
//#include "variables.hpp"
//std::unique_ptr<Calculate> calc;
class ArgumentValues
{
    private:
        string valueArray[8];
        mpz_t pVal, qVal, nVal, phiVal, eVal, dVal, cVal, mVal;
    public:
        ArgumentValues(int argc, char** argv); // save arguments
        void parseArguments(int argc, char** argv); // retrieve values from CMD
        void convertArguments(string* valueArray, int arraySize); // convert values from string to mpz_t
};

