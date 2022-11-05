#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test {
public:
	Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
	auto encoded = soundex.encode("A");
	ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
	auto encoded = soundex.encode("I");
	ASSERT_THAT(encoded, Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
	ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics) {
	ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

