#include <iostream>
#include <string>
#include <cassert>
#include <filesystem>

#include "sources/FileWrapper.h"
#include "sources/LinePreprocessor.h"

std::string getWord()
{
    std::string word;
    std::cout << "Enter word/regex to remove: ";
    std::cin >> word;
    std::cout << std::endl;
    return word;
}


int main()
{
    // 0 - Init stage
    LinePreprocessor preprocessor = {};

    std::string iFilename = "books/processed/Book 1 - The Philosopher's Stone.txt";

    FileWrapper iFileWrapper(iFilename);
    FileWrapper bufferFileWrapper(BUFFER_FILENAME);
    
    // 1
    printFile(iFileWrapper, 100);
    iFileWrapper.resetFile();

    // 2
    openFiles(iFileWrapper, bufferFileWrapper);
    removeNumbers(iFileWrapper, bufferFileWrapper, preprocessor);
    closeFiles(iFileWrapper, bufferFileWrapper);
    saveBuffer(iFilename);

    // 3
    std::string word = getWord();
    openFiles(iFileWrapper, bufferFileWrapper);
    removeWord(iFileWrapper, bufferFileWrapper, preprocessor, word);
    closeFiles(iFileWrapper, bufferFileWrapper);
    saveBuffer(iFilename);
}
