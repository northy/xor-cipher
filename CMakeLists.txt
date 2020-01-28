cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Crypt VERSION 1.0)

add_library(crypt
    src/crypt.cxx
)
include_directories(includes)

add_executable(Run app/application.cxx)
target_link_libraries(Run
    crypt
)
