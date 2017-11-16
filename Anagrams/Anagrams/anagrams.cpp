// Anagrams
// Bradley Marques
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::sort;
using std::string;
bool anagram_test(string input_str_1, string input_str_2);
string formatter(string);
void main() {
	ifstream fin("anagrams.in");
	if (fin.is_open()) {
		ofstream fout("anagrams.out");
		bool is_anagram = false;
		string str1 = "";
		string str2 = "";

		while (str1 != "<end>" && str2 != "<end>") {
			getline(fin, str1);
			getline(fin, str2);
			if (str1 != "<end>" || str2 != "<end>") {
				str1 = formatter(str1);
				str2 = formatter(str2);
				is_anagram = anagram_test(str1, str2);
				if (is_anagram) {
					fout << "YES" << endl;
				}
				else {
					fout << "NO" << endl;
				}
			}
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}
// Returns true if both input strings, when sorted,
// are equal to each other. The assumption is
// that if the two strings, when sorted, contain the
// same characters then the two strings must be anagrams of each other.
bool anagram_test(string input_str_1, string input_str_2)
{
	sort(input_str_1.begin(), input_str_1.end());
	sort(input_str_2.begin(), input_str_2.end());
	return input_str_1 == input_str_2;
}
// The following function formats a string so that
// when the string is ready to be compared to another
// only the characters are being compared.
string formatter(string input_str) {
	// This loop makes all characters in the string lowercase.
	unsigned int len = input_str.length();
	for (unsigned int i = 0; i < len; i++) {
		input_str[i] = tolower(input_str[i]);
	}
	// This loop erases all non-alpha characters.
	unsigned int j = 0;
	while (j < len) {
		if (!isalpha(input_str[j])) {
			input_str.erase(j, 1);
			len--;
		}
		else {
			j++;
		}
	}
	return input_str;
}


