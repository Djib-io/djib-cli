//
// Created by themaqs on 1/26/22.
//

#include "Exception.h"

using namespace Djib;

Exception::Exception(const std::string &msg){
    this->__message = std::string(_djib_exception_prefix_) + msg;
}

const std::string &Exception::get_message() const {
    return this->__message;
}

const char *Exception::what() const noexcept {
    return this->__message.c_str();
}

void Exception::set_message(const std::string &msg) {
    this->__message = msg;
}
