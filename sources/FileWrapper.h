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
		NotOpened = 0
	};

	FileWrapper() = delete;
	FileWrapper(const FileWrapper& other) = delete;
	FileWrapper& operator=(const FileWrapper& other) = delete;

	FileWrapper(const std::string& filename);

	Status getStatus();

	void openFileForRead();
	void openFileForWrite();

	void closeFile();
	void resetFile();

	bool isFileOpened();
	bool isEof();

	std::string getFilename();
	void updateFilename(const std::string& newFilename);

	std::string getNextLine();
	void writeLine(const std::string& nextLine, bool flush = true);

private:
	std::string filename;
	std::fstream file;

	Status status;
};