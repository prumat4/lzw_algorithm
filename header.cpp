#include "header.hpp"

BinaryFileManager::BinaryFileManager(const std::string &filePath) noexcept 
    : inputFile(filePath, std::ios::in | std::ios::binary), outputFile(filePath, std::ios::out | std::ios::binary) {
    if(!inputFile || !outputFile)
        std::cout << "Error while initializing the binary file '" << filePath << "'\n";
    else 
        std::cout << "File " << filePath << " succesfully initialized\n";
}

BinaryFileManager::~BinaryFileManager() noexcept {
    inputFile.close();
    std::cout << "Input file succesfully closed!\n";
}

void BinaryFileManager::WriteByte(const std::bitset<8>& bits) noexcept {
    uint8_t byte = bits.to_ulong();
    outputFile.write(reinterpret_cast<char*>(&byte), sizeof(uint8_t));
}

std::bitset<8> BinaryFileManager::ReadByte() noexcept {
    uint8_t byte {0};
    inputFile.read(reinterpret_cast<char*>(&byte), sizeof(uint8_t));
    std::bitset<8> ans(byte);
    return ans; 
}

std::vector<std::bitset<8>> BinaryFileManager::ReadBitSequence(size_t size) noexcept {
    std::vector<std::bitset<8>> bytes;

    while (size > 0) {
        std::bitset<8> bits;
        uint8_t byte {0};

        inputFile.read(reinterpret_cast<char*>(&byte), sizeof(uint8_t));

        bits = byte;
        bytes.push_back(bits);

        size--;
    }

    return bytes;
}
