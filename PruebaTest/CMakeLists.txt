cmake_minimum_required(VERSION 3.12)
project(PruebaTest)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall --coverage")
#SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

include(cmake-modules/CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()
set(COVERAGE_LCOV_EXCLUDES 'cmake-build-debug/*' 'cmake-modules/*' '*7*' '*boost*')

include_directories(src)
include_directories(test)

set(BOOST_INCLUDE_DIRS /home/carlos/Instaladores/boost_1_68_0)

add_executable(PruebaTest
        src/NumberTheoryCalculator.cpp
        src/NumberTheoryCalculator.h
        src/NumberTheoryCalculatorWithContracts.cpp
        src/NumberTheoryCalculatorWithContracts.h
        main.cpp)

enable_testing()

link_directories(/home/carlos/Instaladores/boost_1_68_0/stage/lib/)

add_executable(NTCalcTEST test/Test.cpp src/NumberTheoryCalculator.cpp src/NumberTheoryCalculator.h)

add_executable(NTCalcWCTEST test/TestContracts.cpp src/NumberTheoryCalculatorWithContracts.cpp src/NumberTheoryCalculatorWithContracts.h)

find_package(Boost REQUIRED COMPONENTS unit_test_framework contract system)
target_include_directories(NTCalcTEST PRIVATE ${Boost_INCLUDE_DIRS})
target_compile_definitions(NTCalcTEST PRIVATE "BOOST_TEST_DYN_LINK=1")
target_link_libraries(NTCalcTEST ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

target_include_directories(NTCalcWCTEST PRIVATE ${Boost_INCLUDE_DIRS})
target_compile_definitions(NTCalcWCTEST PRIVATE "BOOST_TEST_DYN_LINK=1")
target_link_libraries(NTCalcWCTEST ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_CONTRACT_LIBRARY} ${Boost_SYSTEM_LIBRARY})

SETUP_TARGET_FOR_COVERAGE_LCOV(
    NAME NTCalcTESTCoverage_LCOV            # New target name
    EXECUTABLE NTCalcTEST                   # Executable in PROJECT_BINARY_DIR
    #DEPENDENCIES testrunner                # Dependencies to build first
)

SETUP_TARGET_FOR_COVERAGE_GCOVR_HTML(
    NAME NTCalcTESTCoverage_GCOVR           # New target name
    EXECUTABLE NTCalcTEST                   # Executable in PROJECT_BINARY_DIR
    #DEPENDENCIES executable_target         # Dependencies to build first
)

SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME NTCalcWCTESTCoverage_LCOV            # New target name
        EXECUTABLE NTCalcWCTEST                   # Executable in PROJECT_BINARY_DIR
        #DEPENDENCIES testrunner                # Dependencies to build first
)

SETUP_TARGET_FOR_COVERAGE_GCOVR_HTML(
        NAME NTCalcWCTESTCoverage_GCOVR           # New target name
        EXECUTABLE NTCalcWCTEST                   # Executable in PROJECT_BINARY_DIR
        #DEPENDENCIES executable_target         # Dependencies to build first
)