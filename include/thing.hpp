#ifndef MELLOWS_THING_HPP
#define MELLOWS_THING_HPP

#include <string>
using namespace std;

class Thing {
    private:
    string name;
    string description;

    public:
    string getName();
    string view();
};

#endif