add_library(DataCompression
    DataCompression.cpp
)

target_include_directories(DataCompression
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)