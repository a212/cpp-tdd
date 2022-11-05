#include <string>

class Soundex {
public:
	std::string encode(const std::string& word) const;
private:
	static size_t constexpr MaxCodeLength = 4;
	std::string head(const std::string& word) const;
	std::string encodedDigits(const std::string& word) const;
	std::string encodeDigit(char letter) const;
	std::string zeroPad(const std::string& word) const;
};
