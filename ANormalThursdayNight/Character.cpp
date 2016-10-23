//
// Created by Zachary James Gospe on 10/20/16.
//

#include "Character.h"
#include <iostream>

Character::Character(int health, size_t armor, size_t damage) :
            hp(health),
            ac(armor),
            baseDam(damage)
{
}

//puts 2-4 items in a player's equip slots
void Character::randomEquipment(size_t itemLevel) {

    size_t itemCount = (size_t)rand() % 20;

        equip[3] = Item(itemLevel);

        equip [2] = Item(itemLevel);

    if (itemCount > 15) {
        equip [1] = Item(itemLevel);
    } else {
        equip[1].name = name + "'s " + equip[1].name;
    }

    if (itemCount == 20) {
        equip[0] = Item(itemLevel);
    } else {
        equip[0].name = name + "'s " + equip[0].name;
    }
}

int Character::getHP() {
    return hp;
}

size_t Character::getAC() {
    return ac;
}

size_t Character::attack(Item weapon) {
    return baseDam + weapon.getDam();
}

void Character::equipItem(size_t itemSlot, Item a) {
    equip[itemSlot] = a;
}

size_t Character::getXP() {
    return (size_t)xp;
}

void Character::addXP() {
    xp++;
}

void Character::loseHP(size_t damage) {
    hp -= damage;
}

void Character::showInventory() {
    for (size_t i = 0; i < 4; i++) {
        std::cout << (i + 1) << ": " << equip[i].name
                  << " (Attack: " << equip[i].getDam() << ", Defense: "
                  << equip[i].getAC() << ")" << std::endl;
    }
}

void Character::showDefenseInv() {
    for (size_t i = 0; i < 4; i++) {
        std::cout << (i + 1) << ": " << equip[i].name
                  << " (Defense: " << equip[i].getAC() << ")" << std::endl;
    }
}

void Character::showAttackInv() {
    for (size_t i = 0; i < 4; i++) {
        std::cout << (i + 1) << ": " << equip[i].name
                  << " (Attack: " << equip[i].getDam() << ")" << std::endl;
    }
}

//determines if an object can be afforded (true/false),
//and spends the required souls if so
bool Character::spendSouls(size_t cost) {

    if (souls >= cost) {
        souls -= cost;
        return true;
    } else {
        return false;
    }
}

//changes xp into souls, sets xp to 0
void Character::gainSouls() {

    souls += xp;
    xp = 0;

}

size_t Character::getSouls() {
    return souls;
}

size_t Character::addDam() {
    baseDam++;
    return baseDam;
}

size_t Character::addAC() {
    ac++;
    return ac;
}

size_t Character::addToMaxHealth(size_t amount) {
    return (maxHealth + amount);
}

size_t Character::getMaxHealth() {
    return maxHealth;
}

void Character::increaseStartingIL(size_t amount) {
    startingIL += amount;
}

size_t Character::getDam() {
    return baseDam;
}

size_t Character::getStartingIL() {
    return startingIL;
}

void Character::setHP(size_t amount) {
    hp = (int)amount;
}


