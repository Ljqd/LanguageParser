#include "Parser.h"

namespace fs = std::filesystem;


Parser::Parser(std::string bookPath, bool toPrerocess)
{
	fs::path path(bookPath);
	fs::path basePath = "books/processed" / path.filename();
	
	if (!fs::exists(basePath))
		fs::copy_file(bookPath, basePath);

	// fs::path has operator+= but not operator+, lol
	bufferPath = "books/processed" / path.stem();
	bufferPath += "_buffer";
	bufferPath += path.extension();

	baseFile = new FileWrapper(basePath.string(), FileWrapper::Status::OpenedForRead);
	
	if (toPrerocess)
	{
		openBuffer();
		preprocess();
		closeBuffer();
	}
}


void Parser::openBuffer()
{
	bufferFile = new FileWrapper(bufferPath.string(), FileWrapper::Status::OpenedForWrite);
}

void Parser::closeBuffer(bool replaceBasefile)
{
	delete baseFile;
	delete bufferFile;

	baseFile = nullptr;


	bufferFile = nullptr;

	fs::remove(baseFile->getPath());
	fs::copy_file(baseFile->getPath(), bufferFile->getPath());

	
	fs::remove(bufferPath);
}

void Parser::preprocess()
{
	while (!baseFile->isEof())
	{
		std::string line = baseFile->getNextLine();
		bool emptyLine = line.empty();
	
		if (!line.empty())
			preprocessor.removeNumbers(line);

		if (!line.empty())
			preprocessor.toLower(line);

		bool toSkipLine = line.empty() && emptyLine == false;
		
		if (!toSkipLine)
			bufferFile->writeLine(line + "\n");
	}
}

void Parser::parse()
{

}