#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

class BinaryFileManager {
private:
    std::string filePath;
private:
    size_t getNumberOfBytes(size_t size) const noexcept;
    void isValidFile(const std::fstream& file) const;
public:
    BinaryFileManager(const std::string &filePath) noexcept;

    std::vector<char>  ReadBitSequence(size_t size);    
};