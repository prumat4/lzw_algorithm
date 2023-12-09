#pragma once

#include "BinaryFileManager.hpp"
#include <map>

class LZW {
public:
    void encode(size_t fileSizeInBytes, const std::string& filePath);    
    void decode(size_t fileSizeInBytes, const std::string& filePath);
private:

};