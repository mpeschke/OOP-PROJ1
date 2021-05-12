set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(USE_LCOV)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        SET(CMAKE_CXX_FLAGS "-g -O0 ${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_FLAGS} -fprofile-arcs -ftest-coverage")
        SET(CMAKE_EXE_LINKER_FLAGS "--coverage")
        SET(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_FLAGS} --coverage")
        message("CLang detected - using -g -O0 -fprofile-arcs -ftest-coverage --coverage")
    else()
        SET(GCC_COVERAGE_FLAGS "-fprofile-arcs -ftest-coverage")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_FLAGS}")
        SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
        SET(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_FLAGS}")
        message("GCC detected - using -fprofile-arcs -ftest-coverage")
    endif()    
endif(USE_LCOV)

cmake_minimum_required(VERSION 3.5)

file(GLOB_RECURSE SOURCES
    *.hpp
    *.cpp
)

add_executable(Pokemon ${SOURCES})
target_link_libraries (Pokemon LINK_PUBLIC PokemonBLL ${Boost_LIBRARIES})