#include <iostream>
#include <filesystem>
using std::cout, std::endl;
namespace fs = std::filesystem;

int main() {
  cout << "\x1B[96mrun v1.0.0 by CerebralDatabank (Gopal Othayoth)\x1B[0m" << endl;
  cout << "\x1B[96m== COMPILING ==\x1B[0m" << endl << endl;

  int result{0};
  bool noSrc{false};

  if (!fs::is_directory("src")) {
    cout << "\x1B[94m[  INFO ]\x1B[0m ./src/ directory does not exist; using project root.\x1B[0m" << endl;
    noSrc = true;
  }

  if (!noSrc && !fs::is_directory("bin")) {
    cout << "\x1B[94m[  INFO ]\x1B[0m ./bin/ directory does not exist, creating...\x1B[0m" << endl;
    if (!fs::create_directory("bin")) {
        cout << "\x1B[31m[ ERROR ]\x1B[0m Failed to create ./bin/ directory; exiting.\x1B[0m" << endl;
        return 1;
    }
  }

  if (noSrc) {
    result = system("g++ -Wall -Wextra -pedantic -std=c++17 -g ./*.cpp -o ./a.out");
  }
  else {
    result = system("g++ -Wall -Wextra -pedantic -std=c++17 -g ./src/*.cpp -o ./bin/a.out");
  }
  if (result != 0) {
    cout << endl << "\x1B[31m[ ERROR ]\x1B[0m Compilation failed - check errors above.\x1B[0m" << endl;
    cout << "          exit code: \x1B[93m" << (result >> 8) << "\x1B[0m" << endl;
    return result;
  }
  cout << "\x1B[32m[    OK ]\x1B[0m Compilation succeeded!\x1B[0m" << endl;
  
  cout << "\x1B[96m== RUNNING ==\x1B[0m" << endl << endl;
  if (noSrc) {
    result = system("./a.out");
  }
  else {
    result = system("./bin/a.out");
  }
  if (result != 0) {
    cout << endl << "\x1B[31m[ ERROR ]\x1B[0m Program run failed - check errors above.\x1B[0m" << endl;
    cout << "          exit code: \x1B[93m" << (result >> 8) << "\x1B[0m" << endl;
    return result;
  }
  cout << endl << "\x1B[32m[    OK ]\x1B[0m Program run succeeded!\x1B[0m" << endl;
  return 0;
}