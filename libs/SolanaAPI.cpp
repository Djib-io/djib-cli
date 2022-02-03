//
// Created by themaqs on 2/4/22.
//

#include "SolanaAPI.h"

using namespace Djib::Solana;

SolanaNotFoundError::SolanaNotFoundError() : Exception(_err_solana_doesnt_exist_) {}

SolanaAPI::SolanaAPI() {

}

