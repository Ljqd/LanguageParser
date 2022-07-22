#pragma once

#include <string>
#include <regex>
#include <algorithm>


class LinePreprocessor
{
public:
	LinePreprocessor() = default;
	LinePreprocessor(const LinePreprocessor& other) = default;
	LinePreprocessor& operator=(const LinePreprocessor& other) = default;

	void popWord(std::string& line, const std::string word);
	void toLower(std::string& line);
	void removeNumbers(std::string& line);

private:
	void regexReplace(std::string& original, const std::string& regex, std::string format);
};