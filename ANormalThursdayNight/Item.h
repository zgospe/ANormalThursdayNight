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

//Name arrays used to randomly generate names for items
//BaseNames key: (80 Names)
//First 32 are mainly weapons growing in potential strength,
//next 24 are mainly armors growing in potential armor,
//next 19 are miscellaneous growing in both.
const size_t BASENAMESSIZE = 76;
const std::string BASENAMES[BASENAMESSIZE] = {"Pillow", "Severed Head", "Thumbtack", "Stale Bread",
                                              "Pencil", "Tennis Ball", "Stone", "Fly Swatter", "Baseball Bat",
                                              "Guitar", "Waffle Iron", "Saxophone", "Bowling Ball", "Whip",
                                              "Brass Knuckles", "Steak Knife", "Tazer", "Pickaxe",
                                              "Mace", "Sword", "Lance", "Rapier", "Broadsword", "Pistol", "Musket",
                                              "Rifle", "Holy Cross", "Holy Hand Grenade", "Sniper Rifle", "Lazer Gun",
                                              "RPG Launcher", "Holy Bible", "Pizza Box", "Sweater", "Boxers", "Shorts",
                                              "Sweatpants", "Bucket", "Scarf", "Raincoat", "Trench Coat",
                                              "Leather Jacket", "Board", "Medal of Honor", "Plastic Cup", "Umbrella",
                                              "Car Door", "Wooden Shield", "Leather Shield", "Shield", "Helmet", "Metal Boots",
                                              "Chain Mail", "Plate Mail", "Bulletproof Vest", "Flak Jacket", "Tooth",
                                              "Eyeball", "Femur", "Potato", "Stale Bread", "Rubik's Cube", "Pizza",
                                              "Torch", "Buns", "Laptop", "Water Gun", "Chopsticks", "Dirty Laundry",
                                              "Lamp", "Chair", "Monkey", "Bad Attitude", "Positive Mindset",
                                              "Logical Thinking", "Rational Argument"};


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
    size_t itemLevel;

    //Breaks the item, adds the "Broken"
    //modifier to the beginning of the item
    //and cuts all stats in half.
    void breakItem();

    //adds the stat modifiers for the base name
    //helper method
    void baseNameModifier();

public:
    std::string name;

    //generates a random item based on item level
    Item(size_t itemLevel);

    //alt constructor, player's fists
    Item(std::string leftorright, size_t fistDamage);

    //returns the item's damage
    size_t getDam();

    //returns the item's protection
    size_t getAC();

    //reduces the item's usage, and
    //if it changes zero, adds the "Broken"
    //modifier to the beginning of the item
    //and cuts all stats in half. (Uses are then
    //upped to 1 so the broken item can be used).
    void useItem();

};

#endif //ROGUE_LIKE_ITEM_H
