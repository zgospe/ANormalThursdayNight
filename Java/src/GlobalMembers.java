package src;
public class GlobalMembers
{
	public static void intro(Character player)
	{
		System.out.print("It is a Thursday, and ");
		System.out.print(player.name);
		System.out.print(" is feeling quite bored.");
		System.out.print("\n");
		System.out.print(player.name);
		System.out.print(" decides to laugh at Satan.");
		System.out.print("\n");
		System.out.print("\n");
		System.out.print("Suddenly, demons come out ");
		System.out.print("of nowhere and attack ");
		System.out.print(player.name);
		System.out.print("!");
		System.out.print("\n");
		System.out.print("\n");

		System.out.print("Luckily, ");
		System.out.print(player.name);
		System.out.print(" came prepared!");
		System.out.print("\n");
		System.out.print(player.name);
		System.out.print(" is equipped with: ");
		System.out.print("\n");
		player.showInventory();
		System.out.print("\n");

		System.out.print("It's time to fight!");
		System.out.print("\n");
		System.out.print("\n");
	}
	public static void demonArena(Character player)
	{
		//start game
		intro(player);

		while (player.getHP() > 0)
		{ //fight the demons
			//create enemy based on player's experience points
			Character enemy = new Character((int)player.getXP() + 4, 0, (player.getXP() / 2) + 1);

			//create demon to fight
			enemy.name = "Demon " + String.valueOf((player.getXP() + 1));
			enemy.randomEquipment(player.getXP());
			if (fight(player, enemy))
			{
				takeItem(player, enemy);
			}
		}

		System.out.print(player.name);
		System.out.print(" has fallen after ");
		System.out.print((player.getXP() + 1));
		System.out.print(" demons.");
		System.out.print("\n");
		System.out.print("A bright light shines upon the corpse, and ");
		System.out.print(player.name);
		System.out.print("'s soul begins to rise...");
		System.out.print("\n");
		System.out.print("\n");
		System.out.print("\n");

	}
	public static boolean fight(Character player, Character enemy)
	{
		System.out.print(player.name);
		System.out.print(" VS ");
		System.out.print(enemy.name);
		System.out.print("!");
		System.out.print("\n");

		while (player.getHP() > 0 && enemy.getHP() > 0)
		{
			//player chooses weapon
			System.out.print("What would you like to attack with:");
			System.out.print("\n");
			player.showAttackInv();
			int choice = (int) askForInput(1, 4) - 1;

			System.out.print(player.name);
			System.out.print(" attacks with ");
			System.out.print(player.equip[choice].name);
			System.out.print(".");
			System.out.print("\n");
			System.out.print("\n");

			//enemy chooses defense weapon
			int eChoice = (int)(tangible.RandomNumbers.nextNumber() % 4);
			System.out.print(enemy.name);
			System.out.print(" defends with ");
			System.out.print(enemy.equip[eChoice].name);
			System.out.print(".");
			System.out.print("\n");
			System.out.print("\n");

			battle(player, enemy, player.equip[choice], enemy.equip[eChoice]);

			if (enemy.getHP() > 0)
			{
				//enemy's turn, chooses weapon
				eChoice = (int) tangible.RandomNumbers.nextNumber() % 4;
				System.out.print(enemy.name);
				System.out.print(" attacks with ");
				System.out.print(enemy.equip[eChoice].name);
				System.out.print(" (Attack: ");
				System.out.print(enemy.equip[eChoice].getDam());
				System.out.print(")");
				System.out.print("\n");

				//choose defense
				System.out.print("How would you like to defend?");
				System.out.print("\n");
				player.showDefenseInv();
				int defend = (int) askForInput(1, 4) - 1;

				//battle between them with chosen weapons
				battle(enemy, player, enemy.equip[eChoice], player.equip[defend]);
			}
		} //someone is dead

		if (enemy.getHP() <= 0)
		{
			player.addXP();
			return true;
		}
		else
		{
			return false;
		}
	}
	public static void battle(Character atk, Character def, Item atkWep, Item defWep)
	{

		//defence value
		int eDefend = defWep.getAC() + def.getAC();
		//attack value
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: int attackDamage = atk.attack(atkWep);
		int attackDamage = atk.attack(new Item(atkWep));

		if (attackDamage > eDefend)
		{ //if damage goes through
			System.out.print(atk.name);
			System.out.print(" deals ");
			System.out.print((attackDamage - eDefend));
			System.out.print(" damage to ");
			System.out.print(def.name);
			System.out.print(".");
			System.out.print("\n");

			def.loseHP(attackDamage - eDefend);
			System.out.print(def.name);
			System.out.print(" is at ");
			System.out.print(def.getHP());
			System.out.print(" health.");
			System.out.print("\n");

		}
		else
		{ //attack blocked

			System.out.print(atk.name);
			System.out.print("'s attack is ineffective!");
			System.out.println();

		}

		//use charges of both items
		atkWep.useItem();
		defWep.useItem();
		System.out.print("\n");

	}
	public static void takeItem(Character player, Character enemy)
	{
		System.out.print("Which item would you like to take?");
		System.out.print("\n");
		enemy.showInventory();
		System.out.print("Or press 0 to take nothing.");
		System.out.print("\n");
		int choice = askForInput(0, 4);

		if (choice != 0)
		{
			choice -= 1; //move to 0 based indexing

			System.out.print("Which slot would you like to store it in?");
			System.out.print("\n");
			player.showInventory();
			int slot = (int)askForInput(1, 4) - 1;

//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: player.equipItem(slot, enemy.equip[choice]);
			player.equipItem(slot, new Item(enemy.equip[choice]));
		}
	}
	public static boolean heavenIsCapitalist(Character player)
	{ //shop time

		System.out.print(player.name);
		System.out.print("'s soul approaches a grand, shimmering gate.");
		System.out.print("\n");
		System.out.print("An angel stands before it.");
		System.out.print("\n");
		System.out.print("\n");

		if (player.firstPlay)
		{
			System.out.print("\"Welcome ");
			System.out.print(player.name);
			System.out.print(". I have been watching");
			System.out.print("\n");
			System.out.print("your noble fight against Satan's demons. You may not realize this, ");
			System.out.print("\n");
			System.out.print("but every time you killed a demon, you acquired a sinner's soul.");
			System.out.print("\n");
			System.out.print("These souls are the currency of Heaven.");
			System.out.print("\n");
			System.out.print("\n");
			System.out.print("Currently, our economy has been in shambles. Our wealthy citizens ");
			System.out.print("\n");
			System.out.print("have been too entertained with eternal happiness to bother spending");
			System.out.print("\n");
			System.out.print("or investing souls. The market is stagnant, ");
			System.out.print(player.name);
			System.out.print(", so we need");
			System.out.print("\n");
			System.out.print("your help. Please, spend your souls in our marketplace. In return, I will");
			System.out.print("\n");
			System.out.print("revive you and send you back to Earth so that you may kill more demons and");
			System.out.print("\n");
			System.out.print("acquire more souls. If you make enough souls, you may purchase entrance");
			System.out.print("\n");
			System.out.print("into Heaven for you and your family. However, if you disagree, I'll have no");
			System.out.print("\n");
			System.out.print("choice but to banish you eternally to Hell.\"");
			System.out.print("\n");
			System.out.print("\n");
		}

		System.out.print("What is your choice?");
		System.out.print("\n");
		System.out.print("1. Serve as a heavenly stimulus package.");
		System.out.print("\n");
		System.out.print("2. Spend all of eternity in Hell.");
		System.out.print("\n");

		boolean keepPlaying = (askForInput(1, 2) == 1);

		if (keepPlaying)
		{
			player.firstPlay = false;
			shopTime(player);
			return true;
		}
		else
		{
			return false;
		}
	}
	public static void shopTime(Character player)
	{

		System.out.print("Welcome to Heaven's Marketplace.");
		System.out.print("\n");

		player.gainSouls(); //convert xp into souls
		boolean shopping = true;

		do
		{

			System.out.print("You have ");
			System.out.print(player.getSouls());
			System.out.print(" souls to spend.");
			System.out.print("\n");

			System.out.print("What would you like to buy?");
			System.out.print("\n");
			System.out.print("1. Martial Arts Skill (5 souls) - increases base damage by one.");
			System.out.print("\n");
			System.out.print("2. Thick Skin (5 souls) - increases base armor by one.");
			System.out.print("\n");
			System.out.print("3. More Health (5 souls) - increases base health level by 5.");
			System.out.print("\n");
			System.out.print("4. Better Starting Items (5 souls) - increases base item level by 3.");
			System.out.print("\n");
			System.out.print("0. Leave Shop.");
			System.out.print("\n");
			int choice = askForInput(0, 4);

			if (choice == 1)
			{
				if (player.spendSouls(5))
				{
					int newDam = player.addDam();
					System.out.print("Your base damage is now: ");
					System.out.print(newDam);
					System.out.print("\n");
				}
				else
				{
					System.out.print("You cannot afford this item.");
					System.out.print("\n");
				}
			}
			else if (choice == 2)
			{
				if (player.spendSouls(5))
				{
					int newAC = player.addAC();
					System.out.print("Your base armor is now: ");
					System.out.print(newAC);
					System.out.print("\n");
				}
				else
				{
					System.out.print("You cannot afford this item.");
					System.out.print("\n");
				}
			}
			else if (choice == 3)
			{
				if (player.spendSouls(5))
				{
					int newHP = player.addToMaxHealth(5);
					System.out.print("Your maximum health is now: ");
					System.out.print(newHP);
					System.out.print("\n");
				}
				else
				{
					System.out.print("You cannot afford this item.");
					System.out.print("\n");
				}
			}
			else if (choice == 4)
			{
				if (player.spendSouls(5))
				{
					player.increaseStartingIL(3);
					System.out.print("Your starting items will now, on average, be stronger.");
					System.out.print("\n");
				}
				else
				{
					System.out.print("You cannot afford this item.");
					System.out.print("\n");
				}
			}
			else
			{
				shopping = false;
			}
			System.out.print("\n");

		} while (shopping);

		//rebirth, reset player's equipment and health
		System.out.print(player.name);
		System.out.print("'s soul falls through the clouds and plummets back to Earth.");
		System.out.print("\n");
		System.out.print(player.name);
		System.out.print(" is reborn!");
		System.out.print("\n");

		//new starting items
		player.equip[0] = new Item("Right", player.getDam());
		player.equip[1] = new Item("Left", player.getDam());
		player.equip[2] = new Item(player.getStartingIL());
		player.equip[3] = new Item(player.getStartingIL());

		//set health up to max
		player.setHP(player.getMaxHealth());

	}

//asks user to input
	public static int askForInput(int lb, int ub)
	{

		int choice;

		boolean cond = false;

		do
		{
			choice = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));

			if (std.cin.fail() || choice < lb || choice > ub)
			{
				System.out.print("Not a valid input. Try again.");
				System.out.print("\n");
			}
			else
			{
				cond = true;
			}

			std.cin.clear();
			std.cin.ignore();

		}while (!cond);
		System.out.print("\n");

		return choice;
	}
	public static String askForInput()
	{

		String choice;

		boolean cool = false;

		while (!cool)
		{

			choice = ConsoleInput.readToWhiteSpace(true);

			if (std.cin.fail())
			{
				System.out.print("Not a valid input. Try again.");
				System.out.print("\n");
			}
			else
			{
				cool = true;
			}

			std.cin.clear();
			std.cin.ignore();
		}

		System.out.print("\n");
		return choice;
	}

	public static void main(String[] args)
	{

		//seed random
	//C++ TO JAVA CONVERTER WARNING: Unsigned integer types have no direct equivalent in Java:
	//ORIGINAL LINE: std::srand((unsigned int)time(0));
		tangible.RandomNumbers.seed((int)time(0));
		boolean playAgain = true;

		//create player
		Character player = new Character(30, 1, 1);

		//show title and ask for name
		System.out.print("\n");
		System.out.print("Welcome to A NORMAL THURSDAY NIGHT!");
		System.out.print("\n");
		System.out.print("\n");
		System.out.print("What is your name? ");
		player.name = askForInput();

		do
		{
			//fight demons
			demonArena(player);

			//shop in heaven
			playAgain = heavenIsCapitalist(player);

		} while (playAgain);

		System.out.print(player.name);
		System.out.print(" falls to the depths of Hell. ");
		System.out.print("\n");
		System.out.print("Satan is the one laughing now.");
		System.out.print("\n");
		System.out.print("\n");
		System.out.print("Thanks for playing A NORMAL THURSDAY NIGHT!");
		System.out.print("\n");

	}
	//
	// Created by Zachary James Gospe on 10/22/16.
	//


	//size of new Modifier arrays
	public static final int BASENAMESSIZE = 50;
	public static final int PNAMESSIZE = 20;
	public static final int SNAMESSIZE = 11;

	//Make and keep track of Modifiers in an array
	//Modifiers to be used to randomly generate items
	//(PrefixBaseSuffix?, name, damage bonus, ac bonus, use bonus, dam mult, ac mult)
	public static final Modifier[] baseNames = {new Modifier(1, "Pillow", 0, 1, 0, 0.75, 1), new Modifier(1, "Severed Head", 2, 0, 0, 1.1, .75), new Modifier(1, "Thumbtack", 2, 0, 0, 1, 0), new Modifier(1, "Stale Bread", 0, 0, 0, .75, .75), new Modifier(1, "Fly Swatter", 2, 0, 1, 1, .75), new Modifier(1, "Baseball Bat", 3, 0, 1, 1.25, 1), new Modifier(1, "Waffle Iron", 2, 1, 0, 1, 1), new Modifier(1, "Saxophone", 5, 1, 0, 1, 1), new Modifier(1, "Bowling Ball", 2, 0, 0, 1.25, .75), new Modifier(1, "Tazer", 3, 0, 1, 1.25, 1), new Modifier(1, "Pickaxe", 5, 0, 1, 1.25, .75), new Modifier(1, "Steak Knife", 4, 0, 0, 1, 0.5), new Modifier(1, "Mace", 5, 0, 1, 1.25, 1), new Modifier(1, "Icepick", 3, 0, 1, 1.25, 1), new Modifier(1, "Gatling Gun", 5, 0, 0, 1.75, 1), new Modifier(1, "Boomerang", 2, 0, 3, 1, 1), new Modifier(1, "Whip", 3, 0, 0, 1.5, 1), new Modifier(1, "Sword", 3, 1, 1, 1.5, 1), new Modifier(1, "Broadsword", 6, 2, 0, 1.5, 1), new Modifier(1, "Hand Grenade", 10, 0, -1, 1.5, 0), new Modifier(1, "Sniper Rifle", 5, 0, 0, 2, .25), new Modifier(1, "Lazer Gun", 3, 0, 1, 1.5, 1), new Modifier(1, "RPG Launcher", 10, 0, -1, 1.5, .25), new Modifier(1, "Bible", 0, 3, 0, 0.5, 1.75), new Modifier(1, "Sweater", 0, 2, 0, 0, 1.25), new Modifier(1, "Shorts", 0, 1, 0, 0, 1.25), new Modifier(1, "Bucket", 1, 2, 1, 0.5, 1.25), new Modifier(1, "Raincoat", 0, 2, 1, 0.25, 1.25), new Modifier(1, "Plastic Cup", 0, 0, 0, .25, 1.25), new Modifier(1, "Umbrella", 2, 1, 0, 1, 1.25), new Modifier(1, "Car Door", 3, 3, 1, 1, 1), new Modifier(1, "Shield", 2, 5, 1, .75, 1.5), new Modifier(1, "Helmet", 0, 5, 1, .5, 1.5), new Modifier(1, "Boots", 1, 4, 0, .75, 1.25), new Modifier(1, "Chain Mail", 0, 5, 1, 0, 1.5), new Modifier(1, "Plate Mail", 0, 7, 1, 0, 1.5), new Modifier(1, "Bulletproof Vest", 0, 8, 0, 0, 1.5), new Modifier(1, "Flak Jacket", 0, 8, -1, 0, 2), new Modifier(1, "Eyeball", 0, 0, 0, .25, 0), new Modifier(1, "Femur", 1, 0, 0, .25, .25), new Modifier(1, "Potato", 1, 1, 1, .25, .25), new Modifier(1, "Pizza", 0, 0, -1, .5, .5), new Modifier(1, "Potted Plant", 2, 2, -1, .25, .25), new Modifier(1, "Water Gun", 0, 0, 0, 1, .25), new Modifier(1, "Dirty Laundry", 0, 2, 0, .25, 1), new Modifier(1, "Monkey", 5, 2, -1, 1, 1), new Modifier(1, "Bad Attitude", 5, 2, 0, 1.5, 1), new Modifier(1, "Positive Mindset", 2, 5, 0, 1, 1.5), new Modifier(1, "Logical Thinking", 0, 10, 0, .75, 1.5), new Modifier(1, "Rational Argument", 5, 5, 0, 1.5, .75)};

	public static final Modifier[] prefixNames = {new Modifier(0, "Golden", 0, 0, 2, 1.25, 1.25), new Modifier(0, "Shiny", 0, 0, 2, 1, 1), new Modifier(0, "Sharpened", 2, 0, 0, 1.25, 1), new Modifier(0, "Gargantuan", 3, 3, 1, 1.5, 1.5), new Modifier(0, "Deadly", 5, 0, 0, 1.5, 1), new Modifier(0, "Atomic", 10, 0, -1, 1.5, 0.5), new Modifier(0, "Legendary", 3, 3, 0, 1.5, 1.5), new Modifier(0, "Fireproof", 0, 3, 0, 1, 1.5), new Modifier(0, "Titanium", 2, 2, 1, 1.25, 1.25), new Modifier(0, "Dependable", 0, 5, 3, 1, 1), new Modifier(0, "Ancient", 0, 0, -1, 1.25, 1.25), new Modifier(0, "Satanic", 5, 0, 0, 2, .25), new Modifier(0, "Holy", 0, 5, 1, .25, 2), new Modifier(0, "Glorious", 0, 3, 0, 1, 1.75), new Modifier(0, "Imaginary", 0, 0, 10, .25, .25), new Modifier(0, "Tiny", 0, 0, 1, .5, .5), new Modifier(0, "Disgusting", 2, 2, -1, 1.25, 1.25), new Modifier(0, "Simple", 2, 2, 0, 1, 1), new Modifier(0, "Unremarkable", 0, 0, 2, 1, 1), new Modifier(0, "Delicate", 0, 0, -1, 1, 1)};

	public static final Modifier[] suffixNames = {new Modifier(2, "of Strength", 5, 0, 0, 1.5, .5), new Modifier(2, "of Protection", 0, 5, 0, .5, 1.5), new Modifier(2, "of Endless Conquest", 0, 0, 3, 1, 1), new Modifier(2, "of Purity", 0, 5, 0, 1.25, 1.25), new Modifier(2, "of Courage", 3, 3, 1, 1.25, 1.25), new Modifier(2, "of the Abyss", 5, 0, 0, 1.25, .75), new Modifier(2, "Piñata", 0, 0, 0, .25, .25), new Modifier(2, "of Destruction", 0, 0, 0, 2, .5), new Modifier(2, "of Questionable Origin", 5, 5, 0, 1, 1), new Modifier(2, "of Power", 5, 5, 0, 1.5, 1.5), new Modifier(2, "of Diplomacy", 0, 10, 2, .25, 2)};
}