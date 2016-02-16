#include <iostream>
#include <string>
#include <map>
#include "TagRemover.h"
#include <iterator>

using namespace std;

TagRemover::TagRemover(istream& input){
    string temp;
    while(getline(input,temp)){
        HTML.append(temp);
        HTML.append(1,'\n');
    }
    
    string::size_type first,last,newline;
    first=HTML.find('<');
    last=HTML.find('>');
    int nbrOfNewLines;

    while(first!=string::npos){
    	newline=HTML.find('\n',first);
        nbrOfNewLines=0;
    	while(newline<last and newline>first){
            ++nbrOfNewLines;
            newline=HTML.find('\n',newline+1);
        }
        HTML.erase(first,last-first+1);
        HTML.insert(first,nbrOfNewLines,'\n');


        first=HTML.find('<');
        last=HTML.find('>');
    }

    first = HTML.find("&lt;");
    while(first!=string::npos){
        HTML.replace(first,4,"<");
	    first=HTML.find("&lt;");   
    }

    first = HTML.find("&gt;");
    while(first!=string::npos){
        HTML.replace(first,4,">");
	    first=HTML.find("&gt;");   
    }

    first = HTML.find("&nbsp;");
    while(first!=string::npos){
        HTML.replace(first,6," ");
	    first=HTML.find("&nbsp;");   
    }

    first = HTML.find("&amp;");
    while(first!=string::npos){
        HTML.replace(first,5,"&");
	    first= HTML.find("&amp;");   
    }

}

void TagRemover::print(ostream& output){
    output<<HTML<<endl;
}
