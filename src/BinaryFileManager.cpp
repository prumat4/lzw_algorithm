#include "BinaryFileManager.hpp"

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

std::vector<char> BinaryFileManager::readBitSequence(size_t size, const std::string& filePath) {
    std::fstream inputFile;
    inputFile.open(filePath, INPUT_FLAGS);
    isValidFile(inputFile);

    size_t sizeInBytes = getNumberOfBytes(size);
    std::vector<char> bytes(sizeInBytes);
    inputFile.read(bytes.data(), sizeInBytes);

    inputFile.close();
    return bytes;
}

void BinaryFileManager::writeBytes(std::vector<int> &bytes, const std::string& filePath) {
    std::fstream outputFile;
    outputFile.open(filePath, OUTPUT_FLAGS);
    isValidFile(outputFile);

    outputFile.write(reinterpret_cast<char*>(bytes.data()), bytes.size());
    
    outputFile.close();
}