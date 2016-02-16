#include <string>
#include "primes.h"
#include <iostream>

using namespace std;

Primes::Primes(unsigned int ilength) : length(ilength) {
    isPrimes.insert(isPrimes.size(),length,'P');
    isPrimes[0]=isPrimes[1]='C';

}


void Primes::findPrimes(){
    unsigned int t=isPrimes.find('P');
    unsigned int u;
    while(t<length/2){
        u=isPrimes.find('P',t+1);
        while(u<length){
            if(u%t==0){
                isPrimes[u]='C';
            }
            u=isPrimes.find('P',u+1);
        }
        t=isPrimes.find('P',t+1);
    }
}

void Primes::print(int upper){
    for(int i=2;i<=upper;++i) {
        if(isPrimes[i]=='P') {
            cout<<i<<endl;
        }
    }
}

void Primes::printlargest() {
    cout<<"The largest prime number less than or equal to "<<length<<" is: "<<isPrimes.rfind('P')<<endl;

}

