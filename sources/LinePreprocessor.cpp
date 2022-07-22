#include "LinePreprocessor.h"


std::string LinePreprocessor::popRegex(const std::string& line, const std::string& regex)
{
	std::string result; 
	std::regex_replace(std::back_inserter(result), line.begin(), line.end(), std::regex(regex), "");
	return result;
}

std::string LinePreprocessor::popRegex(const std::string& line, const std::regex& regex)
{
	std::string result;
	std::regex_replace(std::back_inserter(result), line.begin(), line.end(), std::regex(regex), "");
	return result;
}

std::string LinePreprocessor::popRegex(const std::string& line, const std::string& regex) const
{
	std::string result;
	std::regex_replace(std::back_inserter(result), line.begin(), line.end(), std::regex(regex), "");
	return result;
}

std::string LinePreprocessor::popRegex(const std::string& line, const std::regex& regex) const
{
	std::string result;
	std::regex_replace(std::back_inserter(result), line.begin(), line.end(), std::regex(regex), "");
	return result;
}