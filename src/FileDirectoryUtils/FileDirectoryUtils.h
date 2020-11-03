//
// Created by valeriisudakov on 03.11.20.
//

#ifndef DIRECTORYACCESSCHECKER_FILEDIRECTORYUTILS_FILEDIRECTORYUTILS_H_
#define DIRECTORYACCESSCHECKER_FILEDIRECTORYUTILS_FILEDIRECTORYUTILS_H_
#include "DirectoryPermissions/Permissions.h"

/*
 * File directory utils.
 * Contains functions getting directory info.
 *
 * @author: Valerii Sudakov.
 */

namespace file_directory_utils {
/*
 *  Directory Permission.
 *  Check directory for read, write and execute permissions.
 *  Fills results to the Permissions struct object and returns.
 *  @see DirectoryPermissions/Permissions.h
 *
 *  @input-param: const char* that contains directory to check.
 *
 *  @return-value: Permissions object that contains info about
 *  permissions of inputted directory.
 */
  Permissions DirectoryPermissions(const char* filepath);

/*
 * Make Directory.
 * Make new folder if it doesnt exist.
 * Also created all sub directories.
 *
 * @input-param: const char* that contains directory pass.
 */
  bool        MakeDirectory(const std::string& filepath);
};

#endif //DIRECTORYACCESSCHECKER_FILEDIRECTORYUTILS_FILEDIRECTORYUTILS_H_
