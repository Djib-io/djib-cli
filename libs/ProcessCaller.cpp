//
// Created by themaqs on 1/26/22.
//

#include "ProcessCaller.h"

using namespace Djib::Process;

ProcessNameError::ProcessNameError() {
    throw Exception(_err_invalid_process_name_);
}

ProcessNotFoundError::ProcessNotFoundError()  {
    throw Exception(_err_process_doesnt_exist_);
}

ProcessFailedError::ProcessFailedError(const std::string& cause)  {
    throw Exception(std::string(_err_process_failed_) + cause);
}



const std::string &ProcessCaller::get_process_name() const {
    return this->_process_name;
}

const std::string &ProcessCaller::get_params() const {
    return this->_params;
}

const std::string &ProcessCaller::get_output() const {
    return this->_output;
}

const std::string &ProcessCaller::get_process_path() const {
    return this->_process_path.string();
}