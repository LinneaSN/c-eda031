#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>

namespace stringcasting
{
    template <typename T>
    T string_cast(std::string s) {
        T type;
        std::istringstream temp(s);
        if(!(temp>>type)){
            throw new std::invalid_argument("Erronous type conversion: could not use >> operator");
        }
        return type;
    }
}
