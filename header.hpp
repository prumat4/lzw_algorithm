#include <iostream>
#include <fstream>
#include <bitset>

class BinaryFileManager {
private:
    std::fstream inputFile;
    std::fstream outputFile;
private:

public:
    BinaryFileManager(const std::string &filePath) noexcept;
    ~BinaryFileManager() noexcept;

    std::string ReadBitSequence(size_t size) const noexcept;
    void WriteByte(const std::bitset<8>& bits) noexcept;
};