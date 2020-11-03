#include <iostream>
#include "DirectoryAccessChecker/DirectoryAccessChecker.h"
#include "unistd.h" //chdir

int main(int argc, char* argv[]) {
  if (argc == 1 || argv[1] == "") {
    std::cout<<"Error. Empty path\n";
    return 2;
  }
  // run from terminal
  else {
    DirectoryAccessChecker directory_access_checker(argv[1]);
    auto result = directory_access_checker.AccessCheck();

    if (AccessDirectory::HAS_ACCESS == result) {
      std::cout << "Success.\n";

      // "take" folder while application work. (moved current dir to the inputted)
      chdir(argv[1]);

      // wait for input to close program
      std::cout << "To exit press any key.\n";
      getchar();
    } else {
      return 2;
    }
  }
  return 0;
}
