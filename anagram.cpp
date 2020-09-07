#include "anagram.h"

int charToInt(const char x) {
	if (x < 'a')
		return x - 'A';
	else
		return x - 'a';
}

bool validateHash(int* hash) {
	for (int i = 0; i < 26; i++) {
		if (hash[i] != 0)
			return false;
	}
	return true;
}

void fillHash(int* hash, const std::string& word) {

	for (unsigned int i = 0; i < word.size(); i++) {
		if (word[i] != ' ') {
			hash[charToInt(word[i])] += 1;
		}
	}
}

void matchHash(int* hash, const std::string& word) {
	for (unsigned int i = 0; i < word.size(); i++) {
		if (word[i] != ' ') {
			hash[charToInt(word[i])] -= 1;
		}
	}
}

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {

	int word1_length = word1.size();
	int word2_length = word2.size();

	int charHash[26] = { 0 };
	fillHash(charHash, word1);
	matchHash(charHash, word2);

	return validateHash(charHash);
}

std::vector<std::string> Anagram::SelectAnagrams(
        const std::string& word,
        const std::vector<std::string>& candidates) {
	
	std::vector<std::string>matchingAnagrams = {};

	for (auto itr = candidates.begin(); itr != candidates.end(); itr++) {
		if (Anagram::WordPairIsAnagram(word, *itr))
			matchingAnagrams.push_back(*itr);
	}

    return matchingAnagrams;
}
