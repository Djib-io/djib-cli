//
// Created by themaqs on 1/26/22.
//

#include "ProcessCaller.h"

using namespace Djib::Process;

ProcessNameError::ProcessNameError() : Exception(_err_invalid_process_name_) {}

ProcessNotFoundError::ProcessNotFoundError() : Exception(_err_process_doesnt_exist_) {}

ProcessFailedError::ProcessFailedError(const std::string &cause) : Exception(
        std::string(_err_process_failed_) + cause) {}

ProcessCaller::ProcessCaller(const std::string &process_name, const std::string &params) {
    this->_process_name = process_name;
    this->_params = params;
    this->_output = "";
    ba::trim(this->_process_name);
    ba::trim(this->_params);
    this->__check_process();
}

void ProcessCaller::__check_process() {
    if (this->_process_name.empty())
        throw ProcessNameError();
    this->_process_path = bp::search_path(this->_process_name);
    if (this->_process_path.empty())
        throw ProcessNotFoundError();
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