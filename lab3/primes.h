#include <string>

class Primes{
    public:
        Primes(int ilength);
        void findPrimes();
        void print(int upper);
        void printlargest();
    private:
        std::string isPrimes;
        int length;
};
