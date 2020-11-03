//
// Created by valeriisudakov on 03.11.20.
//

#include "FileDirectoryUtils.h"
#include <iostream>
#include <unistd.h>
#include "TerminalUtils/TerminalUtils.h"

Permissions file_directory_utils::DirectoryPermissions(const char *filepath) {
  // Check read access
  Permissions permissions;
  int returnval = 0;
  returnval = access (filepath, R_OK);

  if (errno == ENOENT) {
    std::cout << filepath << " No such file or directory.\n";
    permissions.access_read_ = std::nullopt;
    permissions.access_write_ = std::nullopt;
    permissions.access_execute_ = std::nullopt;
    return  permissions;
  }

  if (returnval == 0) {
    std::cout << filepath << " has Read permissions.\n";
    permissions.access_read_ = true;
  } else if (errno == EACCES){
    std::cout<<filepath<<" Read Permission denied.\n";
    permissions.access_read_ = false;
  }

  // Check write access
  returnval = 0;
  returnval = access (filepath, W_OK);
  if (returnval == 0) {
    std::cout << filepath << " has Write permissions.\n";
    permissions.access_write_ = true;
  } else if (errno == EACCES){
    std::cout<<filepath<<" Write Permission denied.\n";
    permissions.access_write_ = false;
  }
  // Check execute access
  returnval = 0;
  returnval = access (filepath, X_OK);
  if (returnval == 0) {
    std::cout << filepath << " has Execute permissions.\n";
    permissions.access_execute_ = true;
  } else if (errno == EACCES){
    std::cout<<filepath<<" Execute Permission denied.\n";
    permissions.access_execute_ = false;
  }
  return permissions;
}

bool file_directory_utils::MakeDirectory(const std::string& filepath) {
  std::string command {"mkdir -p " + filepath};
  auto result = terminal_utils::ExecuteCommand(command.c_str());
  if (result.empty()){
    return true;
  }
  if (result.find("Permission denied")){
    std::cout<<result<<"\n";
    return false;
  }
  return false;
}