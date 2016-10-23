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
    size_t maxHealth = 30;
    int xp = 0;
    size_t ac;
    size_t baseDam;
    size_t souls = 0;
    size_t startingIL = 0;

public:
    //item slots
    Item equip[4] = {Item("Right", baseDam), Item("Left", baseDam), Item(0), Item(0)};

    std::string name = "";

    //if player has sat through exposition before
    bool firstPlay = true;

    Character(int health, size_t armor, size_t damage);

    void randomEquipment(size_t itemLevel);

    int getHP();

    void loseHP(size_t damage);

    size_t getXP();

    void addXP();

    size_t getAC();

    size_t getDam();

    size_t attack(Item weapon);

    void equipItem(size_t itemSlot, Item a);

    void showInventory();

    void showAttackInv();

    void showDefenseInv();

    bool spendSouls(size_t cost);

    void gainSouls();

    size_t getSouls();

    size_t addDam();

    size_t addAC();

    size_t addToMaxHealth (size_t amount);

    size_t getMaxHealth();

    void increaseStartingIL(size_t amount);

    size_t getStartingIL();

    void setHP(size_t amount);
};


#endif //ROGUE_LIKE_CHARACTER_H
