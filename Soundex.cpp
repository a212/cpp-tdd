#include "Soundex.h"
#include <unordered_map>

std::string Soundex::encode(const std::string& word) const {
	return zeroPad(head(word)+encodedDigits(word));
}

std::string Soundex::head(const std::string& word) const {
	return word.substr(0, 1);
}

std::string Soundex::encodedDigits(const std::string& word) const {
	std::string res;
	for (size_t i = 1; i < word.length(); i++) {
		res += encodeDigit(word[i]);
	}
	return res;
}

std::string Soundex::encodeDigit(char letter) const {
	std::unordered_map<char, std::string> encodings = {
		{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
		{'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
		{'d', "3"}, {'t', "3"},
		{'l', "4"},
		{'m', "5"}, {'n', "5"},
		{'r', "6"},
	};
	auto res = encodings.find(letter);
	if (res == encodings.end()) return "";
	return res->second;
}

std::string Soundex::zeroPad(const std::string& word) const {
	auto zerosNeeded = MaxCodeLength - word.length();
	return word + std::string(zerosNeeded, '0');
}
