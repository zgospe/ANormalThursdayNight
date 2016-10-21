#include <iostream>
#include "Character.h"
#include "Item.h"

void intro(Character &player);
bool fight(Character &player, Character &enemy);
void aftermath(Character &player, Character &enemy);

int main() {
    std::srand ((unsigned int)time(0));
    Character player = Character(30, 2, 2);
    intro(player);

    while (player.getHP() > 0) {
        Character enemy = Character((int)player.getXP() + 4, player.getXP() / 4, (player.getXP() / 2) + 2);
        enemy.name = "Demon " + std::to_string((player.getXP() + 1));
        enemy.randomEquipment(player.getXP());
        if (fight(player, enemy)) {
            aftermath(player, enemy);
        }
    }

    std::cout << player.name << " has fallen after " << (player.getXP() + 1) << " demons." << std::endl;
    std::cout << "Now, Satan is laughing. Thank you for playing A NORMAL THURSDAY NIGHT!";
}

bool fight(Character &player, Character &enemy) {
    std::cout << player.name << " VS " << enemy.name << "!" << std::endl;

    while (player.getHP() > 0 && enemy.getHP() > 0) {
        std::cout << "Would you like to attack with:" << std::endl;
        player.showAttackInv();
        size_t choice;
        std::cin >> choice;
        choice -= 1;
        size_t attackDamage = player.attack(choice);
        std::cout << std::endl;

        std::cout << player.name << " attacks with " << player.equip[choice].name << "." << std::endl;
        std::cout << std::endl;
        size_t eDefend = (size_t)(rand() % 4);
        std::cout << enemy.name << " defends with " << enemy.equip[eDefend].name << "." << std::endl;
        eDefend = enemy.equip[eDefend].getAC();
        eDefend += enemy.getAC();
        if (attackDamage > eDefend) {
            std::cout << player.name << " deals " << (attackDamage - enemy.getAC()) << " to " << enemy.name << "." << std::endl;

            enemy.loseHP(attackDamage - enemy.getAC());
            std::cout << enemy.name << " is at " << enemy.getHP() << " health." << std::endl;
            player.equip[choice].useItem();
        } else {
            std::cout << player.name << "'s attack is ineffective!" << std:: endl;
            player.equip[choice].useItem();
        }

        std::cout << std::endl;
        if (enemy.getHP() > 0) {
            //enemy's turn
            choice = (size_t) rand() % 4;
            size_t enemyDamage = enemy.attack(choice);

            std::cout << enemy.name << " attacks with " << enemy.equip[choice].name
                      << " (Attack: " << enemy.equip[choice].getDam() << " )" << std::endl;
            std::cout << "How would you like to defend?" << std::endl;
            player.showDefenseInv();
            size_t defend;
            std::cin >> defend;
            defend -= 1;
            defend = player.equip[defend].getAC() + player.getAC();
            std::cout << std::endl;

            if (enemyDamage > defend) {
                std::cout << enemy.name << " deals " << (attackDamage - defend) << " to " << player.name << "." << std::endl;

                player.loseHP(attackDamage - defend);
                std::cout << player.name << " is at " << player.getHP() << " health." << std::endl;
                enemy.equip[choice].useItem();
            } else {
                std::cout << enemy.name << "'s attack is ineffective!" << std::endl;
                enemy.equip[choice].useItem();
            }
            player.equip[defend].useItem();
        }
    } //end the battle

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

    std::cin >> player.name;
    std::cout << std::endl;

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

void aftermath(Character &player, Character &enemy) {
    std::cout << "Which item would you like to take?" << std::endl;
    enemy.showInventory();
    std::cout << "Or press 0 to take nothing." << std::endl;
    size_t echoice;
    std::cin >> echoice;

    if (echoice != 0) {
        echoice -= 1;
        std::cout << std::endl;

        std::cout << "Which slot would you like to store it in?" << std::endl;
        player.showInventory();
        size_t slot;
        std::cin >> slot;
        slot -= 1;
        std::cout << std::endl;

        player.equipItem(slot, enemy.equip[echoice]);
    }
}