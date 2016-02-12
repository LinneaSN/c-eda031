#include <string>
#include "primes.h"
#include <iostream>

using namespace std;

Primes::Primes(int ilength) : length(ilength) {
    isPrimes.insert(isPrimes.size(),length,'P');
    isPrimes[0]=isPrimes[1]='C';

}


void Primes::findPrimes(){
    for(int i=2;i<length/2;++i){
        if(isPrimes[i]=='P'){
            for(int j=i+1;j<length;++j){
                if(isPrimes[j]=='P' and j%i==0){
                    isPrimes[j]='C';
                }
            }
        }
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

