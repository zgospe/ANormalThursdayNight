#include <iostream>
#include "Character.h"

void setModifiers(Modifier bases[], Modifier prefix[], Modifier suffix[]);
void intro(Character &player);
bool fight(Character &player, Character &enemy);
void aftermath(Character &player, Character &enemy);
int askForInput(int lb, int ub);
std::string askForInput();

int main() {
    //Make and keep track of modifiers in an array
    //modifiers to be used for items
    Modifier baseNames[BASENAMESSIZE] = {
            Modifier(1, "Pillow"), Modifier(1, "Severed Head"), Modifier(1, "Thumbtack"),
            Modifier(1, "Stale Bread"), Modifier(1, "Fly Swatter"), Modifier(1, "Baseball Bat"),
            Modifier(1, "Waffle Iron"), Modifier(1, "Saxophone"), Modifier(1, "Bowling Ball"),
            Modifier(1, "Tazer"), Modifier(1, "Pickaxe"), Modifier(1, "Steak Knife"),
            Modifier(1, "Mace"), Modifier(1, "Sword"), Modifier(1, "Broadsword"),
            Modifier(1, "Hand Grenade"), Modifier(1, "Sniper Rifle"), Modifier(1, "Lazer Gun"),
            Modifier(1, "RPG Launcher"), Modifier(1, "Bible"), Modifier(1, "Sweater"),
            Modifier(1, "Shorts"), Modifier(1, "Bucket"), Modifier(1, "Raincoat"),
            Modifier(1, "Plastic Cup"), Modifier(1, "Umbrella"), Modifier(1, "Car Door"),
            Modifier(1, "Shield"), Modifier(1, "Helmet"), Modifier(1, "Boots"),
            Modifier(1, "Chain Mail"), Modifier(1, "Plate Mail"), Modifier(1, "Bulletproof Vest"),
            Modifier(1, "Flak Jacket"), Modifier(1, "Eyeball"), Modifier(1, "Femur"),
            Modifier(1, "Potato"), Modifier(1, "Pizza"), Modifier(1, "Potted Plant"),
            Modifier(1, "Water Gun"), Modifier(1, "Dirty Laundry"), Modifier(1, "Monkey"),
            Modifier(1, "Bad Attitude"), Modifier(1, "Positive Mindset"), Modifier(1, "Logical Thinking"),
            Modifier(1, "Rational Argument")
    };

    Modifier prefixNames[PNAMESSIZE] = {
            Modifier(0, "Golden"), Modifier(0, "Shiny"), Modifier(0, "Sharpened"),
            Modifier(0, "Gargantuan"), Modifier(0, "Deadly"), Modifier(0, "Atomic"),
            Modifier(0, "Legendary"), Modifier(0, "Golden"), Modifier(0, "Titanium"),
            Modifier(0, "Dependable"), Modifier(0, "Ancient"), Modifier(0, "Satanic"),
            Modifier(0, "Holy"), Modifier(0, "Glorious"), Modifier(0, "Imaginary"),
            Modifier(0, "Tiny"), Modifier(0, "Disgusting"), Modifier(0, "Simple"),
            Modifier(0, "Unremarkable"), Modifier(0, "Delicate")
    };

    Modifier suffixNames[SNAMESSIZE] = {
            Modifier(2, "of Strength"), Modifier(2, "of Protection"), Modifier(2, "of Endless Conquest"),
            Modifier(2, "of Purity"), Modifier(2, "of Courage"), Modifier(2, "of the Abyss"),
            Modifier(2, "Piñata"), Modifier(2, "of Destruction"), Modifier(2, "of Questionable Origin"),
            Modifier(2, "of Power"), Modifier(2, "of Diplomacy")
    };

    std::srand ((unsigned int)time(0));
    setModifiers(baseNames, prefixNames, suffixNames);

    Character player = Character(30, 2, 2);
    player.equip[3] = Item(0, baseNames, prefixNames, suffixNames);
    player.equip[2] = Item(0, baseNames, prefixNames, suffixNames);

    intro(player);

    while (player.getHP() > 0) {
        Character enemy = Character((int)player.getXP() + 4, player.getXP() / 4, (player.getXP() / 2) + 2);
        enemy.name = "Demon " + std::to_string((player.getXP() + 1));
        enemy.randomEquipment(player.getXP(), baseNames, prefixNames, suffixNames);
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
        size_t choice = (size_t) askForInput(1, 4);
        choice -= 1;
        size_t attackDamage = player.attack(choice);

        std::cout << player.name << " attacks with " << player.equip[choice].name << "." << std::endl;
        std::cout << std::endl;
        size_t eDefend = (size_t)(rand() % 4);
        std::cout << enemy.name << " defends with " << enemy.equip[eDefend].name << "." << std::endl;
        eDefend = enemy.equip[eDefend].getAC();
        eDefend += enemy.getAC();
        if (attackDamage > eDefend) {
            std::cout << player.name << " deals " << (attackDamage - eDefend) << " to " << enemy.name << "." << std::endl;

            enemy.loseHP(attackDamage - eDefend);
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
            size_t defend = (size_t) askForInput(1, 4);
            defend -= 1;
            defend = player.equip[defend].getAC() + player.getAC();

            if (enemyDamage > defend) {
                std::cout << enemy.name << " deals " << (enemyDamage - defend) << " to " << player.name << "." << std::endl;

                player.loseHP(enemyDamage - defend);
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

void aftermath(Character &player, Character &enemy) {
    std::cout << "Which item would you like to take?" << std::endl;
    enemy.showInventory();
    std::cout << "Or press 0 to take nothing." << std::endl;
    int echoice = askForInput(0, 4);

    if (echoice != 0) {
        echoice -= 1;

        std::cout << "Which slot would you like to store it in?" << std::endl;
        player.showInventory();
        size_t slot = size_t (askForInput(1, 4));
        slot -= 1;

        player.equipItem(slot, enemy.equip[echoice]);
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

//establish the modifiers
void setModifiers(Modifier bases[], Modifier prefix[], Modifier suffix[]) {

    //initialize base name stuff
    for (size_t i = 0; i < BASENAMESSIZE; i++) {

        //str plus names
        if (i < 20) {
            bases[i].setDamPlus((int) ((i / 5) + 3));

            //str mult
            if (i > 10) {
                bases[i].setDamMult(i / 10);
            }
        } else if (i < 34) { //ac plus names
            bases[i].setACPlus((int) (((i - 19) / 4) + 5));

            //ac mult
            if (i > 27) {
                bases[i].setACMult((i - 27) / 10);
            }
        } else { //both
            bases[i].setDamMult((i - 33) / 24);
            bases[i].setACMult((i - 33) / 24);
            bases[i].setDamPlus(2);
        }
    }

    //initialize prefix name stuff
    for (size_t i = 0; i < PNAMESSIZE; i++) {

        //str plus names
        if (i < 7) {
            prefix[i].setDamPlus((int) ((i / 5) + 2));

            //str multiplier
            if (i > 4) {
                prefix[i].setDamMult(i / 10);
            }
        } else if (i < 10) { //ac plus names

            prefix[i].setACPlus(4);

            prefix[i].setACMult(i / 7);

            prefix[i].setUsePlus(1);

            //dependable
            if (i == 9) {
                prefix[i].setUsePlus(3);
            }

        } else if (i < 14) { //both
            bases[i].setDamMult(i / 9);

            bases[i].setACMult(i / 9);

        } else {
            prefix[i].setDamMult(i / 20); //below 1
            prefix[i].setUsePlus(1);

            if (i == 19) {
                prefix[i].setUsePlus(-1); //delicate
            }
        }
    }


    //initialize suffix name stuff
    for (size_t i = 0; i < SNAMESSIZE; i++) {

        //str plus names
        if (i == 0 || i == 2 || i == 4 || i == 5 || i == 7 || i == 9) {
            suffix[i].setDamPlus(2);

            //str multiplier
            if (i > 4) {
                suffix[i].setDamMult(1 + (i / 15));
            }
        }

        if (i == 1 || i == 3 || i == 4 || i == 10) { //ac plus names

            suffix[i].setACPlus(4);

            suffix[i].setACMult(1 + (i / 6));

        }

        if (i == 2) {
            suffix[i].setUsePlus(3);
        }

        if (i == 6) { //pinata
            suffix[i].setUsePlus(-2);
            suffix[i].setACMult(0.5);
        }

        if (i == 8) {
            suffix[i].setDamMult((rand() % 20) / 5);
        }
    }
}
