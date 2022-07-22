#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

class FileWrapper
{
public:
	enum Status
	{
		OpenedForWrite = 1,
		OpenedForRead = 2,
		HasNoFilename = 0
	};

	FileWrapper() = delete;
	FileWrapper(const FileWrapper& other) = delete;
	FileWrapper& operator=(const FileWrapper& other) = delete;

	FileWrapper(
		const std::string& filename, 
		FileWrapper::Status status = FileWrapper::Status::OpenedForRead
	);

	void resetFile();

	std::string getNextLine();
	void writeLine(const std::string& nextLine, bool flush = true);

	bool isEof();
	bool isEof() const;

	std::string getPath();
	std::string getPath() const;

	Status getStatus();
	Status getStatus() const;

private:
	std::string path;
	std::fstream file;

	Status status;
};