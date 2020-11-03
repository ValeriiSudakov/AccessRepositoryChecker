//
// Created by valeriisudakov on 03.11.20.
//

#ifndef DIRECTORYACCESSCHECKER__DIRECTORYACCESSCHECKER_H_
#define DIRECTORYACCESSCHECKER__DIRECTORYACCESSCHECKER_H_
#include <fstream>
#include "FileDirectoryUtils/FileDirectoryUtils.h"
#include "AccessResult.h"
#include "Utils/DirectoryAccessCheckerUtils.h"

/*
 *  Directory access checker.
 *  Check application permissions to the directory.
 *
 *  @author: Valerii Sudakov.
 */
class DirectoryAccessChecker {
 public:
  DirectoryAccessChecker(const std::string& directory)
  : current_work_directory_(directory) {  }

/*
 * Check inputted dir to access permissions.
 *
 * @return-value: AccessDirectory that contains info about permissions.
 * @see AccessDirectory.h
 */
  AccessDirectory AccessCheck();

 private:
  std::string current_work_directory_;
};

#endif //DIRECTORYACCESSCHECKER__DIRECTORYACCESSCHECKER_H_
