# include "word.h"
# include <string>
# include <vector>
# include <iostream>

int main() {
    std::vector<std::string> t = {"and", "boo", "dbo","han", "ndb", "ook"};
    std::vector<std::string> trigram = {"and", "bag", "dba", "han","ndb"};
    std::string word = "handbag";
    Word ord = Word(word,trigram);
    std::string test1 = ord.get_word();
    unsigned int matches = ord.get_matches(t);
    std::cout<<"Ord: "<<test1<<", Matches: "<<matches<<std::endl;

    return 0;
}
