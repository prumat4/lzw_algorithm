#include "ZivLempelAlgorithm.hpp"

int main() {
    BinaryFileManager man("../file.dat");
    std::vector<char> b = {static_cast<char>(0b10000111)};
    std::bitset<9> bits{"11101110"};
    man.writeBitSequence(bits);

    auto r = man.readBitSequence(320);

    for(auto a : r )
        std::cout << static_cast<int>(static_cast<unsigned char>(a)) << " ";

    return 0;
}