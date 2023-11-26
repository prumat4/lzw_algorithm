#include "header.hpp"

int main() {
    BinaryFileManager man("file.dat");
    char s = 'g';
    int k = static_cast<int>(s);
    std::bitset<8> byte(k);
    std::cout << byte << std::endl;
    man.WriteByte(byte);
    std::bitset<8> byte2(k + 1);

    man.WriteByte(byte2);

    std::cout << man.ReadByte() << std::endl;
    std::cout << man.ReadByte();

    return 0;
}