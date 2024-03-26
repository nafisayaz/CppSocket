
cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_ROOT "/home/ayaz/Projects/CppSocket" )

project( 
    Executor
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "This is C++ Socket Library"
    HOMEPAGE_URL "https://nafisayaz.github.io/espresso/doc.html"
)


add_subdirectory(
    core/
)
    
add_subdirectory(
    ${PROJECT_ROOT}/Server_test/
)

add_subdirectory(
    ${PROJECT_ROOT}/Client_test/
)

# message("PROJECT_SOURCE_DIR===> = " ${PROJECT_SOURCE_DIR})
# message("CMAKE_CURRENT_SOURCE_DIR ==>>>>>>> ", ${CMAKE_CURRENT_SOURCE_DIR})
# message("PROJECT_ROOT ==>>>>>>> ", ${PROJECT_ROOT})
# message("PROJECT_NAME ==>>>>>>>>>>>>>>>>>>>>> ", ${PROJECT_NAME})




