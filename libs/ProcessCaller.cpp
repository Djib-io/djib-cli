//
// Created by themaqs on 1/26/22.
//

#include "ProcessCaller.h"

using namespace Djib::Process;

ProcessNameError::ProcessNameError() : Exception(_err_invalid_process_name_) {}

ProcessNotFoundError::ProcessNotFoundError() : Exception(_err_process_doesnt_exist_) {}

ProcessFailedError::ProcessFailedError(const string &cause) : Exception(string(_err_process_failed_) + cause) {}

ProcessCaller::ProcessCaller(const string &process_name, const string &params) {
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
    auto tmp = bp::search_path(this->_process_name);
    if (tmp.empty())
        throw ProcessNotFoundError();
    this->_process_path = tmp.string() + (this->get_params().empty() ? "" : " " + this->get_params());
}

const string &ProcessCaller::get_process_name() const {
    return this->_process_name;
}

const string &ProcessCaller::get_params() const {
    return this->_params;
}

const string &ProcessCaller::get_output() const {
    return this->_output;
}

const string &ProcessCaller::get_error() const {
    return this->_error;
}

const string &ProcessCaller::get_process_path() const {
    return this->_process_path;
}

bool ProcessCaller::exec() {
    try {
        bp::ipstream pipe_out_stream;
        bp::ipstream pipe_error_stream;
        bp::child c(this->get_process_path(), bp::std_out > pipe_out_stream, bp::std_err > pipe_error_stream);
        c.wait();
        string line;
        std::stringstream ss;
        while (pipe_out_stream && std::getline(pipe_out_stream, line) && !line.empty())
            ss << line << std::endl;
        this->_output = ss.str();
        if(c.exit_code() != 0){
            ss.clear();
            ss.flush();
            while (pipe_error_stream && std::getline(pipe_error_stream, line) && !line.empty())
                ss << line << std::endl;
            this->_error = ss.str();
            return false;
        }
        return true;
    } catch (const std::exception &e) {
        this->_error = e.what();
        throw ProcessFailedError(e.what());
    }
}