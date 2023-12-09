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
    // auto / = inputData.begin(); // mb inputData.begin()?

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
    BinaryFileManager manager;
    auto inputData = manager.readBitSequence(8 * fileSizeInBytes, filePath);
    
    std::vector<char> decoded;
    auto it = inputData.begin();

    int dictSize = 256;
    std::map<int, std::string> dictionary;
    for (int i = 0; i < dictSize; ++i)
        dictionary[i] = std::string(1, i);

    std::string w(1, *it++);
    decoded.push_back(w[0]);

    for (; it != inputData.end(); ++it) {
        int k = *it;

        std::string entry;
        if (dictionary.count(k)) {
            entry = dictionary[k];
        } else if (k == dictSize) {
            entry = w + w[0];
        }

        // Output the entry to the decoded vector
        for (char c : entry) {
            decoded.push_back(c);
        }

        // Update the dictionary
        dictionary[dictSize++] = w + entry[0];

        w = entry;
    }

    std::string decompressedFilePath = filePath.substr(0, filePath.find_last_of('.'));
    decompressedFilePath += "_decompressed.bin";

    manager.writeBytes(decoded, decompressedFilePath);
}