#include "game.h"
#include "Framework\console.h"
#include "GameUI.h"
#include "ai.h"
#include "survival.h"
#include "infection.h"
#include <iostream>
#include "coop.h"
#include "map.h"
#include "animation.h"
#include "Settings.h"

extern Console console;

extern bool keyPressed[K_COUNTbv];
extern stage state;

//Done by Jacob
void moveCharacter_settings(){
		if (keyPressed[K_BACKSPACE])
		{
			state = menu;
		}
        if (keyPressed[K_LEFT])
	    {
		    state = settings_PVP;
	    }
		/*if (keyPressed[K_DOWN])
	    {
		    state = settings_Survival;
	    }*/
		if (keyPressed[K_RIGHT])
	    {
		    state = settings_COOP;
	    }
        /*if(keyPressed[K_UP]){
            state = settings_Infection;
        }*/
}

//Done by Jacob
void moveCharacter_settings_PVP(){
		if (keyPressed[K_ENTER])
		{
			state = settings;
		}
        if (keyPressed[K_DOWN])
	    {
			if (Lives > 1)
			{
				Lives -= 1;
			}
	    }
		/*if (keyPressed[K_LEFT])
	    {
			if (GhostSpeed > 1)
			{
				GhostSpeed -= 1;
			}
	    }*/
		if (keyPressed[K_UP])
	    {
		    Lives += 1;
	    }
        /*if(keyPressed[K_RIGHT]){
            GhostSpeed += 1;
        }*/
}

//Done By Jacob
void moveCharacter_settings_Survival(){
		if (keyPressed[K_ENTER])
		{
			state = settings;
		}
        if (keyPressed[K_LEFT])
	    {
			if (MaxGhostCount > 1)
			{
				MaxGhostCount -= 1;
			}
		}
		if (keyPressed[K_DOWN])
	    {
			if (SpawnRate > 1)
			{
				SpawnRate -= 1;
			}
	    }
		if (keyPressed[K_RIGHT])
	    {
		    MaxGhostCount += 1;
	    }
        if(keyPressed[K_UP]){
            SpawnRate += 1;
        }
}

//Done By Jacob
void moveCharacter_settings_Infection(){
		if (keyPressed[K_ENTER])
		{
			state = settings;
		}
}

//Done By Jacob
void moveCharacter_settings_COOP(){
	if (keyPressed[K_ENTER])
		{
			state = settings;
		}
        if (keyPressed[K_LEFT])
	    {
			if(RespawnRate > 0)
			{
				RespawnRate -= 1;
			}
	    }
		if (keyPressed[K_DOWN])
	    {
		    if(RespawnTF > 1)
			{
				RespawnTF -= 1;
			}
	    }
		if (keyPressed[K_RIGHT])
	    {
		    RespawnRate += 1;
	    }
        if(keyPressed[K_UP]){
            RespawnTF += 1;
        }
}

//Done By Jacob
void renderSettings()
{
	console.writeToBuffer(25,15,"Press BACKSPACE to go back to Menu",0x0F);
	console.writeToBuffer(25,17,"Press LEFT to change PVP Settings",0x0F);
	/*console.writeToBuffer(25,18,"Press DOWN to change Survival Settings",0x0F);*/
	console.writeToBuffer(25,19,"Press RIGHT to change COOP Settings",0x0F);
    /*console.writeToBuffer(25,20,"Press UP to change Infection Settings",0x0F);*/
}

//Done By Jacob
void renderSettings_PVP()
{
	console.writeToBuffer(25,15,"Press ENTER to go back to Settings",0x0F);
	console.writeToBuffer(25,17,"Press Up to increase Lives",0x0F);
	console.writeToBuffer(25,18,"Press Down to decrease Lives",0x0F);
	console.writeToBuffer(25,19,"Lives:",0x0F);
	console.writeToBuffer(37,19,Lives,0x0F);
	/*console.writeToBuffer(25,20,"Press Right to increase Ghost Speed",0x0F);
	console.writeToBuffer(25,21,"Press Left to decrease Ghost Speed",0x0F);
	console.writeToBuffer(25,22,"Ghost Speed:",0x0F);
	console.writeToBuffer(32,22,GhostSpeed,0x0F);*/
}

//Done By Jacob
void renderSettings_COOP()
{
	console.writeToBuffer(25,15,"Press Enter to go back to Settings",0x0F);
	console.writeToBuffer(25,17,"Press Up to increase Revive Timeframe",0x0F);
	console.writeToBuffer(25,18,"Press Down to decrease Revive Timeframe",0x0F);
	console.writeToBuffer(25,19,"Timeframe:",0x0F);
	console.writeToBuffer(36,19,RespawnTF,0x0F);
	//console.writeToBuffer(25,20,"Press Right to increase Revive Time Required",0x0F);
	//console.writeToBuffer(25,21,"Press Left to decrease Revive Time Required",0x0F);
	//console.writeToBuffer(25,22,"Time Required:",0x0F);
	//console.writeToBuffer(39,22,RespawnRate,0x0F);

}

//Done By Jacob
void renderSettings_Survival()
{
	console.writeToBuffer(25,15,"Press ENTER to go back to Settings",0x0F);
	console.writeToBuffer(25,17,"Press UP to increase Spawn Time",0x0F);
	console.writeToBuffer(25,18,"Press Down to decrease Spawn Time",0x0F);
	console.writeToBuffer(25,19,"Spawn Time:",0x0F);
	console.writeToBuffer(37,19,SpawnRate,0x0F);
	console.writeToBuffer(25,20,"Press Right to increase Max Ghost",0x0F);
	console.writeToBuffer(25,21,"Press Left to decrease Max Ghost",0x0F);
	console.writeToBuffer(25,22,"Max Ghost Count:",0x0F);
	console.writeToBuffer(41,22,MaxGhostCount,0x0F);
}

//Done By Jacob
void renderSettings_Infection()
{
	console.writeToBuffer(25,15,"Nothing to change here :P",0x0F);
	console.writeToBuffer(25,17,"Press ENTER to go back to Settings",0x0F);
}
