#include "FileWrapper.h"


FileWrapper::FileWrapper(const std::string& filename, FileWrapper::Status status) :
	path{ filename }, status{ status }
{
	if (status == Status::OpenedForRead)
		file.open(filename, std::fstream::in);
	else if (status == Status::OpenedForWrite)
		file.open(filename, std::fstream::out);
	
	bool a = file.is_open();
	assert(file.is_open());
}

void FileWrapper::resetFile()
{
	file.seekg(0, std::ios::beg);
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

FileWrapper::Status FileWrapper::getStatus()
{
	return status;
}

FileWrapper::Status FileWrapper::getStatus() const
{
	return status;
}

bool FileWrapper::isEof()
{
	return file.eof();
}

bool FileWrapper::isEof() const
{
	return file.eof();
}

std::string FileWrapper::getPath()
{
	return path;
}

std::string FileWrapper::getPath() const
{
	return path;
}