#pragma once

#include <string>


class Lemmatizer
{
public:
	Lemmatizer() = default;
	Lemmatizer(const Lemmatizer& other) = default;
	Lemmatizer& operator=(const Lemmatizer& other) = default;

	std::string lemmatize(std::string word) {};
};