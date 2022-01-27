//
// Created by themaqs on 1/26/22.
//

#ifndef DJIB_CLI_PROCESSCALLER_H
#define DJIB_CLI_PROCESSCALLER_H

#include <string>
#include <sstream>
#include <boost/process.hpp>
#include <boost/algorithm/string.hpp>

#include "Exception.h"
#include "../assets/ProcessCaller.h"

using std::string;
namespace bp = boost::process;
namespace bf = boost::filesystem;
namespace ba = boost::algorithm;

namespace Djib::Process {

    class ProcessNameError : public Djib::Exception {
    public:
        ProcessNameError();
    };

    class ProcessNotFoundError : public Djib::Exception {
    public:
        ProcessNotFoundError();
    };

    class ProcessFailedError : public Djib::Exception {
    public:
        ProcessFailedError() = delete;

        explicit ProcessFailedError(const std::string &cause);
    };

    class ProcessCaller {
    public:
        ProcessCaller() = delete;

        ProcessCaller(const ProcessCaller &other) = delete;

        ProcessCaller(const ProcessCaller *&other) = delete;

        explicit ProcessCaller(const std::string &process_name, const std::string &params = "");

        ~ProcessCaller() = default;

        const std::string &exec();

        const std::string &get_process_name() const;

        const std::string &get_output() const;

        const std::string &get_params() const;

        const std::string &get_process_path() const;

    private:
        void __check_process();

        std::string _process_name;
        std::string _params;
        std::string _output;
        bf::path _process_path;
    };

}
#endif //DJIB_CLI_PROCESSCALLER_H
