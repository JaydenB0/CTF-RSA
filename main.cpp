#include "includes/main.hpp"
using namespace std;

using mt = mpz_t;
namespace {
const size_t ERROR_IN_CMD = 1;
const size_t SUCCESS = 0;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

enum class missingVariables : uint32_t {
  p = (1 << 0),
  q = (1 << 1),
  n = (1 << 2),
  t = (1 << 3),
  c = (1 << 4),
  d = (1 << 5),
  e = (1 << 6),
  m = (1 << 7)
};

constexpr enum missingVariables operator|(const enum missingVariables selfValue,
                                          const enum missingVariables inValue) {
  return (enum missingVariables)(uint32_t(selfValue) | uint32_t(inValue));
}

int main(int argc, char **argv) {
  try {

    namespace args = boost::program_options;
    args::variables_map vm;
    args::options_description desc("Arguments");

    desc.add_options()
      ("help,h", "Print help message")
      (",m", args::value<string>()->multitoken()->default_value("0"), "Message")
      (",p", args::value<string>()->multitoken()->default_value("0"), "P value")
      (",q", args::value<string>()->multitoken()->default_value("0"), "Q value")
      (",n", args::value<string>()->multitoken()->default_value("0"), "Modulus")
      (",t", args::value<string>()->multitoken()->default_value("0"), "Totient value")
      (",c", args::value<string>()->multitoken()->default_value("0"), "Cipher text")
      (",d", args::value<string>()->multitoken()->default_value("0"),"D value")
      (",e", args::value<string>()->multitoken()->default_value("0"),"exponent");
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
