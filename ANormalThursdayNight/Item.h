//
// Created by Zachary James Gospe on 10/20/16.
//

/*
 * A super class defining the characteristics
 * of all types of actions, those being weapons,
 * armors, and miscellaneous.
 */

#ifndef ROGUE_LIKE_ITEM_H
#define ROGUE_LIKE_ITEM_H

#include <string>
#include <random>
#include "Modifier.h"

class Item {

private:

    //potential qualities of an item
    size_t dam;
    size_t ac;
    int uses;
    size_t itemLevel;

    //Breaks the item, adds the "Broken"
    //modifier to the beginning of the item
    //and cuts all stats in half.
    void breakItem();

public:
    std::string name;

    //generates a random item based on item level
    //using the arrays of potential modifiers
    Item(size_t itemLevel, const Modifier baseName[], const Modifier prefixName[], const Modifier suffixName[]);

    //alt constructor, player's fists
    Item(std::string leftorright, size_t fistDamage);

    //returns the item's damage
    size_t getDam();

    //returns the item's protection
    size_t getAC();

    void setDam(size_t newDam);

    void setAC(size_t newAC);

    void setUse(int newUse);

    //reduces the item's usage, and
    //if it changes zero, adds the "Broken"
    //modifier to the beginning of the item
    //and cuts all stats in half. (Uses are then
    //upped to 1 so the broken item can be used).
    void useItem();

    void modify(Modifier a);

};

#endif //ROGUE_LIKE_ITEM_H
