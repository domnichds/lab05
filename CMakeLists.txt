cmake_minimum_required(VERSION 3.10)
project(banking)

# Флаги для покрытия
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Пути к заголовкам Google Test/Mock
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest/googlemock/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest/googletest/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Основная библиотека
add_library(banking
    src/account.cpp
    src/transaction.cpp
)

# Тесты
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    
    # Явное указание тестовых файлов
    set(TEST_SOURCES
        tests/test_account.cpp
        tests/test_transaction.cpp
    )
    
    add_executable(tests ${TEST_SOURCES})
    target_link_libraries(tests
        banking
        gtest
        gmock
        gtest_main
    )
    target_link_libraries(tests --coverage)
    add_test(NAME banking_tests COMMAND tests)
endif()
