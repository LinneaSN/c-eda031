#ifndef TOSTRING_H
#include <string>
#include <sstream>

namespace tostring
{
    template <typename T>
    std::string toString(const T& type){
        std::ostringstream temp;
        temp<<type;
        return temp.str();
    }
}

#endif
