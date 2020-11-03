//
// Created by valeriisudakov on 03.11.20.
//

#ifndef DIRECTORYACCESSCHECKER_FILEDIRECTORYUTILS_DIRECTORYPERMISSIONS_PERMISSIONS_H_
#define DIRECTORYACCESSCHECKER_FILEDIRECTORYUTILS_DIRECTORYPERMISSIONS_PERMISSIONS_H_
#include <optional>

/*
 *  Permissions access of directory.
 *
 *  Displays permissions to read, write and execute files.
 *
 *  If directory doesnt exist value is std::nullopt.
 *
 *  @author: Valerii Sudakov.
 */
struct Permissions{
  std::optional<bool> access_read_;
  std::optional<bool> access_write_;
  std::optional<bool> access_execute_;
};

#endif //DIRECTORYACCESSCHECKER_FILEDIRECTORYUTILS_DIRECTORYPERMISSIONS_PERMISSIONS_H_
