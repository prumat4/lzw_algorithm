#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

class BinaryFileManager {
private:
    std::fstream inputFile;
    std::fstream outputFile;
private:

public:
    BinaryFileManager(const std::string &filePath) noexcept;
    ~BinaryFileManager() noexcept;
    
    std::bitset<8> ReadByte() noexcept;
    std::vector<std::bitset<8>> ReadBitSequence(size_t size) noexcept;

    void WriteByte(const std::bitset<8>& bits) noexcept;
    // void WriteBitSequence(const std::bitset<>& bits) noexcept;
};