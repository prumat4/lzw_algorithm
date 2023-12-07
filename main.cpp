#include "DataCompression.hpp"

int main() {
    BinaryFileManager man("../file.dat");
    std::vector<char> b = {'a', 'b', 'c', 'p'};
    man.WriteBitSequence(b);
    man.WriteBitSequence(b);


    auto r = man.ReadBitSequence(320);

    for(auto a : r )
        std::cout << static_cast<int>(static_cast<unsigned char>(a)) << " ";

    
    return 0;
}