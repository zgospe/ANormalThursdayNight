//
// Created by Zachary James Gospe on 10/20/16.
//

#include "Item.h"
#include <iostream>
#include <ctime>

//randomly generates an item
Item::Item(size_t itemLevel) : dam(itemLevel / 2), ac(itemLevel / 3), uses(3)
{
    baseNameModifier();

    //Choose suffix:
    size_t suff = rand() % (SUFFIXSIZE * 2);
    if (suff < SUFFIXSIZE) {
        name += SUFFIX[suff];

        //Modifier
        if (suff == 0 || suff == 3
                || suff == 4 || suff == 7) {
            dam += 2;
        }

        if (suff == 1 || suff == 3
            || suff == 5 ) {
            ac += 3;
        }

        if (suff == 2 || suff == 6 || suff == 7) {
            if (suff == 2) uses *= 2;
            uses *= 1.5;
        }

        if (suff == 5) {
            uses = 1;
            dam += 10;
        }
    }

    //Choose Prefix
    size_t pref = rand() % (PREFIXSIZE * 3);
    if (pref < PREFIXSIZE) {
        name = PREFIX[pref] + name;

        //Modifier
        if (suff == 1 || suff == 2
            || suff == 5 || suff == 8) {
            dam += 5;
        }

        if (suff == 0 || suff == 6 ) {
            dam /= 2;
        }

        if (suff == 4 || suff == 5 || suff == 7) {
            ac += 3;
        }

        if (suff == 2 || suff == 3 || suff == 7 || suff == 8) {
            uses += 5;
        }
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
        (*this).breakItem();
        uses = 5;
    }
}

//Breaks the item, adds the "Broken"
//modifier to the beginning of the item
//and cuts all stats in half. (Uses are then
//upped to 1 so the broken item can be used).
void Item::breakItem() {
    dam /= 2;
    ac /= 2;
    name = "Broken " + name;
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

void Item::baseNameModifier() {
    //Choose the base item name
    size_t base = rand() % BASENAMESSIZE;
    name = BASENAMES[base];

    //Give basics stats dependent
    //on the base name;

    //weapon names
    if (base < 32) {
        dam += 1;
        dam += base / 4;
    } else if (base < 56) {
        ac += 1;
        ac += (base - 32) / 6;
    } else {
        dam += rand() % (base - 55);
        ac += rand() % (base - 55);
        uses--;
    }
}
