#include <iostream>
#include "Character.h"

void intro(Character &player);
void demonArena(Character &player);
bool fight(Character &player, Character &enemy);
void battle (Character & atk, Character & def, Item & atkWep, Item & defWep);
void takeItem(Character &player, Character &enemy);
bool heavenIsCapitalist(Character &player);
void shopTime(Character &player);
int askForInput(int lb, int ub);
std::string askForInput();

int main() {

    //seed random
    std::srand ((unsigned int)time(0));
    bool playAgain = true;

    //create player
    Character player = Character(30, 1, 1);

    //show title and ask for name
    std::cout << std::endl << "Welcome to A NORMAL THURSDAY NIGHT!" << std::endl << std::endl
              << "What is your name? ";
    player.name = askForInput();

    do {
        //fight demons
        demonArena(player);

        //shop in heaven
        playAgain = heavenIsCapitalist(player);

    } while (playAgain);

    std::cout << player.name << " falls to the depths of Hell. " << std::endl
              << "Satan is the one laughing now." << std::endl << std::endl
              << "Thanks for playing A NORMAL THURSDAY NIGHT!" << std::endl;

}

bool fight(Character &player, Character &enemy) {
    std::cout << player.name << " VS " << enemy.name << "!" << std::endl;

    while (player.getHP() > 0 && enemy.getHP() > 0) {
        //player chooses weapon
        std::cout << "What would you like to attack with:" << std::endl;
        player.showAttackInv();
        size_t choice = (size_t) askForInput(1, 4) - 1;

        std::cout << player.name << " attacks with " << player.equip[choice].name << "." << std::endl;
        std::cout << std::endl;

        //enemy chooses defense weapon
        size_t eChoice = (size_t)(rand() % 4);
        std::cout << enemy.name << " defends with " << enemy.equip[eChoice].name << "." << std::endl;
        std::cout << std::endl;

        battle(player, enemy, player.equip[choice], enemy.equip[eChoice]);

        if (enemy.getHP() > 0) {
            //enemy's turn, chooses weapon
            eChoice = (size_t) rand() % 4;
            std::cout << enemy.name << " attacks with " << enemy.equip[eChoice].name
                      << " (Attack: " << enemy.equip[eChoice].getDam() << ")" << std::endl;

            //choose defense
            std::cout << "How would you like to defend?" << std::endl;
            player.showDefenseInv();
            size_t defend = (size_t) askForInput(1, 4) - 1;

            //battle between them with chosen weapons
            battle(enemy, player, enemy.equip[eChoice], player.equip[defend]);
        }
    } //someone is dead

    if (enemy.getHP() <= 0) {
        player.addXP();
        return true;
    } else {
        return false;
    }
}

void intro(Character &player) {
    std::cout << "It is a Thursday, and " << player.name << " is feeling quite bored." << std::endl;
    std::cout << player.name << " decides to laugh at Satan." << std::endl;
    std::cout << std::endl;
    std::cout << "Suddenly, demons come out ";
    std::cout << "of nowhere and attack " << player.name << "!" << std::endl;
    std::cout << std::endl;

    std::cout << "Luckily, " << player.name << " came prepared!" << std::endl;
    std::cout << player.name << " is equipped with: " << std::endl;
    player.showInventory();
    std::cout << std::endl;

    std::cout << "It's time to fight!" << std::endl;
    std::cout << std::endl;
}

void takeItem(Character &player, Character &enemy) {
    std::cout << "Which item would you like to take?" << std::endl;
    enemy.showInventory();
    std::cout << "Or press 0 to take nothing." << std::endl;
    int choice = askForInput(0, 4);

    if (choice != 0) {
        choice -= 1; //move to 0 based indexing

        std::cout << "Which slot would you like to store it in?" << std::endl;
        player.showInventory();
        size_t slot = size_t (askForInput(1, 4)) - 1;

        player.equipItem(slot, enemy.equip[choice]);
    }
}

//asks user to input
int askForInput(int lb, int ub) {

    int choice;

    bool cond = false;

    do
    {
        std::cin >> choice;

        if (std::cin.fail() || choice < lb || choice > ub) {
            std::cout << "Not a valid input. Try again." << std::endl;
        } else {
            cond = true;
        }

        std::cin.clear();
        std::cin.ignore();

    }while(!cond);
    std::cout << std::endl;

    return choice;
}

std::string askForInput() {

    std::string choice;

    bool cool = false;

    while (!cool) {

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Not a valid input. Try again." << std::endl;
        } else {
            cool = true;
        }

        std::cin.clear();
        std::cin.ignore();
    }

    std::cout << std::endl;
    return choice;
}

void battle (Character & atk, Character & def, Item & atkWep, Item & defWep) {

    //defence value
    size_t eDefend = defWep.getAC() + def.getAC();
    //attack value
    size_t attackDamage = atk.attack(atkWep);

    if (attackDamage > eDefend) { //if damage goes through
        std::cout << atk.name << " deals " << (attackDamage - eDefend) << " damage to " << def.name << "." << std::endl;

        def.loseHP(attackDamage - eDefend);
        std::cout << def.name << " is at " << def.getHP() << " health." << std::endl;

    } else { //attack blocked

        std::cout << atk.name << "'s attack is ineffective!" << std:: endl;

    }

    //use charges of both items
    atkWep.useItem();
    defWep.useItem();
    std::cout << std::endl;

}

void demonArena (Character & player) {
    //start game
    intro(player);

    while (player.getHP() > 0) { //fight the demons
        //create enemy based on player's experience points
        Character enemy = Character((int)player.getXP() + 4, 0, (player.getXP() / 2) + 1);

        //create demon to fight
        enemy.name = "Demon " + std::to_string((player.getXP() + 1));
        enemy.randomEquipment(player.getXP());
        if (fight(player, enemy)) {
            takeItem(player, enemy);
        }
    }

    std::cout << player.name << " has fallen after " << (player.getXP() + 1) << " demons." << std::endl;
    std::cout << "A bright light shines upon the corpse, and " << player.name << "'s soul begins to rise..." <<
    std::endl << std::endl << std::endl;

}

bool heavenIsCapitalist(Character &player) { //shop time

    std::cout << player.name << "'s soul approaches a grand, shimmering gate." << std::endl;
    std::cout << "An angel stands before it." << std::endl << std::endl;

    if (player.firstPlay) {
        std::cout << "\"Welcome " << player.name << ". I have been watching" << std::endl
                  << "your noble fight against Satan's demons. You may not realize this, " << std::endl
                  << "but every time you killed a demon, you acquired a sinner's soul." << std::endl
                  << "These souls are the currency of Heaven." << std::endl << std::endl

                  << "Currently, our economy has been in shambles. Our wealthy citizens " << std::endl
                  << "have been too entertained with eternal happiness to bother spending" << std::endl
                  << "or investing souls. The market is stagnant, " << player.name << ", so we need" << std::endl
                  << "your help. Please, spend your souls in our marketplace. In return, I will" << std::endl
                  << "revive you and send you back to Earth so that you may kill more demons and" << std::endl
                  << "acquire more souls. If you make enough souls, you may purchase entrance" << std::endl
                  << "into Heaven for you and your family. However, if you disagree, I'll have no" << std::endl
                  << "choice but to banish you eternally to Hell.\"" << std::endl << std::endl;
    }

    std::cout << "What is your choice?" << std::endl
              << "1. Serve as a heavenly stimulus package." << std::endl
              << "2. Spend all of eternity in Hell." << std::endl;

    bool keepPlaying = (askForInput(1, 2) == 1);

    if (keepPlaying) {
        player.firstPlay = false;
        shopTime(player);
        return true;
    } else {
        return false;
    }
}

void shopTime (Character & player) {

    std::cout << "Welcome to Heaven's Marketplace." << std::endl;

    player.gainSouls(); //convert xp into souls
    bool shopping = true;

    do {

        std::cout << "You have " << player.getSouls() << " souls to spend." << std::endl;

        std::cout << "What would you like to buy?" << std::endl
                  << "1. Martial Arts Skill (5 souls) - increases base damage by one." << std::endl
                  << "2. Thick Skin (5 souls) - increases base armor by one." << std::endl
                  << "3. More Health (5 souls) - increases base health level by 5." << std::endl
                  << "4. Better Starting Items (5 souls) - increases base item level by 3." << std::endl
                  << "0. Leave Shop." << std::endl;
        int choice = askForInput(0, 4);

        if (choice == 1) {
            if (player.spendSouls(5)) {
                size_t newDam = player.addDam();
                std::cout << "Your base damage is now: " << newDam << std::endl;
            } else {
                std::cout << "You cannot afford this item." << std::endl;
            }
        } else if (choice == 2) {
            if (player.spendSouls(5)) {
                size_t newAC = player.addAC();
                std::cout << "Your base armor is now: " << newAC << std::endl;
            } else {
                std::cout << "You cannot afford this item." << std::endl;
            }
        } else if (choice == 3) {
            if (player.spendSouls(5)) {
                size_t newHP = player.addToMaxHealth(5);
                std::cout << "Your maximum health is now: " << newHP <<std::endl;
            } else {
                std::cout << "You cannot afford this item." << std::endl;
            }
        } else if (choice == 4) {
            if (player.spendSouls(5)) {
                player.increaseStartingIL(3);
                std::cout << "Your starting items will now, on average, be stronger." <<std::endl;
            } else {
                std::cout << "You cannot afford this item." << std::endl;
            }
        } else shopping = false;
        std::cout << std::endl;

    } while (shopping);

    //rebirth, reset player's equipment and health
    std::cout << player.name << "'s soul falls through the clouds and plummets back to Earth." << std::endl;
    std::cout << player.name << " is reborn!" << std::endl;

    //new starting items
    player.equip[0] = Item("Right", player.getDam());
    player.equip[1] = Item("Left", player.getDam());
    player.equip[2] = Item(player.getStartingIL());
    player.equip[3] = Item(player.getStartingIL());

    //set health up to max
    player.setHP(player.getMaxHealth());

}