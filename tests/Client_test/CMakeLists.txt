cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project( 
    Cxx-Client
    VERSION 1.0.0
    DESCRIPTION "This is C++ Socket Library"
    HOMEPAGE_URL "https://nafisayaz.github.io/espresso/doc.html"
)

add_executable( ${PROJECT_NAME}
    Client.cpp
)

target_include_directories( ${PROJECT_NAME} PRIVATE
    ${PROJECT_ROOT}/core/sock/headers
)

target_link_directories( ${PROJECT_NAME} PRIVATE
    core/
)

target_link_libraries( ${PROJECT_NAME}
    cxxsock
    pthread
    uquick
    
)
