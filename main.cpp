#include "DataCompression.hpp"

int main() {
    BinaryFileManager man("file.dat");
    auto r = man.ReadBitSequence(19);

    for(auto a : r )
        std::cout << static_cast<int>(static_cast<unsigned char>(a)) << " ";

    
    return 0;
}