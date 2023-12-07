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
    std::fstream inputFile(filePath, std::ios::in | std::ios::binary);
    isValidFile(inputFile);

    size_t sizeInBytes = getNumberOfBytes(size);
    std::vector<char> bytes(sizeInBytes);
    inputFile.read(bytes.data(), sizeInBytes);
    inputFile.close();

    return bytes;
}

// WriteBitSequence():
// в тебе має бути функція яка просто бере послідновсність бітів і пише їх у файл бінарний
// як я це бачу:
// 1. зберігаємо цу як величезний бітсет?
// 2. біжимо по цьому бітсету і просто кожні 8 бітів пушимо в масив символів 
// 3. потім через write записуємо  у файл?

// які трабли:
// 1. як знайти розмір цього початково бітсету (як з ним працювати буде точніше формулювання)