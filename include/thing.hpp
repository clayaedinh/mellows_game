#ifndef MELLOWS_THING_HPP
#define MELLOWS_THING_HPP

#include <string>

class Thing {
    private:
    std::string name;
    std::string description;

    public:
    std::string getName();
    std::string view();
};

#endif