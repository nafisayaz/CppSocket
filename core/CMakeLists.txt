cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project( 
    CxxSocket
    VERSION 1.0.0
    DESCRIPTION "This is C++ Socket Library"
    HOMEPAGE_URL "https://nafisayaz.github.io/espresso/doc.html"
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/sock/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/sock/headers
    ${PROJECT_ROOT}/utilities/headers
)

add_library( cxxsock SHARED 
    ${CMAKE_CURRENT_SOURCE_DIR}/sock/src/serv-sock_t.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sock/src/cli-sock_t.cpp 
)
