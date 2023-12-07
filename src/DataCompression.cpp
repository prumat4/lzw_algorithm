#include "DataCompression.hpp"

BinaryFileManager::BinaryFileManager(const std::string &filePath) noexcept { 
    this->filePath = filePath;
}

size_t BinaryFileManager::getNumberOfBytes(size_t size) const noexcept {
    if(size % 8 == 0)
        return size / 8;
    
    return (size / 8) + 1;
}

void BinaryFileManager::isValidFile(const std::fstream &file) const {
    if(!file) {
        std::runtime_error error("Error opening file!");
        throw(error);
    }
}

std::vector<char> BinaryFileManager::ReadBitSequence(size_t size) {
    std::fstream inputFile;
    inputFile.open(filePath, std::ios::in | std::ios::binary);
    isValidFile(inputFile);

    size_t sizeInBytes = getNumberOfBytes(size);
    std::vector<char> bytes(sizeInBytes);
    inputFile.read(bytes.data(), sizeInBytes);

    inputFile.close();
    return bytes;
}

void BinaryFileManager::WriteBitSequence(const std::vector<char> &bits) {
    std::fstream outputFile;
    outputFile.open(filePath, std::ios::out | std::ios::binary);
    isValidFile(outputFile);

    outputFile.write(bits.data(), bits.size());
    
    outputFile.close();
}