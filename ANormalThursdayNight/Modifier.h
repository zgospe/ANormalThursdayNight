//
// Created by Zachary James Gospe on 10/21/16.
//
// Description: Class for random item generation,
// establishing modifier values for statistics and effects
// and attaching them to prefixes, base names, and suffixes.

#ifndef ROGUE_LIKE_MODIFIER_H
#define ROGUE_LIKE_MODIFIER_H

#include <string>

//side of modifier arrays
const size_t BASENAMESSIZE = 46;
const size_t PNAMESSIZE = 20;
const size_t SNAMESSIZE = 11;

class Modifier {

private:

    std::string name;

    //represents whether it is a suffix, base, or prefix (0, 1, 2 respectively)
    size_t type;

    int damPlus = 0;
    int acPlus = 0;
    int usePlus = 0;

    double damMult = 1;
    double acMult = 1;

public:

    //Constructor, given prefix and suffix
    Modifier(size_t type, std::string name);

    //Constructor
    Modifier();

    void setName(std::string name);

    void setType(size_t val);

    void setDamPlus(int val);

    void setACPlus(int val);

    void setUsePlus(int val);

    void setDamMult(double val);

    void setACMult(double val);

    std::string getName();

    size_t getType();

    int getDamPlus();

    int getACPlus();

    int getUsePlus();

    double getDamMult();

    double getACMult();

};



#endif //ROGUE_LIKE_MODIFIER_H
