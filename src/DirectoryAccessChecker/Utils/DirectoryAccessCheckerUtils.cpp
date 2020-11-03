//
// Created by valeriisudakov on 03.11.20.
//

#include "DirectoryAccessCheckerUtils.h"

AccessDirectory directory_access_checker_utils::GetAccessByPermissions(const Permissions &permissions) {
  if (!permissions.access_write_.has_value() ||
      !permissions.access_read_.has_value() ||
      !permissions.access_execute_.has_value()){
    return  AccessDirectory::DIRECTORY_DOESNT_EXIST;
  } else if (!permissions.access_read_.value() &&
             !permissions.access_execute_.value()){
    return AccessDirectory::NOT_ENOUGH_PERMISSIONS;
  }
}