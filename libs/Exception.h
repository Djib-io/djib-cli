//
// Created by themaqs on 1/26/22.
//

#ifndef DJIB_CLI_EXCEPTION_H
#define DJIB_CLI_EXCEPTION_H


#include <exception>
#include <string>

#include "../assets/Exception.h"

namespace Djib {

    class Exception : public std::exception {
    public:
        Exception() = delete;

        Exception(const Exception &other) = delete;

        Exception(Exception *&other) = delete;

        ~Exception() override = default;

        explicit Exception(const std::string &msg);

        virtual const char *what() const noexcept override;

        const std::string &get_message() const;

    protected:
        void set_message(const std::string &msg);

    private:
        std::string _message;
    };
}



#endif //DJIB_CLI_EXCEPTION_H
