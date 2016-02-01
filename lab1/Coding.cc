#include "Coding.h"

unsigned char Coding::encode(unsigned char c){
    return (c+37-32)%(126-32)+32;
}

unsigned char Coding::decode(unsigned char c){
    char decC=c-37;
    if(decC<32){
        decC=126-(32-decC);
    }    
    return decC;
    //return (c-37)%(126);
}
