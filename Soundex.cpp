#include "Soundex.h"
#include <unordered_map>

std::string Soundex::encode(const std::string& word) const {
	return zeroPad(upperFront(head(word))+encodedDigits(tail(word)));
}

std::string Soundex::head(const std::string& word) const {
	return word.substr(0, 1);
}

std::string Soundex::tail(const std::string& word) const {
	return word.substr(1);
}

bool Soundex::isComplete(const std::string& word) const {
	return word.length() == MaxCodeLength - 1;
}

std::string Soundex::upperFront(const std::string& word) const {
	return std::string(1, std::toupper(static_cast<unsigned char>(word.front())));
}

char Soundex::lower(char c) const {
	return std::tolower(static_cast<unsigned char>(c));
}

std::string Soundex::encodedDigits(const std::string& word) const {
	std::string encoding;
	for (auto letter : word) {
		if (isComplete(encoding)) break;
		auto digit = encodeDigit(letter);
		if (digit != NotADigit && digit != lastDigit(encoding))
		encoding += digit;
	}
	return encoding;
}

std::string Soundex::lastDigit(const std::string& word) const {
	if (word.empty()) return "";
	return std::string(1, word.back());
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
	auto res = encodings.find(lower(letter));
	if (res == encodings.end()) return NotADigit;
	return res->second;
}

std::string Soundex::zeroPad(const std::string& word) const {
	auto zerosNeeded = MaxCodeLength - word.length();
	return word + std::string(zerosNeeded, '0');
}
