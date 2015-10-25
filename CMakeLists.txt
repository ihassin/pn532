#cmake_minimum_required(VERSION 3.3)
cmake_minimum_required(VERSION 2.8.7)

project(pn532)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(UNITY_TEST_SOURCE_FILES unit-tests/unity-tests.h unit-tests/command-tests.h unit-tests/command-tests.c)
set(SOURCE_FILES main.c)

# Create unity lib => unit test framework
add_subdirectory (unity)
add_library (unity unity/unity.c unity/unity.h unity/unity_internals.h)

# Create hlp lib => Host Link Protocol
add_subdirectory (hlp)
add_library (hlp hlp/hlp.c hlp/hlp.h)

# Create unit-tests lib
add_subdirectory (unit-tests)
add_library (unit-tests unit-tests/command-tests.c unit-tests/command-tests.h unit-tests/unity-tests.h)

# Create pn532 lib
add_subdirectory (pn532-driver)
add_library (pn532-driver pn532-driver/pn532.c pn532-driver/pn532.h)

add_executable(pn532 ${SOURCE_FILES} ${UNITY_TEST_SOURCE_FILES})

target_link_libraries (pn532 LINK_PUBLIC hlp unity unit-tests pn532-driver)
