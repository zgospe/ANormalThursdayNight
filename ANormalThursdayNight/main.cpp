#include <iostream>
#include "Character.h"

void intro(Character &player);
bool fight(Character &player, Character &enemy);
void battle (Character & atk, Character & def, Item & atkWep, Item & defWep);
void takeItem(Character &player, Character &enemy);
int askForInput(int lb, int ub);
std::string askForInput();

int main() {

    //seed random
    std::srand ((unsigned int)time(0));

    //create player
    Character player = Character(30, 2, 2);

    //start game
    intro(player);

    while (player.getHP() > 0) {
        //create enemy based on player's experience points
        Character enemy = Character((int)player.getXP() + 4, player.getXP() / 2 + 1, player.getXP() / 2 + 1);

        enemy.name = "Demon " + std::to_string((player.getXP() + 1));
        enemy.randomEquipment(player.getXP());
        if (fight(player, enemy)) {
            takeItem(player, enemy);
        }
    }

    std::cout << player.name << " has fallen after " << (player.getXP() + 1) << " demons." << std::endl;
    std::cout << "Now, Satan is laughing. Thank you for playing A NORMAL THURSDAY NIGHT!";
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
    std::cout << "Welcome to A NORMAL THURSDAY NIGHT!" << std::endl;
    std::cout << "What is your name? ";

    player.name = askForInput();

    std::cout << "It is a Thursday, and " << player.name << " is feeling quite bored." << std::endl;
    std::cout << player.name << " decides to laugh at Satan." << std::endl;
    std::cout << std::endl;
    std::cout << "Suddenly, monsters come out ";
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
        std::cout << atk.name << " deals " << (attackDamage - eDefend) << " to " << def.name << "." << std::endl;

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