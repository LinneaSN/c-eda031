#include "Coding.h"
#include <fstream>
#include <iostream>



int main(){

    std::ifstream in("infile");
    std::ofstream out;
    out.open("file.enc.txt");
    char ch;
    while(in.get(ch)){
        ch=Coding::encode(ch);
        out<<ch;
    }
    out.close();
    in.close();
    return 0;
}
