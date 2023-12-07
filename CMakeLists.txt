cmake_minimum_required(VERSION 3.12)
project(ZLW-algorithm)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

add_executable(main
    main.cpp
)

target_link_libraries(main
ZLW-algorithm
)