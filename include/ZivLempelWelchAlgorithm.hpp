#pragma once

#include "BinaryFileManager.hpp"
#include <map>

class LZW {
public:
    void encode(size_t fileSizeInBytes, const std::string& filePath);    
    void decode(size_t fileSizeInBytes, const std::string& filePath);
private:

};


void LZW::encode(size_t fileSizeInBytes, const std::string& filePath) {
    BinaryFileManager manager;
    auto inputData = manager.readBitSequence(8 * fileSizeInBytes, filePath);
    
    std::vector<int> compressed;
    auto resultIterator = compressed.begin();

    int dictSize = 256;
    std::map<std::string, int> dictionary;
    for(int i = 0; i < dictSize; i++)
        dictionary[std::string(1, i)] = i;

    std::string w;

    for(auto it = inputData.begin(); it != inputData.end(); ++it){
        std::string wc = w + *it;

        if(dictionary.count(wc))
            w = wc;
        else {
            compressed.push_back(dictionary[w]);
            dictionary[wc] = dictSize++;
            w = std::string(1, *it);
        }
    }

    if(!w.empty())
        compressed.push_back(dictionary[w]);

    std::string compressedFilePath = filePath.substr(0, filePath.find_last_of('.'));
    compressedFilePath += "_compressed.bin";

    manager.writeBytes(compressed, compressedFilePath);
}

void LZW::decode(size_t fileSizeInBytes, const std::string& filePath) {

}