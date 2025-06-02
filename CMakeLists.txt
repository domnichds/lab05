cmake_minimum_required(VERSION 3.10)
project(banking)

# Добавляем пути к заголовкам Google Mock
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest/googlemock/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest/googletest/include
)

add_library(banking
    src/account.cpp
    src/transaction.cpp
)

target_include_directories(banking PUBLIC include)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    
    file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)
    
    add_executable(tests ${TEST_SOURCES})
    target_include_directories(tests PRIVATE include)
    
    # Исправляем линковку
    target_link_libraries(tests 
        banking 
        gtest 
        gmock 
        gtest_main
    )
    
    add_test(NAME banking_tests COMMAND tests)
endif()
