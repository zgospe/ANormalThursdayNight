package src;
import java.util.*;

//
// Created by Zachary James Gospe on 10/20/16.
//

//
// Created by Zachary James Gospe on 10/20/16.
//

/*
 * A super class defining the characteristics
 * of all types of actions, those being weapons,
 * armors, and miscellaneous.
 */



public class Item
{


	//potential qualities of an item
	private int dam;
	private int ac;
	private int uses;
	private int itemLevel;

	//Breaks the item, adds the "Broken"
	//modifier to the beginning of the item
	//and cuts all stats in half.

	//Breaks the item, adds the "Broken"
	//modifier to the beginning of the item
	//and cuts all stats in half. (Uses are then
	//upped to 1 so the broken item can be used).
	private void breakItem()
	{
		dam /= 2;
		ac /= 2;
		uses = 2;

		System.out.print(name);
		System.out.print(" breaks!");
		System.out.print("\n");

		if (name.substring(0, 6).equals("Broken") || name.substring(0, 6).equals("Very B"))
		{
			name = "Very " + name;
		}
		else if (name.substring(0, 9).equals("Very Very"))
		{
			name = "Garbage With Sentimental Value";
		}
		else
		{
			name = "Broken " + name;
		}
	}

	public String name;

	//generates a random item based on item level
	//using the arrays of potential modifiers

	//randomly generates an item
	public Item(int itemLevel)
	{
			//bmi
		this.dam = tangible.RandomNumbers.nextNumber() % (itemLevel / 2 + 2);
		this.ac = tangible.RandomNumbers.nextNumber() % (itemLevel / 2 + 2);
		this.uses = 3;
		this.name = "";

		//pick mod
		int baseMod = tangible.RandomNumbers.nextNumber() % GlobalMembers.BASENAMESSIZE;


		//modify
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: modify(baseNames[baseMod]);
		GlobalMembers member = new GlobalMembers();
		Modifier a = new Modifier(member.baseNames[baseMod]);
		modify(new Modifier(GlobalMembers.baseNames[baseMod]));

		//pick aux mods
		int otherMods = tangible.RandomNumbers.nextNumber() % 100;
		//more likely to get rare items as game goes on
		otherMods += itemLevel;

		if (otherMods >= 70 && otherMods < 80)
		{
			int suffMod = tangible.RandomNumbers.nextNumber() % GlobalMembers.SNAMESSIZE;
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: modify(suffixNames[suffMod]);
			modify(new Modifier(GlobalMembers.suffixNames[suffMod]));

		}
		else if (otherMods >= 80 && otherMods < 90)
		{
			int preMod = tangible.RandomNumbers.nextNumber() % GlobalMembers.PNAMESSIZE;
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: modify(prefixNames[preMod]);
			modify(new Modifier(GlobalMembers.prefixNames[preMod]));

		}
		else if (otherMods >= 90)
		{
			int preMod = tangible.RandomNumbers.nextNumber() % GlobalMembers.PNAMESSIZE;
			int suffMod = tangible.RandomNumbers.nextNumber() % GlobalMembers.SNAMESSIZE;

//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: modify(suffixNames[suffMod]);
			modify(new Modifier(GlobalMembers.suffixNames[suffMod]));
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: modify(prefixNames[preMod]);
			modify(new Modifier(GlobalMembers.prefixNames[preMod]));
		}
	}

	//alt constructor, player's fists

	//for empty weapon slots, makes a left or right fist
	//must specify Left or Right in the string
	public Item(String leftorright, int fistDamage)
	{
		this.name = leftorright + " Fist";
		this.dam = fistDamage;
		this.uses = 5;
		this.ac = 0;
		this.itemLevel = fistDamage;
	}

	//returns the item's damage

	//returns the damage value of the item
	public final int getDam()
	{
		return dam;
	}

	//returns the item's protection

	//returns the armor value of the item
	public final int getAC()
	{
		return ac;
	}

	public final void setDam(int newDam)
	{
		dam = newDam;
	}

	public final void setAC(int newAC)
	{
		ac = newAC;
	}

	public final void setUse(int newUse)
	{
		uses = newUse;
	}

	//reduces the item's usage, and
	//if it changes zero, adds the "Broken"
	//modifier to the beginning of the item
	//and cuts all stats in half. (Uses are then
	//upped to 1 so the broken item can be used).
	public final void useItem()
	{
		uses--;

		if (uses <= 0)
		{
			breakItem();
		}
	}

	public final void modify(Modifier a)
	{

			if (a.getType() == 0)
			{
				name = a.getName() + " " + name;
			}
			else if (a.getType() == 1)
			{
				name = a.getName();
			}
			else
			{
				name += " " + a.getName();
			}

			dam *= a.getDamMult();
			dam += a.getDamPlus();

			ac *= a.getACMult();
			ac += a.getACPlus();

			uses += a.getUsePlus();

	}

}