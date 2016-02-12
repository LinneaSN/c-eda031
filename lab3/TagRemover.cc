#include <iostream>
#include <string>
#include <map>
#include "TagRemover.h"

using namespace std;

TagRemover::TagRemover(istream& input){
    table={{ "lt",'<'} , {"gt",'>'} , {"nbsp",' '} ,{"amp",'&'}};
    char ch;
    bool write = true;
    bool specialChar=false;
    string specialString;
    while(input.get(ch)){
        if(ch=='<'){
            write = false;
        } else if(ch=='>'){
            write = true;
        } else if(ch=='&'){
            write =false;
            specialChar=true;
        }else if(specialChar){
            if(ch==';'){
                specialChar=false;
                write=true;
                HTML.push_back(table[specialString]);
                specialString.erase();
            } else {
                specialString.push_back(ch);
            }            
        } else if(ch=='\n' or write) {
            HTML.push_back(ch);
        }
    }
}

void TagRemover::print(ostream& output){
    output<<HTML<<endl;
}
