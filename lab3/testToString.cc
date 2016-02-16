//#include "toString.h" 
#include <string>
#include <iostream>
#include "date.h"
#include <sstream>
#include "toString.h"
using namespace std;
using namespace tostring;


int main(){
    double d=1.234;
    Date today;
    string sd=/*tostring::*/toString(d);
    string st=/*tostring::*/toString(today);
  
    cout<<"A number converted to string: "<<sd<<endl;
    cout<<"A date converted to string: "<<st<<endl;
    
    return 0;
}
