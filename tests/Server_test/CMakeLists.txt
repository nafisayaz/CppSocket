cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project( 
    Cxx-Server
    VERSION 1.0.0
    DESCRIPTION "This is C++ Socket Library"
    HOMEPAGE_URL "https://nafisayaz.github.io/espresso/doc.html"
)

add_executable( ${PROJECT_NAME}
    Server.cpp
)

target_include_directories( ${PROJECT_NAME} PRIVATE
    ${PROJECT_ROOT}/core/sock/headers
    # ${CMAKE_CURRENT_SOURCE_DIR}/core/sock/headers
)

target_link_directories( ${PROJECT_NAME} PRIVATE
    ${PROJECT_ROOT}/core/
    ${PROJECT_ROOT}/utilities/
)

target_link_libraries( ${PROJECT_NAME} PRIVATE
    cxxsock
    pthread
    uquick

)
