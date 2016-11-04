package src;
import java.util.*;

//
// Created by Zachary James Gospe on 10/20/16.
//

//
// Created by Zachary James Gospe on 10/20/16.
//



public class Character
{


	//basic stats, health, experience, armor
	private int hp;
	private int maxHealth = 30;
	private int xp = 0;
	private int ac;
	private int baseDam;
	private int souls = 0;
	private int startingIL = 0;

	//item slots
	public Item[] equip = {new Item("Right", baseDam), new Item("Left", baseDam), new Item(0), new Item(0)};

	public String name = "";

	//if player has sat through exposition before
	public boolean firstPlay = true;

	public Character(int health, int armor, int damage)
	{
		this.hp = health;
		this.ac = armor;
		this.baseDam = damage;
	}


	//puts 2-4 items in a player's equip slots
	public final void randomEquipment(int itemLevel)
	{

		int itemCount = (int)tangible.RandomNumbers.nextNumber() % 20;

			equip[3] = new Item(itemLevel);

			equip [2] = new Item(itemLevel);

		if (itemCount > 15)
		{
			equip [1] = new Item(itemLevel);
		}
		else
		{
			equip[1].name = name + "'s " + equip[1].name;
		}

		if (itemCount == 20)
		{
			equip[0] = new Item(itemLevel);
		}
		else
		{
			equip[0].name = name + "'s " + equip[0].name;
		}
	}

	public final int getHP()
	{
		return hp;
	}

	public final void loseHP(int damage)
	{
		hp -= damage;
	}

	public final int getXP()
	{
		return (int)xp;
	}

	public final void addXP()
	{
		xp++;
	}

	public final int getAC()
	{
		return ac;
	}

	public final int getDam()
	{
		return baseDam;
	}

	public final int attack(Item weapon)
	{
		return baseDam + weapon.getDam();
	}

	public final void equipItem(int itemSlot, Item a)
	{
		equip[itemSlot] = a;
	}

	public final void showInventory()
	{
		for (int i = 0; i < 4; i++)
		{
			System.out.print((i + 1));
			System.out.print(": ");
			System.out.print(equip[i].name);
			System.out.print(" (Attack: ");
			System.out.print(equip[i].getDam());
			System.out.print(", Defense: ");
			System.out.print(equip[i].getAC());
			System.out.print(")");
			System.out.print("\n");
		}
	}

	public final void showAttackInv()
	{
		for (int i = 0; i < 4; i++)
		{
			System.out.print((i + 1));
			System.out.print(": ");
			System.out.print(equip[i].name);
			System.out.print(" (Attack: ");
			System.out.print(equip[i].getDam());
			System.out.print(")");
			System.out.print("\n");
		}
	}

	public final void showDefenseInv()
	{
		for (int i = 0; i < 4; i++)
		{
			System.out.print((i + 1));
			System.out.print(": ");
			System.out.print(equip[i].name);
			System.out.print(" (Defense: ");
			System.out.print(equip[i].getAC());
			System.out.print(")");
			System.out.print("\n");
		}
	}


	//determines if an object can be afforded (true/false),
	//and spends the required souls if so
	public final boolean spendSouls(int cost)
	{

		if (souls >= cost)
		{
			souls -= cost;
			return true;
		}
		else
		{
			return false;
		}
	}


	//changes xp into souls, sets xp to 0
	public final void gainSouls()
	{

		souls += xp;
		xp = 0;

	}

	public final int getSouls()
	{
		return souls;
	}

	public final int addDam()
	{
		baseDam++;
		return baseDam;
	}

	public final int addAC()
	{
		ac++;
		return ac;
	}

	public final int addToMaxHealth(int amount)
	{
		return (maxHealth + amount);
	}

	public final int getMaxHealth()
	{
		return maxHealth;
	}

	public final void increaseStartingIL(int amount)
	{
		startingIL += amount;
	}

	public final int getStartingIL()
	{
		return startingIL;
	}

	public final void setHP(int amount)
	{
		hp = (int)amount;
	}
}