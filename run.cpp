#include <iostream>
using std::cout;
using std::endl;

int main() {
  cout << "\x1B[96mrun v1.0.0-alpha by CerebralDatabank (Gopal Othayoth)\x1B[0m" << endl;
  cout << "\x1B[96m== COMPILING ==\x1B[0m" << endl << endl;

  int result{0};


  result = system("g++ -Wall -Wextra -pedantic -std=c++17 -g ./src/*.cpp -o ./bin/a.out");
  if (result != 0) {
    cout << endl << "\x1B[31m[ ERROR ]\x1B[0m Compilation failed - check errors above.\x1B[0m" << endl;
    cout << "          exit code: \x1B[93m" << result << "\x1B[0m" << endl;
    return result;
  }
  cout << "\x1B[32m[    OK ]\x1B[0m Compilation succeeded!\x1B[0m" << endl;
  
  cout << "\x1B[96m== RUNNING ==\x1B[0m" << endl << endl;
  // system("chmod +x ./bin/a.out");
  result = system("./bin/a.out");
  if (result != 0) {
    cout << endl << "\x1B[31m[ ERROR ]\x1B[0m Program run failed - check errors above.\x1B[0m" << endl;
    cout << "          exit code \x1B[93m" << result << "\x1B[0m" << endl;
    return result;
  }
  cout << endl << "\x1B[32m[    OK ]\x1B[0m Program run succeeded!\x1B[0m" << endl;
  return 0;
}