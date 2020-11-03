//
// Created by valeriisudakov on 03.11.20.
//

#include "DirectoryAccessCheckerUtils.h"
#include "TerminalUtils/TerminalUtils.h"
#include <iostream>

AccessDirectory directory_access_checker_utils::GetAccessByPermissions(const Permissions &permissions) {
  if (!permissions.access_write_.has_value() ||
      !permissions.access_read_.has_value() ||
      !permissions.access_execute_.has_value()){
    return  AccessDirectory::DIRECTORY_DOESNT_EXIST;
  } else if (permissions.access_read_.value() == false ||
             permissions.access_write_.value() == false){
    return AccessDirectory::NOT_ENOUGH_PERMISSIONS;
  }
  return AccessDirectory::HAS_ACCESS;
}

std::vector<std::string> directory_access_checker_utils::GetProgramProcessesID() {
  auto processes_id = terminal_utils::ExecuteCommand("pidof DirectoryAccessChecker");
  processes_id.erase(processes_id.find('\n'));
  return directory_access_checker_utils::SplitStringToWords(processes_id, ' ');
}

std::vector<std::string> directory_access_checker_utils::SplitStringToWords(const std::string &str,
                                                                            const char split_symbol) {
  std::vector<std::string> words;
  std::string word = "";
  for (auto x : str)
  {
    if (x == split_symbol)
    {
      if (!word.empty()) {
        words.push_back(word);
        word = "";
      }
    }
    else {
      word = word + x;
    }
  }
  // adding last folder.
  // If path were inputted like: /Directory/Access/Checker - last folder will be missed.
  if (!word.empty()) {
    words.push_back(word);
  }
  return words;
}

bool directory_access_checker_utils::DoesProcessUseFolder(const std::string &path, const std::vector<std::string>& processes_id) {
  std::string command {"lsof | grep " + path};
  auto floder_info = terminal_utils::ExecuteCommand(command.c_str());
  for (const auto& id : processes_id){
    if (floder_info.find(id) != std::string::npos){
      return true;
    }
  }
  return false;
}