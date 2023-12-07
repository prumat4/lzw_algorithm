#include <iostream>
#include <fstream>

class BinaryFileManager {
private:
    std::ifstream inputFile;
    std::ofstream outputFile;
private:

public:
    BinaryFileManager(const std::string &filePath) noexcept;
    ~BinaryFileManager() noexcept;

    std::string ReadBitSequence(size_t size) const noexcept;
};