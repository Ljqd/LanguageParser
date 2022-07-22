#pragma once

#include <string>
#include <regex>


class LinePreprocessor
{
public:
	LinePreprocessor() = default;
	LinePreprocessor(const LinePreprocessor& other) = default;
	LinePreprocessor& operator=(const LinePreprocessor& other) = default;

	std::string popRegex(const std::string& line, const std::string& word);
	std::string popRegex(const std::string& line, const std::regex& regex);

	std::string popRegex(const std::string& line, const std::string& word) const;
	std::string popRegex(const std::string& line, const std::regex& regex) const;

	// static std::string popRegex(const std::string& line, const std::string& word);
	// static std::string popRegex(const std::string& line, const std::regex& regex);
};