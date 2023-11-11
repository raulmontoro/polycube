cmake_minimum_required(VERSION 3.20)
project(PolyCubes)

set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/src)
set (INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/inc)
set (TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

set (HEADERS 
    ${INC_DIR}/Helpers.hpp
    ${INC_DIR}/Coord.hpp
    ${INC_DIR}/PolyCube.hpp
)
set (SRCS 
    ${SRC_DIR}/PolyCube.cpp
)
set(TESTS
    ${TEST_DIR}/helpers.cpp
    ${TEST_DIR}/coord.cpp
    ${TEST_DIR}/polycube/compute_center.cpp
    ${TEST_DIR}/polycube/hash.cpp
    ${TEST_DIR}/polycube/sort.cpp
    ${TEST_DIR}/polycube/translate.cpp
    ${TEST_DIR}/polycube/mirror.cpp
)

add_executable(cubes ${SRC_DIR}/main.cpp ${SRCS} ${HEADERS})

target_include_directories(cubes PUBLIC ${INC_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests ${TESTS} ${SRCS} ${HEADERS})

target_include_directories(tests PUBLIC ${INC_DIR} ${TEST_DIR})

target_link_libraries(tests PRIVATE gtest_main)
