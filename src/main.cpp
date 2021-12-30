#include <iostream>
#include <string>
#include <tclap/CmdLine.h>
#include "includes/main.hpp"
#include "includes/rsa.hpp"

using namespace std;

namespace TCLAP {
template <>
struct ArgTraits<mpz_class> {
    typedef StringLike ValueCategory;
};
}

// Return count
int getInput(mpz_class *inputValues, int argc, char** argv)
{
  try
  {
    TCLAP::CmdLine cmd("Compute RSA Values", ' ', "2");
    TCLAP::ValueArg<mpz_class> input_p("p", "P", "P Value", false, 0, "int", cmd);
    TCLAP::ValueArg<mpz_class> input_q("Q","Q","Q", false, 0 ,"int", cmd);
    TCLAP::ValueArg<mpz_class> input_n("N","N","N", false, 0 ,"int", cmd);
    TCLAP::ValueArg<mpz_class> input_t("T","T","T", false, 0 ,"int", cmd);
    TCLAP::ValueArg<mpz_class> input_e("E","E","E", false, 0 ,"int", cmd);
    TCLAP::ValueArg<mpz_class> input_d("D","D","D", false, 0 ,"int", cmd);
    TCLAP::ValueArg<mpz_class> input_c("C","C","C", false, 0 ,"int", cmd);
    TCLAP::ValueArg<mpz_class> input_m("M","M","M", false, 0 ,"int", cmd);

    cmd.parse(argc, argv);
    inputValues[0] = input_p.getValue();
    inputValues[1] = input_q.getValue();
    inputValues[2] = input_n.getValue();
    inputValues[3] = input_t.getValue();
    inputValues[4] = input_e.getValue();
    inputValues[5] = input_d.getValue();
    inputValues[6] = input_c.getValue();
    inputValues[7] = input_m.getValue();

  } catch (TCLAP::ArgException &e)  // catch exceptions
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
  return 0;
}

int main(int argc, char** argv) 
{
  mpz_class inputValues[8];
  getInput(inputValues, argc, argv);
  RSAObject *rsaObj = new RSAObject(inputValues);
}