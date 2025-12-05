#pragma once
#include <iostream>
using namespace std;

struct Zombie
{
    int dangerLevel;
    string type;

    Zombie() {}
    Zombie(int d, string t) { dangerLevel = d; type = t; }

    bool operator<(const Zombie& other) const { return dangerLevel < other.dangerLevel; }
    bool operator>(const Zombie& other) const { return dangerLevel > other.dangerLevel; }
    bool operator==(const Zombie& other) const { return dangerLevel == other.dangerLevel; }

    friend ostream& operator<<(ostream& os, const Zombie& z)
    {
        os << z.dangerLevel; // default: danger level only
        return os;
    }
};
