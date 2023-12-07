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
public:
    BinaryFileManager(const std::string &filePath) noexcept;

    std::vector<char> ReadBitSequence(size_t size);    
    void WriteBitSequence(const std::vector<char> &bits);
};