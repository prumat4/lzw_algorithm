#include "ZivLempelWelchAlgorithm.hpp"

int main() {
    // BinaryFileManager man("../file.bin");
    // auto uncompressed = man.readBitSequence(2*8);

    // for(auto a : uncompressed)
    //     std::cout << a;

    // std::vector<char> u = { char(187165), char(1837165)};
    // man.writeBytes(u);

    LZW first;
    first.encode(5294, "../file.bin");
    first.decode(1173, "../file_compressed.bin");

    return 0;
}