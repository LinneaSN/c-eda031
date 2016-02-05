#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;


Dictionary::Dictionary() {
    std::ifstream in("words.txt");
    std::string line, word;
    while(getline(in,line)){
        std::istringstream item(line);
        item >> word;
        stringSet.insert(word);
    }
    in.close();
}

bool Dictionary::contains(const string& word) const {
    std::string lowercaseword = word;
    std::transform(lowercaseword.begin(),lowercaseword.end(),lowercaseword.begin(),::tolower);    
    return stringSet.find(lowercaseword)!=stringSet.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
