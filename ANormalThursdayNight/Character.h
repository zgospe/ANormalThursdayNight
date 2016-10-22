//
// Created by Zachary James Gospe on 10/20/16.
//

#ifndef ROGUE_LIKE_CHARACTER_H
#define ROGUE_LIKE_CHARACTER_H

#include <string>
#include "Item.h"

class Character {

private:

    //basic stats, health, experience, armor
    int hp;
    int xp = 0;
    size_t ac;
    size_t baseDam = 0;

public:
    //item slots
    Item equip[4] = {Item("Right", baseDam), Item("Left", baseDam), Item(0), Item(0)};

    std::string name = "";

    Character(int health, size_t armor, size_t damage);

    void randomEquipment(size_t itemLevel);

    int getHP();

    void loseHP(size_t damage);

    size_t getXP();

    void addXP();

    size_t getAC();

    size_t attack(size_t itemSlot);

    void equipItem(size_t itemSlot, Item a);

    void showInventory();

    void showAttackInv();

    void showDefenseInv();
};


#endif //ROGUE_LIKE_CHARACTER_H
