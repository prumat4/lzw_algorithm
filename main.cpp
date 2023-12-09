#include "ZivLempelWelchAlgorithm.hpp"

int main() {
    LZW first;
    first.encode(5294, "../examples/file.bin");
    first.decode(1173, "../examples/file_compressed.bin");

    return 0;
}