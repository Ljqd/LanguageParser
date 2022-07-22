#include "FileWrapper.h"


FileWrapper::FileWrapper(const std::string& filename) :
	file{}, filename{ filename }, status{ Status::NotOpened }
{}

FileWrapper::Status FileWrapper::getStatus()
{
	return status;
}

void FileWrapper::openFileForRead()
{
	if (file.is_open())
		file.close();
	file.open(filename, std::fstream::in);
	if (file.is_open())
		status = Status::OpenedForRead;
}

void FileWrapper::openFileForWrite()
{
	if (file.is_open())
		file.close();
	file.open(filename, std::fstream::out);
	if (file.is_open())
		status = Status::OpenedForWrite;
}

void FileWrapper::closeFile()
{
	file.close();
	status = Status::NotOpened;
}

void FileWrapper::resetFile()
{
	file.seekg(0, std::ios::beg);
}

bool FileWrapper::isFileOpened()
{
	bool isOpen = file.is_open();
	assert(
		(isOpen == true  && status != Status::NotOpened) ||
		(isOpen == false && status == Status::NotOpened)
	);
	return isOpen;
}

bool FileWrapper::isEof()
{
	return file.eof();
}

std::string FileWrapper::getFilename()
{
	return filename;
}

void FileWrapper::updateFilename(const std::string& newFilename)
{
	closeFile();
	filename = newFilename;
}

std::string FileWrapper::getNextLine()
{
	std::string line;
	std::getline(file, line);
	return line;
}

void FileWrapper::writeLine(const std::string& nextLine, bool flush)
{
	if (status == Status::OpenedForWrite)
	{
		file << nextLine;
		if (flush)
			file.flush();
	}
}