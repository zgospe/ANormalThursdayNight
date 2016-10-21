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

const std::string BASENAMES[16] = {"Sword", "Lance", "Spear", "Shield", "Armor",
        "Torch", "Boots", "Femur", "Severed Head", "Stale Bread", "Bow",
                                   "Glasses", "Skeleton Key", "Bucket", "Thumbtack", "Pistol"};
const size_t BASENAMESSIZE = 16;

const std::string PREFIX[9] = {"Bent ", "Powerful ", "Glowing ", "Durable ",
                               "Protector's ", "Gladiator's ", "Short ", "Stout ", "Shiny "};
const size_t PREFIXSIZE = 9;

const std::string SUFFIX[8] = {" of Strength", " of Protection", " of Endless Conquest",
                               " of Steel", " of Power", " of Sadness", " of Loneliness", " of the Abyss"};
const size_t SUFFIXSIZE = 8;

class Item {

private:

    //potential qualities of an item
    size_t dam;
    size_t ac;
    int uses;

public:
    std::string name;

    //generates a random item
    Item();

    Item(const Item &a);

    //alt constructor, player's fists
    Item(size_t fistDamage);

    //alt constructor, empty slot
    Item(std::string nothing);

    //returns the item's damage
    size_t getDam();

    //returns the item's protection
    size_t getAC();

    //returns the item's usages
    int getUses();

    //reduces the item's usage, and
    //if it changes zero, adds the "Broken"
    //modifier to the beginning of the item
    //and cuts all stats in half. (Uses are then
    //upped to 1 so the broken item can be used).
    void useItem();

    //Breaks the item, adds the "Broken"
    //modifier to the beginning of the item
    //and cuts all stats in half.
    void breakItem();

};

#endif //ROGUE_LIKE_ITEM_H
