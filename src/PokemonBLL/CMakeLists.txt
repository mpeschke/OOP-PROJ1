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

file(GLOB_RECURSE SOURCESBLL
    *.hpp
    *.cpp
)

add_library(PokemonBLL SHARED ${SOURCESBLL})
set_target_properties(PokemonBLL PROPERTIES SOVERSION 2)
target_include_directories (PokemonBLL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries( PokemonBLL ${Boost_LIBRARIES} )
add_definitions( -DBOOST_ALL_DYN_LINK )