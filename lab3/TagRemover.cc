#include <iostream>
#include <string>
#include <map>
#include "TagRemover.h"
#include <iterator>

using namespace std;

TagRemover::TagRemover(istream& input){
    //table={{ "lt",'<'} , {"gt",'>'} , {"nbsp",' '} ,{"amp",'&'}};
    //char ch;
    //bool write = true;
    //bool specialChar=false;
    //string specialString;
    input>> noskipws;
    istream_iterator<char> it(input);
    istream_iterator<char> endit;
    HTML(it,endit);

    cout<<HTML<<endl;
    
    int first,last,newline;
    first=HTML.find('<');
    last=HTML.find('>');

    while(first!=string::npos){
    	newline=HTML.find("\n");
    	if(newline<last and newline>first){
	    HTML.replace(first,last-first+1,"\n");
        } else {
            HTML.erase(first,last-first+1);
        }
        first=HTML.find('<');
        last=HTML.find('>');
    }
}
    /*first = HTML.find("&lt;");
    while(first!=string::npos){
        HTML.replace(first,4,"<");
	HTML.find("&lt;");   
    }

    first = HTML.find("&gt;");
    while(first!=string::npos){
        HTML.replace(first,4,">");
	HTML.find("&gt;");   
    }

    first = HTML.find("&nbsp;");
    while(first!=string::npos){
        HTML.replace(first,6," ");
	HTML.find("&nbsp;");   
    }

    first = HTML.find("&amp;");
    while(first!=string::npos){
        HTML.replace(first,5,"&");
	HTML.find("&amp;");   
    }*/


    



   /* while(input.get(ch)){
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
    }*/


void TagRemover::print(ostream& output){
    output<<HTML<<endl;
}
