#include <string>
#include "SHAKE.h"
#include "password.h"

Password::Password(std::string service, unsigned int min_length, unsigned int max_length, bool has_special_characters, std::string special_characters){
	this->service = service;
	this->min_length = min_length;
	this->max_length = max_length;
	this->has_special_characters = has_special_characters;
	this->special_characters = special_characters;
}

unsigned int Password::determineLength(){
	unsigned int diff_length = this->max_length - this->min_length;
	return (min_length + calculateStringSum()%(diff_length + 1))/2;
}

unsigned int Password::calculateStringSum(){
	unsigned int service_sum = 0;
	unsigned int pin_sum = 0;
	unsigned int salt_sum = 0;
	for(unsigned int i = 0; i < this->service.length(); ++i){
		service_sum += service[i];
	}
	for(unsigned int i = 0; i < pin.length(); ++i){
		pin_sum += pin[i];
	}
	for(unsigned int i = 0; i < salt.length(); ++i){
		salt_sum += salt[i];
	}
	return service_sum + pin_sum + salt_sum;
}

std::string Password::insertSpecialCharacters(std::string hash){
	unsigned int num_special_characters = hash.length()/SPECIAL_CHARACTER_DIVISOR;
	for(unsigned int i = 0; i < num_special_characters; ++i){
		hash[hash[i]%hash.length()] = special_characters[hash[i]%special_characters.length()];
	}
	return hash;
}

std::string Password::generateHash(){
	SHAKE256 shake;
	shake.update(pin.data(),pin.length());
	shake.update(salt.data(),salt.length());
	shake.update(service.data(),service.length());
	unsigned char* c_hash = new unsigned char[determineLength()];
	shake.extend(c_hash,determineLength());
  	
	std::string hash((char *)c_hash);
	delete c_hash;
	return hash;
}
