#To fill
include_directories(${PARADISEO_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)

# target_link_libraries(... ${PARADISEO_LIBRARIES})

enable_testing()

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# add_executable(...)
add_executable(HV_TEST hypervolumeTest.cpp)
add_executable(CROSSOVER_TEST crossoverTest.cpp)

target_link_libraries(HV_TEST ${PARADISEO_LIBRARIES} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_compile_definitions(HV_TEST PRIVATE "BOOST_TEST_DYN_LINK=1")

target_link_libraries(CROSSOVER_TEST ${PARADISEO_LIBRARIES} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_compile_definitions(CROSSOVER_TEST PRIVATE "BOOST_TEST_DYN_LINK=1")
