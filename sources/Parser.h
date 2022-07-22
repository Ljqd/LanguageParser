#pragma once

#include <string>
#include <filesystem>

#include "FileWrapper.h"
#include "LinePreprocessor.h"
#include "Lemmatizer.h"


class Parser
{
private:
	void preprocess();

	void openBuffer();
	void closeBuffer(bool replaceBasefile = true);

public:
	Parser(std::string bookPath, bool toPrerocess = true);

	Parser() = delete;
	Parser(const Parser& other) = delete;
	Parser& operator=(const Parser& other) = delete;

	void parse();

private:
	std::filesystem::path originalBookPath;
	std::filesystem::path bufferPath;

	LinePreprocessor preprocessor;
	Lemmatizer lemmatizer;

	FileWrapper* baseFile;
	FileWrapper* bufferFile;
};

/*
void Extractor::printFile(FileWrapper& fileWrapper, std::size_t numberOfLines)
{
	while (!fileWrapper.isEof() && numberOfLines > 0)
	{
		std::cout << fileWrapper.getNextLine() << "\n";
		numberOfLines--;
	}
}
*/