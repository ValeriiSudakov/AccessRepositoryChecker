#include <iostream>
#include "DirectoryAccessChecker/DirectoryAccessChecker.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    DirectoryAccessChecker directory_access_checker("/home/valeriisudakov/asd");
    auto result = directory_access_checker.AccessCheck();
    if (AccessDirectory::HAS_ACCESS == result) {
      std::cout << "Success.\n";
    }
  }
  else {
    DirectoryAccessChecker directory_access_checker(argv[1]);
    auto result = directory_access_checker.AccessCheck();
    if (AccessDirectory::HAS_ACCESS == result){
     std::cout<<"Success.\n";
    }
  }
  return 0;
}
