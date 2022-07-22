#include "Extractor.h"


const static std::string BUFFER_FILENAME = "books/processed/buffer.txt";


Extractor::Extractor(const std::string bookPath) :
    bookPath{ bookPath }, preprocessor{}
{
    std::string baseFilename = "processed" + this->bookPath.filename();
    std::string bufferFilaname = "processed" + this->bookPath.filename();

    baseFile = FileWrapper{ baseFilename };
    bufferFile;
}

void Extractor::openFiles()
{
    baseFile.openFileForRead();
    bufferFile.openFileForWrite();

    assert(baseFile.getStatus() == FileWrapper::Status::OpenedForRead);
    assert(bufferFile.getStatus() == FileWrapper::Status::OpenedForWrite);
}

void Extractor::closeFiles()
{
    baseFile.closeFile();
    bufferFile.closeFile();

    assert(baseFile.getStatus() == FileWrapper::Status::NotOpened);
    assert(bufferFile.getStatus() == FileWrapper::Status::NotOpened);
}

void Extractor::printFile(FileWrapper& fileWrapper, std::size_t numberOfLines = SIZE_MAX)
{
    while (!fileWrapper.isEof() && numberOfLines > 0)
    {
        std::cout << fileWrapper.getNextLine() << "\n";
        numberOfLines--;
    }
}

void Extractor::removeRegex(const std::string& regex)
{
    while (!baseFile.isEof())
    {
        std::string line = baseFile.getNextLine();
        if (line.empty())
            bufferFile.writeLine("\n");

        std::string result = preprocessor.popRegex(line, regex);

        if (!result.empty())
            bufferFile.writeLine(result + "\n");
    }
    baseFile.resetFile();
}

void Extractor::removeNumbers()
{
    std::string regex = "[1234567890]+";
    removeRegex(regex);
}

void Extractor::removeWord(const std::string& word)
{
    removeRegex(word);
}

