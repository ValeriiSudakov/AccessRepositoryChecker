//
// Created by valeriisudakov on 03.11.20.
//

#include "DirectoryAccessChecker.h"
#include <iostream>

AccessDirectory DirectoryAccessChecker::AccessCheck() {
  auto permissions = file_directory_utils::DirectoryPermissions(current_work_directory_.c_str());

  {
    auto access_directory = directory_access_checker_utils::GetAccessByPermissions(permissions);
    if (AccessDirectory::NOT_ENOUGH_PERMISSIONS == access_directory){
      std::cout<<"Not enough permissions.\n";
      return access_directory;
    }
    if (AccessDirectory::DIRECTORY_DOESNT_EXIST == access_directory){
      auto make_dir = file_directory_utils::MakeDirectory(current_work_directory_.c_str());
      if (!make_dir){
        return AccessDirectory::NOT_ENOUGH_PERMISSIONS;
      }
      std::cout<<"Made "<<current_work_directory_<<" directory.\n";
    }
  }

  auto program_ids = directory_access_checker_utils::GetProgramProcessesID();
  auto busy = directory_access_checker_utils::DoesProcessUseFolder(current_work_directory_, program_ids);

  if (busy){
    std::cout<<"Inputted dir is busy.\n";
    return AccessDirectory::DIRECTORY_IS_BUSY;
  }
  return AccessDirectory::HAS_ACCESS;

}