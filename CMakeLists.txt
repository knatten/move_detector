cmake_minimum_required(VERSION 3.10.3)
project(OptionalDo)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++ -I/usr/local/opt/llvm/include")
add_executable(main main.cpp move_detector_test.cpp)
