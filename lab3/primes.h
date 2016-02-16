#include <string>

class Primes{
    public:
        Primes(unsigned int ilength);
        void findPrimes();
        void print(int upper);
        void printlargest();
    private:
        std::string isPrimes;
        unsigned int length;
};
