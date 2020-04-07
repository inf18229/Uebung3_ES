project(Übung3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Uebung3 src/main.cpp src/PreAllocString.cpp src/Printf.cpp include/PreAllocString.h include/Printf.h)

set(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -Wextra -Wno-format -Wold-style-cast -std=c++17 -fno-exceptions -fno-rtti")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )