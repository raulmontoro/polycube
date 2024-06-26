cmake_minimum_required(VERSION 3.20)
project(PolyCubes)

set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/src)
set (INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/inc)
set (TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

set (HEADERS 
    ${INC_DIR}/Helpers.hpp
    ${INC_DIR}/Coord.hpp
    ${INC_DIR}/PolyCube.hpp
    ${INC_DIR}/HashedList.hpp
    ${INC_DIR}/CubeSet.hpp
    ${INC_DIR}/CubeSpace.hpp
)
set (SRCS 
    ${SRC_DIR}/PolyCube.cpp
    ${SRC_DIR}/CubeSet.cpp
)
set(TESTS
    ${TEST_DIR}/helpers.cpp
    ${TEST_DIR}/coord.cpp
    ${TEST_DIR}/hashedlist.cpp
    ${TEST_DIR}/cubeset.cpp
    ${TEST_DIR}/cubespace.cpp
    ${TEST_DIR}/polycube/in_list.cpp
    ${TEST_DIR}/polycube/compute_center.cpp
    ${TEST_DIR}/polycube/hash.cpp
    ${TEST_DIR}/polycube/sort.cpp
    ${TEST_DIR}/polycube/translate.cpp
    ${TEST_DIR}/polycube/mirror.cpp
)

# binary build (executable, contains main, main.cpp)
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






# binary build (non executable)
add_executable(tests ${TESTS} ${SRCS} ${HEADERS})
target_include_directories(tests PUBLIC ${INC_DIR} ${TEST_DIR})





target_link_libraries(tests PRIVATE gtest_main)
target_compile_definitions(tests PRIVATE POLYCUBES_SAFTEY_TESTS=1)
target_compile_definitions(tests PRIVATE POLYCUBES_INCLUDE_TIME_TESTS=0)
