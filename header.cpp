#include "header.hpp"

BinaryFileManager::BinaryFileManager(const std::string &filePath) noexcept 
    : inputFile(filePath, std::ios::binary), outputFile(filePath, std::ios::binary) {
    if(!inputFile || !outputFile)
        std::cout << "Error while initializing the binary file '" << filePath << "'\n";
    else 
        std::cout << "File " << filePath << " succesfully initialized\n";
}

BinaryFileManager::~BinaryFileManager() noexcept {
    inputFile.close();
    std::cout << "Input file succesfully closed!\n";
}

std::string BinaryFileManager::ReadBitSequence(size_t size) const noexcept {
    // use put and write? or is it for write func? 
}