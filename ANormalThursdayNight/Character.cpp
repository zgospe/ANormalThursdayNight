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

size_t Character::attack(size_t weaponSlot) {
    return baseDam + equip[weaponSlot].getDam();
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


