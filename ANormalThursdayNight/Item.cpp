//
// Created by Zachary James Gospe on 10/20/16.
//

#include "Item.h"
#include <iostream>
#include <ctime>

//randomly generates an item
Item::Item() : dam(size_t(rand() % 3)), ac(1), uses(3)
{
    //Choose the base item name
    size_t base = rand() % BASENAMESSIZE;
    name = BASENAMES[base];

    //Give basics stats dependent
    //on the base name;
    if (base == 0 || base == 1
           || base == 2 || base == 10
                || base == 14 || base == 15) {
        dam += size_t(rand() % 3) + 2;
    } else if (base == 3  || base == 4
                    || base == 6 || base == 11
                        || base == 13) {
        dam += rand() % 3;
        ac = size_t(rand() % 5) + 5;
    }

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

size_t Item::getDam() {
    return dam;
}

size_t Item::getAC() {
    return ac;
}

int Item::getUses() {
    return uses;
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

//for empty weapon slots
Item::Item(size_t fistDamage) : name("Fist"),
                                dam(fistDamage),
                                uses(5),
                                ac(0)
{
}

//for empty bag slots
Item::Item(std::string none) : name("Nothing"),
                               dam(0),
                               uses(40),
                               ac(0)

{
}

Item::Item(const Item &a) : name(a.name),
                     dam(a.dam),
                     uses(a.uses),
                     ac(a.ac)
{
}
