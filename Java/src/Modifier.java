package src;
import java.util.*;

//
// Created by Zachary James Gospe on 10/21/16.
//

//
// Created by Zachary James Gospe on 10/21/16.
//
// Description: Class for random item generation,
// establishing modifier values for statistics and effects
// and attaching them to prefixes, base names, and suffixes.



public class Modifier
{


	private String name;

	//represents whether it is a suffix, base, or prefix (0, 1, 2 respectively)
	private int type;

	private int damPlus = 0;
	private int acPlus = 0;
	private int usePlus = 0;

	private double damMult = 1;
	private double acMult = 1;


	//Constructor, given prefix and suffix
	public Modifier(int place, String word)
	{
		this.name = word;
		this.type = place;
		this.damPlus = 0;
		this.acPlus = 0;
		this.usePlus = 0;
		this.damMult = 1;
		this.acMult = 1;
	}

	//Constructor
	public Modifier()
	{
		this.name = "";
		this.type = 1;
		this.damPlus = 0;
		this.acPlus = 0;
		this.usePlus = 0;
		this.damMult = 1;
		this.acMult = 1;
	}

	//Complete Constructor
	public Modifier(int t, String nom, int dP, int aP, int uP, double dM, double aM)
	{
		this.name = nom;
		this.type = t;
		this.damPlus = dP;
		this.acPlus = aP;
		this.usePlus = uP;
		this.damMult = dM;
		this.acMult = aM;
		//nothing left to do
	}

	public final void setName(String String)
	{
		name = String;
	}

	public final void setType(int val)
	{
		type = val;
	}

	public final void setDamPlus(int val)
	{
		damPlus = val;
	}

	public final void setACPlus(int val)
	{
		acPlus = val;
	}

	public final void setUsePlus(int val)
	{
		usePlus = val;
	}

	public final void setDamMult(double val)
	{
		damMult = val;
	}

	public final void setACMult(double val)
	{
		acMult = val;
	}

	public final String getName()
	{
		return name;
	}

	public final int getType()
	{
		return type;
	}

	public final int getDamPlus()
	{
		return damPlus;
	}

	public final int getACPlus()
	{
		return acPlus;
	}

	public final int getUsePlus()
	{
		return usePlus;
	}

	public final double getDamMult()
	{
		return damMult;
	}

	public final double getACMult()
	{
		return acMult;
	}

}