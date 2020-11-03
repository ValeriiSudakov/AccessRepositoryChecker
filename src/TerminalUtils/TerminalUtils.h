//
// Created by valeriisudakov on 03.11.20.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_TERMITALUTILS_TERMINALUTILS_H_
#define DIRECTORYACCESSCHECKER_SRC_TERMITALUTILS_TERMINALUTILS_H_
#include <string>

/*
 *  Terminal utils.
 *  Contains functions to work with ubuntu terminal
 *  @author: Valerii Sudakov.
 */

namespace terminal_utils {
/*
 * Execute command.
 * Takes command to execute, run it and returns
 * result as string.
 *
 * @input-param: const char* that contains command
 * to execute.
 *
 * @return-value: std::string with results.
 */
  std::string ExecuteCommand(const char* command);
};

#endif //DIRECTORYACCESSCHECKER_SRC_TERMITALUTILS_TERMINALUTILS_H_
