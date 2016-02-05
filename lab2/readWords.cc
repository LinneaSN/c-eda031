#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main(){
    std::ifstream in("/usr/share/dict/words");
    std::ofstream out;
    out.open("words.txt");
    std::string word;
    while(getline(in,word)){
        std::transform(word.begin(),word.end(),word.begin(), ::tolower);
        int nbrOfTrigrams=std::max(0,static_cast<int>(word.size())-2);
        std::vector<std::string> trigrams(nbrOfTrigrams);
        for(int i=0;i<nbrOfTrigrams;++i){
            trigrams[i]=word.substr(i,3);
        }
        sort(trigrams.begin(),trigrams.end());
        out<<word<<" "<<nbrOfTrigrams;
        for(int i=0;i<nbrOfTrigrams;++i){
            out<<" "<<trigrams[i];    
        }
        out<<std::endl;
    }
    out.close();
    in.close();  
    return 0;
}

