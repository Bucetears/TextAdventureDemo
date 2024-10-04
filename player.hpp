#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
using namespace std;

class Player
{
    public:
    int affectionValue = 5;
    int snmValue = 5;
    void alterValues(vector<int> values);

    void alterValues(vector<int> values)
    {
        affectionValue += values[0];
        snmValue += values[1];
    }

};


#endif