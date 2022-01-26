//
// Created by themaqs on 1/26/22.
//

#ifndef DJIB_CLI_ASSETS_PROCESSCALLER_H
#define DJIB_CLI_ASSETS_PROCESSCALLER_H

#include <string>

namespace Djib::Process {

    constexpr auto _err_invalid_process_name_ = "Process name doesn't have a valid format.";
    constexpr auto _err_process_doesnt_exist_ = "Process doesn't exist on the system path.";
    constexpr auto _err_process_failed_ = "Can't run the process. Reason: ";

}

#endif //DJIB_CLI_ASSETS_PROCESSCALLER_H
