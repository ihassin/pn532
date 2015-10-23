cmake_minimum_required(VERSION 3.3)
project(pn532)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(UNITY_TEST_SOURCE_FILES unity-tests.h command-tests.h command-tests.c)
set(SOURCE_FILES main.c)

# Create unity lib => unit test framework
add_subdirectory (unity)
add_library (unity unity/unity.c unity/unity.h unity/unity_internals.h)

# Create hlp lib => Host Link Protocol
add_subdirectory (hlp)
add_library (hlp hlp/hlp.c hlp/hlp.h)

add_executable(pn532 ${SOURCE_FILES} ${UNITY_TEST_SOURCE_FILES})

target_link_libraries (pn532 LINK_PUBLIC hlp unity)
