add_library(ZLW-algorithm
    BinaryFileManager.cpp
    ZivLempelWelchAlgorithm.cpp
)

target_include_directories(ZLW-algorithm
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)