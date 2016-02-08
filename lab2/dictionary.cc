#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;


vector<string> find_trigrams(const string& word) {
    int nbrOfTrigrams=max(0,static_cast<int>(word.size())-2);
    vector<string> trigrams(nbrOfTrigrams);
    for(int i=0;i<nbrOfTrigrams;++i){
        trigrams[i]=word.substr(i,3);
    }
    sort(trigrams.begin(),trigrams.end());
    return trigrams;
}

Dictionary::Dictionary() : wordlist(25) {
    std::ifstream in("words.txt");
    std::string line, word, number;
    int NbrOfTrigrams;
    //wordlist=std::vector<std::vector<Word> >(25,std::vector<Word>);
    while(getline(in,line)){
        std::istringstream item(line);
        item >> word;
        item >> NbrOfTrigrams;
        std::vector<std::string> trigrams(NbrOfTrigrams);
        for(int i=0;i<NbrOfTrigrams;++i){
                item>>trigrams[i];
        
        //        std::cout<<trigrams[i]<<std::endl;
        }
        //std::cout<<word<<std::endl;
        if(NbrOfTrigrams<23){
            //Word temp = Word(word,trigrams);
            wordlist[NbrOfTrigrams+2].push_back(Word(word,trigrams));
        }
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
    add_trigram_suggestions(&suggestions, word);
    if(!suggestions.empty()){
        rank_suggestions(&suggestions, word);
        trim_suggestions(&suggestions);
	}
    return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>* suggestions, const string& word) const{

    int wordlistIndex=static_cast<int>(word.size());
    vector<string> trigrams=find_trigrams(word);
    int matches;
    for(int i=wordlistIndex-1; i<=wordlistIndex+1;++i) {
        for(auto temp =begin(wordlist[i]); temp !=end(wordlist[i]); ++temp) {
            matches = temp->get_matches(trigrams);
            if(matches*2>=(wordlistIndex-2)){
                suggestions->push_back(temp->get_word());
            }

        }
    }
}

void Dictionary::rank_suggestions(vector<string>* suggestions, const string& word) const {
    vector<pair<int,string> > pairsuggestions;
    int d[26][26];
    for(int i=1;i<26;++i){        
        d[i][0]=i;
        d[0][i]=i;
    }
    d[0][0]=0;
    int ifvalue;
    for(auto &i : *suggestions) {
        for(int index=1;index<=static_cast<int>(word.size());++index) {
            for(int j=1; j<=static_cast<int>(i.size());++j){
                if(word[index-1]==i[j-1]) {
                    ifvalue = d[index-1][j-1];
                } else {
                    ifvalue = d[index-1][j-1]+1;
                }
                d[index][j]=min(min(ifvalue,d[index-1][j]+1),d[index][j-1]+1);
            }
        }
        pairsuggestions.push_back(make_pair(d[static_cast<int>(word.size())][static_cast<int>(i.size())],i));
    } 
    sort(pairsuggestions.begin(),pairsuggestions.end());
    for(int j=0;j<static_cast<int>(suggestions->size());++j) {
        (*suggestions)[j] = pairsuggestions[j].second;
    }
}

void Dictionary::trim_suggestions(vector<string>* suggestions) const {
    suggestions->resize(5);
}


