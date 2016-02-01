#include "Coding.h"
#include <fstream>
#include <iostream>

int main(){
    
    std::ifstream in("file.enc.txt");
    std::ofstream out;
    out.open("file.dec.txt");
    char ch;
    while(in.get(ch)){
        ch=Coding::decode(ch);
        out<<ch;
    }
    out.close();
    in.close();
    return 0;
}
