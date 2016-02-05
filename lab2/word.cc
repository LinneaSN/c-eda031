#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int matches, latest;
    matches=latest=0;
    int trisize = trigrams.size();
    for(std::string s : t){
        for(int i = latest; i<trisize;++i){
            if(s==trigrams[i]){
                ++matches;
                latest=i;
                break;
            }
        }
    }
    return matches;
}
