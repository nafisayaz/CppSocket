cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project( 
    uQuick
    VERSION 1.0.0
    DESCRIPTION "This is C++ Socket Library"
    HOMEPAGE_URL "https://nafisayaz.github.io/espresso/doc.html"
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

add_library( uquick SHARED 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/quick.cpp  
)
