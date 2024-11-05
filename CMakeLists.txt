cmake_minimum_required(VERSION 3.29)
project(concorrencia_proj)

set(CMAKE_CXX_STANDARD 20)

add_executable(concorrencia_proj main.cpp)

# Encontre o pacote TBB
find_package(TBB REQUIRED)

# Linkar o TBB ao seu projeto
target_link_libraries(concorrencia_proj TBB::tbb)