#pragma once

#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

#define INPUT_FLAGS std::ios::in | std::ios::binary | std::ios::app
#define OUTPUT_FLAGS std::ios::out | std::ios::binary | std::ios::app

class BinaryFileManager {
private:
    size_t getNumberOfBytes(size_t size) const noexcept;
    void isValidFile(const std::fstream& file) const;
public:
    std::vector<char> readBitSequence(size_t size, const std::string& filePath);
    void writeBytes(std::vector<int> &bytes, const std::string& filePath);
};