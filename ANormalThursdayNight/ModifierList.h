//
// Created by Zachary James Gospe on 10/22/16.
//

#ifndef ROGUE_LIKE_MODIFIERLIST_H
#define ROGUE_LIKE_MODIFIERLIST_H

#include "Modifier.h"

//size of modifier arrays
const size_t BASENAMESSIZE = 46;
const size_t PNAMESSIZE = 20;
const size_t SNAMESSIZE = 11;

//Make and keep track of Modifiers in an array
//Modifiers to be used to randomly generate items
//(PrefixBaseSuffix?, name, damage bonus, ac bonus, use bonus, dam mult, ac mult)
const Modifier baseNames[BASENAMESSIZE] = {
        Modifier(1, "Pillow", 0, 1, 0, 0.75, 1),
        Modifier(1, "Severed Head", 2, 0, 0, 1.1, .75),
        Modifier(1, "Thumbtack", 2, 0, 0, 1, 0),
        Modifier(1, "Stale Bread", 0, 0, 0, .75, .75),
        Modifier(1, "Fly Swatter", 2, 0, 1, 1, .75),
        Modifier(1, "Baseball Bat", 3, 0, 1, 1.25, 1),
        Modifier(1, "Waffle Iron", 2, 1, 0, 1, 1),
        Modifier(1, "Saxophone", 5, 1, 0, 1, 1),
        Modifier(1, "Bowling Ball", 2, 0, 0, 1.25, .75),
        Modifier(1, "Tazer", 3, 0, 1, 1.25, 1),
        Modifier(1, "Pickaxe", 5, 0, 1, 1.25, .75),
        Modifier(1, "Steak Knife", 4, 0, 0, 1, 0.5),
        Modifier(1, "Mace", 5, 0, 1, 1.25, 1),
        Modifier(1, "Sword", 3, 1, 1, 1.5, 1),
        Modifier(1, "Broadsword", 6, 2, 0, 1.5, 1),
        Modifier(1, "Hand Grenade", 10, 0, -1, 1.5, 0),
        Modifier(1, "Sniper Rifle", 5, 0, 0, 1.5, .25),
        Modifier(1, "Lazer Gun", 3, 0, 1, 1.5, .75),
        Modifier(1, "RPG Launcher", 10, 0, -1, 1.5, .25),
        Modifier(1, "Bible", 0, 3, 0, 0.5, 1.75),
        Modifier(1, "Sweater", 0, 2, 0, 0, 1.25),
        Modifier(1, "Shorts", 0, 1, 0, 0, 1.25),
        Modifier(1, "Bucket", 1, 2, 1, 0.5, 1.25),
        Modifier(1, "Raincoat", 0, 2, 1, 0.25, 1.25),
        Modifier(1, "Plastic Cup", 0, 0, 0, .25, 1.25),
        Modifier(1, "Umbrella", 2, 1, 0, 1, 1.25),
        Modifier(1, "Car Door", 3, 3, 1, 1, 1),
        Modifier(1, "Shield", 2, 5, 1, .75, 1.5),
        Modifier(1, "Helmet", 0, 5, 1, .5, 1.5),
        Modifier(1, "Boots", 1, 4, 0, .75, 1.25),
        Modifier(1, "Chain Mail", 0, 5, 1, 0, 1.5),
        Modifier(1, "Plate Mail", 0, 7, 1, 0, 1.5),
        Modifier(1, "Bulletproof Vest", 0, 8, 0, 0, 1.5),
        Modifier(1, "Flak Jacket", 0, 8, -1, 0, 2),
        Modifier(1, "Eyeball", 0, 0, 0, .25, 0),
        Modifier(1, "Femur", 1, 0, 0, .25, .25),
        Modifier(1, "Potato", 1, 1, 1, .25, .25),
        Modifier(1, "Pizza", 0, 0, -1, .5, .5),
        Modifier(1, "Potted Plant", 2, 2, -1, .25, .25),
        Modifier(1, "Water Gun", 0, 0, 0, 1, .25),
        Modifier(1, "Dirty Laundry", 0, 2, 0, .25, 1),
        Modifier(1, "Monkey", 5, 2, -1, 1, 1),
        Modifier(1, "Bad Attitude", 5, 2, 0, 1.5, 1),
        Modifier(1, "Positive Mindset", 2, 5, 0, 1, 1.5),
        Modifier(1, "Logical Thinking", 0, 10, 0, .75, 1.5),
        Modifier(1, "Rational Argument", 5, 5, 0, 1.5, .75)
};

const Modifier prefixNames[PNAMESSIZE] = {
        Modifier(0, "Golden", 0, 0, 2, 1.25, 1.25),
        Modifier(0, "Shiny", 0, 0, 2, 1, 1),
        Modifier(0, "Sharpened", 2, 0, 0, 1.25, 1),
        Modifier(0, "Gargantuan", 3, 3, 1, 1.5, 1.5),
        Modifier(0, "Deadly", 5, 0, 0, 1.5, 1),
        Modifier(0, "Atomic", 10, 0, -1, 1.5, 0.5),
        Modifier(0, "Legendary", 3, 3, 3, 1.5, 1.5),
        Modifier(0, "Fireproof", 0, 3, 0, 1, 1.5),
        Modifier(0, "Titanium", 2, 2, 1, 1.25, 1.25),
        Modifier(0, "Dependable", 0, 5, 3, 1, 1),
        Modifier(0, "Ancient", 0, 0, -1, 1.25, 1.25),
        Modifier(0, "Satanic", 5, 0, 0, 2, .25),
        Modifier(0, "Holy", 0, 5, 1, .25, 2),
        Modifier(0, "Glorious", 0, 3, 0, 1, 1.75),
        Modifier(0, "Imaginary", 0, 0, 10, .25, .25),
        Modifier(0, "Tiny", 0, 0, 1, .5, .5),
        Modifier(0, "Disgusting", 2, 2, -1, 1.25, 1.25),
        Modifier(0, "Simple", 2, 2, 0, 1, 1),
        Modifier(0, "Unremarkable", 0, 0, 2, 1, 1),
        Modifier(0, "Delicate", 0, 0, -1, 1, 1)
};

const Modifier suffixNames[SNAMESSIZE] = {
        Modifier(2, "of Strength", 5, 0, 0, 1.5, .5),
        Modifier(2, "of Protection", 0, 5, 0, .5, 1.5),
        Modifier(2, "of Endless Conquest", 0, 0, 3, 1, 1),
        Modifier(2, "of Purity", 0, 5, 0, 1.25, 1.25),
        Modifier(2, "of Courage", 3, 3, 1, 1.25, 1.25),
        Modifier(2, "of the Abyss", 5, 0, 0, 1.25, .75),
        Modifier(2, "Piñata", 0, 0, 0, .25, .25),
        Modifier(2, "of Destruction", 0, 0, 0, 2, .5),
        Modifier(2, "of Questionable Origin", 5, 5, 0, 1, 1),
        Modifier(2, "of Power", 5, 5, 0, 1.5, 1.5),
        Modifier(2, "of Diplomacy", 0, 10, 2, .25, 2)
};

#endif //ROGUE_LIKE_MODIFIERLIST_H
