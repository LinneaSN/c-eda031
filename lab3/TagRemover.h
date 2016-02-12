#include <iostream>
#include <string>
#include <map>

class TagRemover{
    public:
        TagRemover(std::istream& input);
        void print(std::ostream& output);
    private:
        std::string HTML;
        std::map<std::string, char> table;
};
