#pragma once

#include <string>
#include <cassert>
#include <filesystem>

#include "FileWrapper.h"
#include "LinePreprocessor.h"

class Extractor
{
private:
    void openFiles();
    void closeFiles();

    void printFile(FileWrapper& fileWrapper, std::size_t numberOfLines = SIZE_MAX);

    void removeRegex(const std::string& regex);
    void removeNumbers();
    void removeWord(const std::string& word);

public:
	Extractor(const std::string bookPath);

    Extractor() = delete; // FileWrapper has no default constructor
	Extractor(const Extractor& other) = delete;
	Extractor& operator=(const Extractor& other) = delete;

    void printBaseBook(std::size_t numberOfLines = SIZE_MAX);
    void printProcessedBook(std::size_t numberOfLines = SIZE_MAX);

private:
    FileWrapper baseFile;
    FileWrapper bufferFile;

    LinePreprocessor preprocessor;

    std::filesystem::path bookPath;
};