cmake_minimum_required(VERSION 3.20)
project(djib-cli)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.78 REQUIRED COMPONENTS filesystem)

add_executable(djib-cli main.cpp libs/Exception.cpp libs/Exception.h assets/Exception.h libs/ProcessCaller.cpp libs/ProcessCaller.h assets/ProcessCaller.h libs/SolanaAPI.cpp libs/SolanaAPI.h)

target_link_libraries(djib-cli Boost::filesystem)