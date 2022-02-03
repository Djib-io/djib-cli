//
// Created by themaqs on 2/4/22.
//

#ifndef DJIB_CLI_SOLANAAPI_H
#define DJIB_CLI_SOLANAAPI_H


#include "ProcessCaller.h"

#include "../assets/SolanaAPI.h"


namespace Djib::Solana {

    class SolanaNotFoundError : public Djib::Exception {
    public:
        SolanaNotFoundError();
    };

    class SolanaAPI {
    public:
        SolanaAPI();

    private:
        void __check_solana();
    };

}

#endif //DJIB_CLI_SOLANAAPI_H
