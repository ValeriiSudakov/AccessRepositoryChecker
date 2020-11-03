//
// Created by valeriisudakov on 03.11.20.
//

#ifndef DIRECTORYACCESSCHECKER_DIRECTORYACCESSCHECKER_UTILS_DIRECTORYACCESSCHECKERUTILS_H_
#define DIRECTORYACCESSCHECKER_DIRECTORYACCESSCHECKER_UTILS_DIRECTORYACCESSCHECKERUTILS_H_
#include "DirectoryAccessChecker/AccessResult.h"
#include "FileDirectoryUtils/DirectoryPermissions/Permissions.h"

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
  AccessDirectory GetAccessByPermissions(const Permissions& permissions);
};

#endif //DIRECTORYACCESSCHECKER_DIRECTORYACCESSCHECKER_UTILS_DIRECTORYACCESSCHECKERUTILS_H_
