#include "dictionary.h"
#include <iostream>

int main(){

    Dictionary *dict= new Dictionary();
    bool test1=dict->contains("ABBAs");
    bool test2=dict->contains("ahubabuba");
    delete dict;
    std::cout<<"ok!"<<std::endl;
    std::cout<<"status test1: "<<test1<<" , status test 2 "<<test2<<std::endl;
    return 0;
}
