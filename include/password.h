#include <string>

extern std::string salt;
extern std::string pin;
const unsigned int SPECIAL_CHARACTER_DIVISOR = 5;
class Password{
	public:
		Password(std::string service, unsigned int min_length, unsigned int max_length,bool has_special_characters, std::string special_characters);
		std::string generateHash();

	private:
		std::string service;
		unsigned int min_length;
		unsigned int max_length;
		bool has_special_characters;
		std::string special_characters;

		unsigned int determineLength();
		unsigned int calculateStringSum();
		std::string encodeHex(const unsigned char* hash);
		std::string insertSpecialCharacters(std::string hash);
};
