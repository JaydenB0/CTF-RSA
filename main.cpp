#include "includes/main.hpp"
using namespace std;

using mt = mpz_t;
namespace {
const size_t ERROR_IN_CMD = 1;
const size_t SUCCESS = 0;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

int main(int argc, char **argv) {
  try {
    namespace args = boost::program_options;
    args::options_description desc("Arguments");
    desc.add_options()("help,h", "Print help message")(
        ",m", args::value<string>()->multitoken()->default_value("0"),
        "Message")(",p",
                   args::value<string>()->multitoken()->default_value("0"),
                   "P value")(
        ",q", args::value<string>()->multitoken()->default_value("0"),
        "Q value")(",n",
                   args::value<string>()->multitoken()->default_value("0"),
                   "Modulus")(
        ",t", args::value<string>()->multitoken()->default_value("0"),
        "Totient value")(
        ",c", args::value<string>()->multitoken()->default_value("0"),
        "Cipher text")(",d",
                       args::value<string>()->multitoken()->default_value("0"),
                       "D value")(
        ",e", args::value<string>()->multitoken()->default_value("0"),
        "exponent");
    args::variables_map vm;
    try {
      args::store(args::parse_command_line(argc, argv, desc), vm);
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
    } catch (args::error &e) {
      cerr << "Error: " << e.what() << endl << endl;
      cerr << desc << endl;
      return ERROR_IN_CMD;
    }
  } catch (exception &e) {
    cerr << "Unhandled Exception reached the top of main: " << e.what()
         << ", EXITING" << endl;
    return ERROR_UNHANDLED_EXCEPTION;
  }

  return SUCCESS;
}
