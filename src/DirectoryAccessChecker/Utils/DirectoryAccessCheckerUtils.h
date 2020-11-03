//
// Created by valeriisudakov on 03.11.20.
//

#ifndef DIRECTORYACCESSCHECKER_DIRECTORYACCESSCHECKER_UTILS_DIRECTORYACCESSCHECKERUTILS_H_
#define DIRECTORYACCESSCHECKER_DIRECTORYACCESSCHECKER_UTILS_DIRECTORYACCESSCHECKERUTILS_H_
#include "DirectoryAccessChecker/AccessResult.h"
#include "FileDirectoryUtils/DirectoryPermissions/Permissions.h"
#include <vector>

/*
 *  Directory access checker utils.
 *  Contains secondary functions of DirectoryAccessChecker.
 *
 *  @author: Valerii Sudakov.
 */
namespace directory_access_checker_utils {

/*
 * Get access by permissions.
 * Make AccessDirectory by permissions.
 *
 * @input-param: Permissions that contains directory permissions data;
 * @see FileDirectoryUtils/Permissions/Permissions.h
 *
 * @return-value: AccessDirectory
 * @see AccessDirectory.h
 */
  AccessDirectory                   GetAccessByPermissions(const Permissions& permissions);

/*
 * Does process use folder.
 * Check if any processes of this program use folder.
 * Makes requests by the ubuntu terminal and process response.
 *
 * @input-param: const std::string& that contains path to check.
 *
 * @input-param: const std::vector<std::string>& that contains list
 * of ids of this program.
 *
 * @return-value: true if busy, false if not.
 */
  bool                              DoesProcessUseFolder(const std::string& path, const std::vector<std::string>& processes_id);

/*
 * Get program processes id
 * Makes request by the ubuntu terminal and returns id
 * of the run program processes.
 *
 * @return-value: std::vector of ids.
 */
  std::vector<std::string>          GetProgramProcessesID();

/*
 *  Split string to words.
 *  Makes from string vector of strings.
 *
 *  @input-param: const std::string& that contains string to split.
 *
 *  @input-param: const char that contains split symbol.
 *
 *  @return-value: std::vector<std::string> of splitted words.
 */
  std::vector<std::string>          SplitStringToWords(const std::string& str, const char split_symbol);
};

#endif //DIRECTORYACCESSCHECKER_DIRECTORYACCESSCHECKER_UTILS_DIRECTORYACCESSCHECKERUTILS_H_
