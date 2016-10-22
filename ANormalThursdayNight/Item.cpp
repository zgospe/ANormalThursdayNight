//
// Created by Zachary James Gospe on 10/20/16.
//

#include "Item.h"
#include <iostream>
#include <ctime>

//randomly generates an item
Item::Item(size_t itemLevel) :
        //bmi
        dam(rand() % (itemLevel / 2 + 2)),
        ac(rand() % (itemLevel / 2 + 2)),
        uses(3), name("")
{

    //pick mod
    size_t baseMod = rand() % BASENAMESSIZE;


    //modify
    modify(baseNames[baseMod]);

    //pick aux mods
    int otherMods = rand() % 100;
    //more likely to get rare items as game goes on
    otherMods += itemLevel / 2;

    if (otherMods >= 50 && otherMods < 70) {
        size_t suffMod = rand() % SNAMESSIZE;
        modify(suffixNames[suffMod]);
    } else if (otherMods >= 70 || otherMods < 90) {
        size_t preMod = rand() % PNAMESSIZE;
        modify(prefixNames[preMod]);
    } else if (otherMods >= 90) {
        size_t preMod = rand() % PNAMESSIZE;
        size_t suffMod = rand() % SNAMESSIZE;

        modify(suffixNames[suffMod]);
        modify(prefixNames[preMod]);
    }
}

//returns the damage value of the item
size_t Item::getDam() {
    return dam;
}

//returns the armor value of the item
size_t Item::getAC() {
    return ac;
}

void Item::useItem() {
    uses--;

    if (uses <= 0) {
        breakItem();
    }
}

//Breaks the item, adds the "Broken"
//modifier to the beginning of the item
//and cuts all stats in half. (Uses are then
//upped to 1 so the broken item can be used).
void Item::breakItem() {
    dam /= 2;
    ac /= 2;
    uses = 2;

    std::cout << name << " breaks!" << std::endl;

    if (name.substr(0, 6) == "Broken" || name.substr(0, 6) == "Very B") {
        name = "Very " + name;
    } else if (name.substr(0, 9) == "Very Very"){
        name = "Garbage With Sentimental Value";
    } else {
        name = "Broken " + name;
    }
}

//for empty weapon slots, makes a left or right fist
//must specify Left or Right in the string
Item::Item(std::string leftorright, size_t fistDamage) :
                                name(leftorright + " Fist"),
                                dam(fistDamage),
                                uses(3),
                                ac(0),
                                itemLevel(fistDamage)
{
}

void Item::setDam(size_t newDam) {
    dam = newDam;
}

void Item::setAC(size_t newAC) {
    ac = newAC;
}

void Item::setUse(int newUse) {
    uses = newUse;
}

void Item::modify(Modifier a) {

        if (a.getType() == 0) {
            name = a.getName() + " " + name;
        } else if (a.getType() ==  1) {
            name = a.getName();
        } else {
            name += " " + a.getName();
        }

        dam *= a.getDamMult();
        dam += a.getDamPlus();

        ac *= a.getACMult();
        ac += a.getACPlus();

        uses += a.getUsePlus();

}