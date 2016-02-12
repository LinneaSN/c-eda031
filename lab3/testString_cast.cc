#include <string>
#include "string_cast.h"
#include <iostream>
#include <stdexcept>
#include "date.h"

using namespace std;
using namespace stringcasting;

int main(){
    try{
        int i = string_cast<int>("123");
        cout<< "Successfully converted from string to int: "<<i<<endl;
        double d = string_cast<double>("12.34");
        cout<< "Successfully converted from string to double: "<<d<<endl;
        Date date = string_cast<Date>("2015-01-10");
        cout<< "Successfully converted from string to Date: "<<date<<endl;
    } catch(std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }


    return 0;
}


