#include "primes.h"
int main(){
    int length=100000;
    Primes prime(length);
    prime.findPrimes();
    prime.print(200);
    prime.printlargest();
    return 0;
}
