#include <string>

class Soundex {
public:
	std::string encode(const std::string& word) const;
private:
	static size_t constexpr MaxCodeLength = 4;
	std::string head(const std::string& word) const;
	std::string tail(const std::string& word) const;
	bool isComplete(const std::string& word) const;
	std::string upperFront(const std::string& word) const;
	char lower(char c) const;
	const std::string NotADigit {"*"};
	std::string encodedDigits(const std::string& word) const;
	void encodeHead(std::string& encoding, const std::string& word) const;
	void encodeTail(std::string& encoding, const std::string& word) const;
	void encodeLetter(std::string& encoding, char letter, char lastLetter) const;
	bool isVowel(char letter) const;
	std::string lastDigit(const std::string& word) const;
	std::string encodeDigit(char letter) const;
	std::string zeroPad(const std::string& word) const;
};
