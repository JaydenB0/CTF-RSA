#include <boost/program_options.hpp>
#include <iostream>
using namespace std;

typedef long long ll;
namespace {
const size_t ERROR_IN_CMD = 1;
const size_t SUCCESS = 0;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

int main(int argc, char **argv) {
  ll m, p, c, q, n, d, e, phi;
  try {
    namespace args = boost::program_options;
    args::options_description desc("Arguments");
    desc.add_options()("help,h", "Print help message")(
        "message,m", args::value<ll>(&m),
        "Message")(",p", args::value<ll>(&p),
                   "P value")(",q", args::value<ll>(&q),
                              "Q value")(",n", args::value<ll>(&n), "Modulus")(
        "phi,t", args::value<ll>(&phi),
        "Totient value")(",c", args::value<ll>(&c), "Cipher text")(
        ",d", args::value<ll>(&d), "D value")(",e", args::value<ll>(&e),
                                              "exponent");
    args::variables_map vm;
    try {
      args::store(args::parse_command_line(argc, argv, desc), vm);
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
