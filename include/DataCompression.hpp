#pragma once

#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

#define INPUT_FLAGS std::ios::in | std::ios::binary | std::ios::app
#define OUTPUT_FLAGS std::ios::out | std::ios::binary | std::ios::app

class BinaryFileManager {
private:
    std::string filePath;

private:
    size_t getNumberOfBytes(size_t size) const noexcept;
    void isValidFile(const std::fstream& file) const;
    void writeBytes(const std::vector<char> &bytes);

public:
    BinaryFileManager(const std::string &filePath) noexcept;

    std::vector<char> readBitSequence(size_t size);

    template<size_t N>
    std::bitset<N> reverseBitset(const std::bitset<N>& input);

    template<size_t N>
    void writeBitSequence(const std::bitset<N> &bits);
};

template<size_t N>
std::bitset<N> BinaryFileManager::reverseBitset(const std::bitset<N>& input) {
    std::bitset<N> reversedBitset;
    for (size_t i = 0; i < N; ++i) {
        reversedBitset[i] = input[N - i - 1];
    }
    
    return reversedBitset;
}

template<size_t N>
void BinaryFileManager::writeBitSequence(const std::bitset<N> &bits) {
    auto revertedBitset = reverseBitset(bits);
    std::vector<char> bytes;
    size_t numBytes = N / 8;
 
    for (size_t i = 0; i < numBytes; i++) {
        char byte = 0;
        for (size_t j = 0; j < 8; j++) {
            byte |= (revertedBitset[i * 8 + j] << j);
        }
        bytes.push_back(byte);
    }
 
    size_t remainingBits = N % 8;
    if (remainingBits > 0) {
        char lastByte = 0;
        for (size_t i = 0; i < remainingBits; i++) {
            lastByte |= (revertedBitset[numBytes * 8 + i] << i);
        }
        bytes.push_back(lastByte);
    }
 
    writeBytes(bytes);
}