#include"ai.h"
#include "game.h"

extern short sPacMap[21][38];
extern Console console;
const int ciOffsetX = 20;
const int ciOffsetY = 5;
extern PMAP pacMap;

int reroll(int& x)
{
    x=rand()%4;
    return x;
}

//Done By Daniel(Leader)
//check the monster location and the direction they go 
void monster(COORD& monster1,int& g_idirection)
{
    bool bcollision = false;
	//check the condition met  
    if(bcollision == false)
	{
		if(g_idirection == 0)
		{
			//when the condition met
			if(wall_left(monster1) == true)
			{
				bcollision = true;
			}
			else
			{ 
				monster1.X--;
			}
            }
            if(g_idirection == 1)
            {
                if(wall_right(monster1) == true)
				{
                    bcollision=true;
                }
                else
				{
					monster1.X++;
                }
            }
            if(g_idirection==2)
            {
               if(wall_down(monster1) == true)
			   {
				   bcollision=true;
			   }
			   else
			   {
				   monster1.Y++;
			   }
            }
            if(g_idirection == 3)
            {
                if(wall_up(monster1) == true)
				{
                    bcollision=true;
                }
                else
				{
					monster1.Y--;
                }
            }
			//check what wall they hit 
            if(wall_up(monster1) == false && wall_down(monster1) == false && wall_left(monster1) == false && wall_right(monster1) == false)
			{
                bcollision=true;
            }
            if(wall_up(monster1) == false && wall_down(monster1) == false && wall_left(monster1) == false)
			{
                bcollision=true;
            }
            if(wall_up(monster1) == false && wall_down(monster1) == false && wall_right(monster1) == false)
			{
                bcollision=true;
            }
            if(wall_up(monster1) == false && wall_left(monster1) == false && wall_right(monster1) == false)
			{
                bcollision=true;
            }
            if(wall_down(monster1) == false && wall_left(monster1) == false && wall_right(monster1) == false)
			{
                bcollision=true;
            }
    }
	//if the monster is going against the wall re-roll the direction
    if(bcollision == true)
	{
        reroll(g_idirection);
    }
}


//Done By Daniel(Leader)\
//check what kind of wall 
bool wall_left(COORD location)
{
    if(pacMap -> data[location.Y - ciOffsetY][location.X -1 - ciOffsetX] == '1')
	{
        return true;
    }
    else
	{
        return false;
    }
}


//Done By Daniel(Leader)
//check what kind of wall 
bool wall_right(COORD location)
{
    if(pacMap -> data[location.Y - ciOffsetY][location.X + 1- ciOffsetX] == '1')
	{
        return true;
    }
    else
	{
        return false;
    }
}


//Done By Daniel(Leader)
//check what kind of wall 
bool wall_up(COORD location)
{
    if(pacMap -> data[location.Y - 1 - ciOffsetY][location.X - ciOffsetX] == '1')
	{
        return true;
    }
    else
	{
        return false;
    }
}


//Done By Daniel(Leader)
//check what kind of wall 
bool wall_down(COORD location)
{
    if(pacMap -> data[location.Y + 1 - ciOffsetY][location.X - ciOffsetX] == '1')
	{
        return true;
    }
    else
	{
        return false;
    }
}
