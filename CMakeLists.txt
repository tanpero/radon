cmake_minimum_required (VERSION 3.0)
project (radon)
add_library (radon STATIC
    "src/bigint.h"
	"src/bigint.cc"
    "src/radon.h"
	"src/radon.cc"
	"test/main.cc"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

target_include_directories (radon PUBLIC src)

add_executable(radon-test test/main.cc)
target_include_directories (radon-test PUBLIC src)
target_link_libraries(radon-test radon)
