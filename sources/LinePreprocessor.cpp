#include "LinePreprocessor.h"

void LinePreprocessor::popWord(std::string& line, const std::string word)
{
	regexReplace(line, word, "");
}

void LinePreprocessor::toLower(std::string& line)
{
	std::transform(line.begin(), line.end(), line.begin(),
		[](unsigned char c) { return std::tolower(c); });
}

void LinePreprocessor::removeNumbers(std::string& line)
{
	std::string regex = "[1234567890]+";
	regexReplace(line, regex, "");
}

void LinePreprocessor::regexReplace(std::string& original, const std::string& regex, std::string format)
{
	std::regex_replace(original, std::regex(regex), format);
}


/*
std::string LinePreprocessor::popWord(const std::string& line, const std::string word)
{
	return regexReplace(line, word, "");
}

std::string LinePreprocessor::toLower(const std::string& line)
{
	std::string result(line.length(), '\x00');
	for (std::size_t i = 0; i < line.length(); ++i)
	{
		result[i] = std::tolower(line[i]);
	}
	return result;
}

std::string LinePreprocessor::removeNumbers(const std::string line)
{
	std::string regex = "[1234567890]+";
	return regexReplace(line, regex, "");
}

std::string LinePreprocessor::regexReplace(const std::string& original, const std::string& regex, std::string format)
{
	std::string result;
	std::regex_replace(std::back_inserter(result), original.begin(), original.end(), std::regex(regex), format);
	return result;
}
*/