#pragma once
#include <iostream>
using namespace std;

struct Zombie
{
	// Data members
    int dangerLevel;
    string type;

	// Constructors
    Zombie() {}
    Zombie(int d, string t) { dangerLevel = d; type = t; }

	// Operator overloads
    bool operator<(const Zombie& other) const { return dangerLevel < other.dangerLevel; }
    bool operator>(const Zombie& other) const { return dangerLevel > other.dangerLevel; }
    bool operator==(const Zombie& other) const { return dangerLevel == other.dangerLevel; }

	// Output overload
    friend ostream& operator<<(ostream& os, const Zombie& z)
    {
        os << z.dangerLevel;
        return os;
    }
};
