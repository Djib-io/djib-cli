//
// Created by themaqs on 1/26/22.
//

#ifndef DJIB_CLI_PROCESSCALLER_H
#define DJIB_CLI_PROCESSCALLER_H

#include <string>

namespace Djib::Process {

    class ProcessNameError{
    public:
        ProcessNameError();
    };

    class ProcessNotFoundError {
    public:
        ProcessNotFoundError();
    };

    class ProcessFailedError {
    public:
        ProcessFailedError() = delete;

        ProcessFailedError(const std::string &cause);
    };

    class ProcessCaller {

    };

}
#endif //DJIB_CLI_PROCESSCALLER_H
