#include "includes/main.hpp"
using namespace std;

namespace {
const size_t ERROR_IN_CMD = 1;
const size_t SUCCESS = 0;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

// 1 = given; 0 = missing
enum class missVars : uint32_t {
  pSet = (1 << 0),
  qSet = (1 << 1),
  nSet = (1 << 2),
  tSet = (1 << 3),
  cSet = (1 << 4),
  dSet = (1 << 5),
  eSet = (1 << 6),
  mSet = (1 << 7)
};

template<class missVars> inline missVars operator~ (missVars a) { return (missVars)~(int)a; }
template<class missVars> inline missVars operator| (missVars a, missVars b) { return (missVars)((int)a | (int)b); }
template<class missVars> inline missVars operator& (missVars a, missVars b) { return (missVars)((int)a & (int)b); }
template<class missVars> inline missVars operator^ (missVars a, missVars b) { return (missVars)((int)a ^ (int)b); }
template<class missVars> inline missVars& operator|= (missVars& a, missVars b) { return (missVars&)((int&)a |= (int)b); }
template<class missVars> inline missVars& operator&= (missVars& a, missVars b) { return (missVars&)((int&)a &= (int)b); }
template<class missVars> inline missVars& operator^= (missVars& a, missVars b) { return (missVars&)((int&)a ^= (int)b); }

void checkFlags(missVars &Flag, std::unique_ptr<Calculate> &c) {
  if (mpz_cmp_d(c->p.get_mpz_t(), 1))
    Flag |= missVars::pSet;
  if (mpz_cmp_d(c->q.get_mpz_t(), 1))
    Flag |= missVars::qSet;
  if (mpz_cmp_d(c->n.get_mpz_t(), 1))
    Flag |= missVars::nSet;
  if (mpz_cmp_d(c->d.get_mpz_t(), 1))
    Flag |= missVars::dSet;
  if (mpz_cmp_d(c->c.get_mpz_t(), 1))
    Flag |= missVars::cSet;
  if (mpz_cmp_d(c->e.get_mpz_t(), 1))
    Flag |= missVars::eSet;
  if (mpz_cmp_d(c->phi.get_mpz_t(), 1))
    Flag |= missVars::tSet;
  if (mpz_cmp_d(c->m.get_mpz_t(), 1))
    Flag |= missVars::mSet;
}

int checkPQnotN(missVars& Flag) {
  return !((int(Flag) & int(missVars::nSet))) && ((int(Flag) & int(missVars::pSet)) ^ (int(Flag) & int(missVars::qSet)) == (int(missVars::pSet) | int(missVars::qSet)));
}

int checkPNnotQ(missVars& Flag) {
  return !((int(Flag) & int(missVars::qSet))) && ((int(Flag) & int(missVars::pSet)) ^ (int(Flag) & int(missVars::nSet)) == (int(missVars::pSet) | int(missVars::nSet)));
}

int checkQNnotP(missVars& Flag) {
  return !((int(Flag) & int(missVars::pSet))) && ((int(Flag) & int(missVars::qSet)) ^ (int(Flag) & int(missVars::nSet)));
}

int checkPQnotPhi(missVars& Flag) {
  return !((int(Flag) & int(missVars::tSet))) && ((int(Flag) & int(missVars::qSet)) ^ (int(Flag) & int(missVars::pSet)) == (int(missVars::qSet) | int(missVars::pSet)));
}

int checkMENnotC(missVars& Flag) {
  return !((int(Flag) & int(missVars::cSet))) && ((int(Flag) & int(missVars::mSet)) ^ (int(Flag) & int(missVars::eSet)));
}

int checkCDNnotM(missVars& Flag){
  return !((int(Flag) & int(missVars::mSet))) && ((int(Flag) & int(missVars::cSet)) ^ (int(Flag) & int(missVars::dSet)));
}

int checkEPhinotD(missVars& Flag) {
  return !((int(Flag) & int(missVars::dSet))) && ((int(Flag) & int(missVars::eSet)) ^ (int(Flag) & int(missVars::tSet)));
}

void printAllVariables(std::unique_ptr<Calculate> &c){
  cout << "P: " << calc->p << endl;
  cout << "Q: " << calc->q << endl;
  cout << "N: " << calc->n << endl;
  cout << "Totient: " << calc->phi << endl;
  cout << "D: " << calc->d << endl;
  cout << "E: " << calc->e << endl;
  cout << "C: " << calc->c << endl;
  cout << "M: " << calc->m << endl;
}

int main(int argc, char **argv) {
  try {

    namespace args = boost::program_options;
    args::variables_map vm;
    args::options_description desc("Arguments");

    desc.add_options()
      ("help,h", "Print help message")
      (",m", args::value<string>()->default_value("1"), "Message")
      (",p", args::value<string>()->default_value("1"), "P value")
      (",q", args::value<string>()->default_value("1"), "Q value")
      (",n", args::value<string>()->default_value("1"), "Modulus")
      (",t", args::value<string>()->default_value("1"), "Totient value")
      (",c", args::value<string>()->default_value("1"), "Cipher text")
      (",d", args::value<string>()->default_value("1"),"D value")
      (",e", args::value<string>()->default_value("1"),"exponent");
    args::store(args::parse_command_line(argc, argv, desc), vm);

    try {
      auto iN = vm["-n"].as<string>();
      auto iM = vm["-m"].as<string>();
      auto iP = vm["-p"].as<string>();
      auto iC = vm["-c"].as<string>();
      auto iQ = vm["-q"].as<string>();
      auto iD = vm["-d"].as<string>();
      auto iE = vm["-e"].as<string>();
      auto iPhi = vm["-t"].as<string>();
      calc = std::make_unique<Calculate>(iN, iM, iP, iC, iQ, iD, iE, iPhi);
      // Set flag time
      missVars Flag;

      checkFlags(Flag, calc);
      cout << "CHECK:" << endl;

      if (checkMENnotC(Flag)){
        calc->C_M_E_N();
        checkFlags(Flag, calc);
      }
      if (checkPQnotN(Flag)){
        calc->N_P_Q();
        checkFlags(Flag, calc);
      }
      if (checkPNnotQ(Flag)) {
        calc->Q_P_N();
        checkFlags(Flag, calc);
      }
      if (checkQNnotP(Flag)){
        calc->P_Q_N();
        checkFlags(Flag, calc);
      }
      if (checkPQnotPhi(Flag)){
        calc->Eulers_P_Q();
        checkFlags(Flag, calc);
      }
      if (checkCDNnotM(Flag)){
        calc->M_C_D_N();
        checkFlags(Flag, calc);
      }
      if (checkEPhinotD(Flag)){
        calc->D_E_Phi();
        checkFlags(Flag, calc);
      }
      printAllVariables(calc);
      if (vm.count("help")) {
        cout << desc << endl;
        return SUCCESS;
      }
      args::notify(vm);
    } 
    
    catch (args::error &e) {
      cerr << "Error: " << e.what() << endl << endl;
      cerr << desc << endl;
      return ERROR_IN_CMD;
    }
  } 

  catch (exception &e) {
    cerr << "Unhandled Exception reached the top of main: " << e.what() << ", EXITING" << endl;
    return ERROR_UNHANDLED_EXCEPTION;
  }

  return SUCCESS;
}
