//
// Created by themaqs on 1/26/22.
//

#ifndef DJIB_CLI_PROCESSCALLER_H
#define DJIB_CLI_PROCESSCALLER_H

#include <string>
#include <sstream>
#include <boost/process.hpp>

#include "Exception.h"
#include "../assets/ProcessCaller.h"

using std::string;
namespace bp = boost::process;
namespace bf = boost::filesystem;

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

        explicit ProcessFailedError(const std::string &cause);
    };

    class ProcessCaller {
    public:
        const std::string &get_process_name() const;

        const std::string &get_output() const;

        const std::string &get_params() const;

        const std::string &get_process_path() const;

    private:
        std::string _process_name;
        std::string _params;
        std::string _output;
        bf::path _process_path;
    };

}
#endif //DJIB_CLI_PROCESSCALLER_H
