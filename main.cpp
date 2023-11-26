#include "header.hpp"

int main() {
    BinaryFileManager man("file.dat");
    char s = 'g';
    int k = static_cast<int>(s);
    std::bitset<8> byte(k);
    man.WriteByte(byte);
    return 0;
}