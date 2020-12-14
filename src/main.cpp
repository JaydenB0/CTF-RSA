#include "includes/main.hpp"
#include "flagFunctions.cpp"
#include <iostream>
#include <tclap/CmdLine.h>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) 
{
  condition_variable cv;
  mutex cv_m;
  //atomic<int> NbActiveThreads=2;

  ArgumentValues values(argc, argv);
  StateFlag flag(values.valueArray);
  //std::thread t1(waits,1,20), t2(engine);
}

void ArgumentValues::parseArguments(int argc, char** argv)
{
  try
  {
    TCLAP::CmdLine cmd("Calculates missing RSA values", ' ', "2.0");
    TCLAP::ValueArg<std::string>
            pArg("p","p","P Value",false,"0","int", cmd), 
            qArg("q","q","Q Value",false,"0","int", cmd), 
            nArg("n","n","N Value",false,"0","int", cmd),
            phiArg("t","totient","Totient Value",false,"0","int", cmd),
            eArg("e","exponent","Exponent Value",false,"0","int", cmd),
            dArg("d","d","D Value",false,"0","int", cmd),
            cArg("c","cipher","Ciphertext",false,"0","int", cmd),
            mArg("m","plaintext","Plaintext message",false,"0","int", cmd);
    cmd.parse(argc, argv);

    valueArray[0] = pArg.getValue();
    valueArray[1] = qArg.getValue();
    valueArray[2] = nArg.getValue();
    valueArray[3] = phiArg.getValue();
    valueArray[4] = eArg.getValue();
    valueArray[5] = dArg.getValue();
    valueArray[6] = cArg.getValue();
    valueArray[7] = mArg.getValue();
  } 
  catch (TCLAP::ArgException &e)
  {
    std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
  }
}

void ArgumentValues::convertArguments(string* valueArray, int arraySize)
{
  char* charArray;
  for(int i=0; i< arraySize; i++)
  {
    string currentStr = valueArray[i];
    charArray = &currentStr[0];
    switch(i)
    {
      case 0:
        mpz_init_set_str(pVal, charArray, 10);
        break;
      case 1:
        mpz_init_set_str(qVal, charArray, 10);
        break;
      case 2:
        mpz_init_set_str(nVal, charArray, 10);
        break;
      case 3:
        mpz_init_set_str(phiVal, charArray, 10);
        break;
      case 4:
        mpz_init_set_str(eVal, charArray, 10);
        break;
      case 5:
        mpz_init_set_str(dVal, charArray, 10);
        break;
      case 6:
        mpz_init_set_str(cVal, charArray, 10);
        break;
      case 7:
        mpz_init_set_str(mVal, charArray, 10);
        break;
    }
    cout << charArray << endl;
  }
  
}

ArgumentValues::ArgumentValues(int argc, char** argv)
{
  this->parseArguments(argc, argv);
  this->convertArguments(valueArray, 8);
}