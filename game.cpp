// This is the main file for the game logic and function
//
//
// This is the main file for the game logic and function
//
//
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

// Console object
Console console(90, 50, "NamCap");

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNTbv];
PMAP pacMap;
PMAP pacMap2;
PMAP pacMap3;
PMAP introMap;
PMAP introMap2;
PMAP introMap3;
const int ciOffsetX=20;
const int ciOffsetY=5;

int		g_iChangeMod = 1;
int		g_iChangeCol = 1;
int		g_iauto = 2;
bool	g_bOrigin = false;
bool	g_bCoin = false;

COORD ghost1;
COORD ghost2;
COORD ghost3;

COORD ghost4;
COORD ghost5;
COORD ghost6;
COORD ghost7;
COORD ghost8;
COORD ghost9;
//COORD ghost10;
int g_idirection;
int g_idirection2;
int g_idirection3;
int g_idirection4;
int g_idirection5;
int g_idirection6;
int g_idirection7;
int g_idirection8;
int g_idirection9;
//int g_idirection10;


extern stage state;
extern Console console;

extern unsigned char coin;
int score = 0;
int score2=0;

// Game specific variables here
COORD tp1;
COORD tp2;
COORD charLocation;
COORD charLocation2;
char* maps[]={"map.txt\0","map2.txt\0","map3.txt\0","3.txt\0","2.txt\0","1.txt\0","GAMEOVER.txt\0","PD1.txt\0","PD2.txt\0","PD3.txt\0","map5.txt\0"};
int Lives = 1;
int RespawnRate = 0;
int RespawnTF = 5;
int SpawnRate = 10;
int MaxGhostCount = 10;
int GhostSpeed = 1;

// Initialize variables, allocate memory, load data from file, etc. 
// This is called once before entering into your main loop
void init()
{   
		PlaySound(NULL,0,0);
		PlaySound(TEXT("pacman_beginning"),NULL,SND_LOOP|SND_ASYNC);
		elapsedTime=0.0;
		
        charLocation.X = 38;
        charLocation.Y = 20;

	    charLocation2.X = 38;
        charLocation2.Y = 13;

        ghost1.X=39;
        ghost1.Y=13;

        ghost2.X=2+ciOffsetX;
        ghost2.Y=2+ciOffsetY;

        ghost3.X=36+ciOffsetX;
        ghost3.Y=19+ciOffsetY;

        srand(time(NULL));
        g_idirection=rand()%4;
        g_idirection2=rand()%4;
        g_idirection3=rand()%4;
    // sets the width, height and the font name to use in the console
    console.setConsoleFont(10, 20, L"Raster Fonts");
}

void init_menu(stage changeState){
    	PlaySound(NULL,0,0);
		PlaySound(TEXT("pacman_beginning"),NULL,SND_LOOP|SND_ASYNC);
		elapsedTime=0.0;
        state=changeState;
}

void init_PVP_stage1(stage changeState){
     elapsedTime = 0.0;
        pacMap=load_map(1);
		PlaySound(NULL,0,0);
		PlaySound(TEXT("Super Mario Bros. Original Theme by Nintendo.wav"),NULL,SND_LOOP|SND_ASYNC);
        charLocation.X = 38;
        charLocation.Y = 20;

	    charLocation2.X = 39;
        charLocation2.Y = 13;

        ghost1.X=39;
        ghost1.Y=13;

        ghost2.X=2+ciOffsetX;
        ghost2.Y=2+ciOffsetY;

        ghost3.X=36+ciOffsetX;
        ghost3.Y=19+ciOffsetY;

        srand(time(NULL));
        g_idirection=rand()%4;
        g_idirection2=rand()%4;
        g_idirection3=rand()%4;
        state=changeState;
}

void init_PVP_stage2(stage changeState){
        elapsedTime = 0.0;
        pacMap=load_map(0);
		PlaySound(NULL,0,0);
		PlaySound(TEXT("Super Mario Bros. Original Theme by Nintendo.wav"),NULL,SND_LOOP|SND_ASYNC);
        charLocation.X = 38;
        charLocation.Y = 20;

	    charLocation2.X = 39;
        charLocation2.Y = 13;

        ghost1.X=39;
        ghost1.Y=13;

        ghost2.X=2+ciOffsetX;
        ghost2.Y=2+ciOffsetY;

        ghost3.X=36+ciOffsetX;
        ghost3.Y=19+ciOffsetY;

        srand(time(NULL));
        g_idirection=rand()%4;
        g_idirection2=rand()%4;
        g_idirection3=rand()%4;

        tp1.X=0+ciOffsetX;
        tp1.Y=9+ciOffsetY;
        tp2.X=37+ciOffsetX;
        tp2.Y=9+ciOffsetY;
        state=changeState;
}

void init_countdown321(stage changeState)
{
	 elapsedTime = 0.0;
	 PlaySound(NULL,0,0);
	 PlaySound(TEXT("Mario Kart Race Start.wav"),NULL,SND_ASYNC);
	 pacMap= load_map(3);
	 pacMap2= load_map(4);
	 pacMap3= load_map(5);
     state=changeState;
}

// Do your clean up of memory here
// This is called once just before the game exits
void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    console.clearBuffer();
}
/*
	This function checks if any key had been pressed since the last time we checked
	If a key is pressed, the value for that particular key will be true
	
	Add more keys to the enum in game.h if you need to detect more keys
	To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
	For Alphanumeric keys, the values are their ascii values (uppercase).
*/
void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VK_UP);
    keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
    keyPressed[K_M] = isKeyPressed(0x4D);
	keyPressed[K_N] = isKeyPressed(0x4E);

	keyPressed[K_W] = isKeyPressed(0x57);
    keyPressed[K_S] = isKeyPressed(0x53);
    keyPressed[K_A] = isKeyPressed(0x41);
    keyPressed[K_D] = isKeyPressed(0x44);
	keyPressed[K_ENTER]=isKeyPressed(0x0D);
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

/*
	This is the update function
	double dt - This is the amount of time in seconds since the previous call was made

	Game logic should be done here.
	Such as collision checks, determining the position of your game characters, status updates, etc
	If there are any calls to write to the console here, then you are doing it wrong.

    If your game has multiple states, you should determine the current state, and call the relevant function here.
*/
void update(double dt, stage state)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter(state);// moves the character, collision detection, physics, etc

    // sound can be played here too.
}


double timer(double& seconds)
{
    seconds -= deltaTime;
    return seconds;
}

/*
    This is the render loop
    At this point, you should know exactly what to draw onto the screen.
    Just draw it!
    To get an idea of the values for colours, look at console.h and the URL listed there
*/

void render(stage state)
{
    clearScreen();      // clears the current screen and draw from scratch
    switch(state){
		case intro:
			renderIntro(INIT_menu);
			break;
        case menu:
            renderMainMenu();
            break;
		case settings:
			renderSettings();
			break;
		case settings_PVP:
			renderSettings_PVP();
			break;
		case settings_COOP:
			renderSettings_COOP();
			break;
		case settings_Survival:
			renderSettings_Survival();
			break;
		case settings_Infection:
			renderSettings_Infection();
			break;
		case countPVP1:
			rendercountdown321(INIT_PVP_stage1);
			break;
		case countPVP2:
			rendercountdown321(INIT_PVP_stage2);
			break;
		case countSurvival:
			rendercountdown321(INIT_stage_survival);
			break;
		case countCOOP:
			rendercountdown321(INIT_COOP_stage);
			break;
		case countInfection:
			rendercountdown321(INIT_infection);
			break;
		case stage_survival:
			renderMapSurvival();
			renderCharacterSurvival();
			break;
        case PVP_stage1:
            renderMap();
            renderCharacter(); 
            break;
        case transition: 
            render_transition();
            break;
        case PVP_stage2:
            renderMap();
            renderCharacter(); 
            break;
		case COOP_stage:
			renderMap();
			renderCoopCharacter();
			coopWinCon();
			break;
		case COOP_end:
			renderEndCondition();
			break;
        case infection:
            renderMap();
            renderCharacter_infection();
			break;
        case end:
            render_end();
            break;
		case end2:
            render_end2();
            break;
		case end_survivors:
			render_end_survivors();
			break;
		case end_infectants:
			render_end_infectants();
			break;
    }
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void renderMainMenu()
{   
	console.writeToBuffer(25,15,"Press Enter to go to Settings",0x0F);
	console.writeToBuffer(25,17,"Press LEFT to play PVP",0x0F);
	console.writeToBuffer(25,18,"Press DOWN to play Survival",0x0F);
	console.writeToBuffer(25,19,"Press RIGHT to play COOP",0x0F);
    console.writeToBuffer(25,20,"Press UP to play Infection",0x0F);
}

void renderSettings()
{
	console.writeToBuffer(25,15,"Press ENTER to go back to Menu",0x0F);
	console.writeToBuffer(25,17,"Press LEFT to change PVP Settings",0x0F);
	console.writeToBuffer(25,18,"Press DOWN to change Survival Settings",0x0F);
	console.writeToBuffer(25,19,"Press RIGHT to change COOP Settings",0x0F);
    console.writeToBuffer(25,20,"Press UP to change Infection Settings",0x0F);
}

void renderSettings_PVP()
{
	console.writeToBuffer(25,15,"Press ENTER to go back to Settings",0x0F);
	console.writeToBuffer(25,17,"Press Up to increase Ghost Speed",0x0F);
	console.writeToBuffer(25,18,"Press Down to decrease Ghost Speed",0x0F);
	console.writeToBuffer(25,19,"Ghost Speed:",0x0F);
	console.writeToBuffer(37,19,GhostSpeed,0x0F);
	console.writeToBuffer(25,20,"Press Right to increase Lives",0x0F);
	console.writeToBuffer(25,21,"Press Left to decrease Lives",0x0F);
	console.writeToBuffer(25,22,"Lives:",0x0F);
	console.writeToBuffer(32,22,Lives,0x0F);
}

void renderSettings_COOP()
{
	console.writeToBuffer(25,15,"Press Enter to go back to Settings",0x0F);
	console.writeToBuffer(25,17,"Press Up to increase Revive Timeframe",0x0F);
	console.writeToBuffer(25,18,"Press Down to decrease Revive Timeframe",0x0F);
	console.writeToBuffer(25,19,"Timeframe:",0x0F);
	console.writeToBuffer(36,19,RespawnTF,0x0F);
	console.writeToBuffer(25,20,"Press Right to increase Revive Time Required",0x0F);
	console.writeToBuffer(25,21,"Press Left to decrease Revive Time Required",0x0F);
	console.writeToBuffer(25,22,"Time Required:",0x0F);
	console.writeToBuffer(39,22,RespawnRate,0x0F);

}

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

void renderSettings_Infection()
{
	console.writeToBuffer(25,15,"Nothing to change here :P",0x0F);
	console.writeToBuffer(25,17,"Press ENTER to go back to Settings",0x0F);
}

void rendercountdown321(stage changeState)
{
	colour(0x0F);
	if(elapsedTime <=1)
	{
		insertmap(pacMap);
	}

	if(elapsedTime <=2 && elapsedTime >1)
	{
		insertmap(pacMap2);
	}
	
	if(elapsedTime <=3 && elapsedTime >2)
	{
		insertmap(pacMap3);
	}
	if(elapsedTime >= 3)
	{
		state = changeState;
	}
}

void render_transition()
{
	console.writeToBuffer(25,15,"Player 2 Ready? Press Enter!",0x0F);         
}

void moveCharacter_menu(){
		if (keyPressed[K_ENTER])
		{
			state = settings;
		}
        if (keyPressed[K_LEFT])
	    {
		    state = INIT_countPVP1;
	    }
		if (keyPressed[K_DOWN])
	    {
		    state = INIT_countSurvival;
	    }
		if (keyPressed[K_RIGHT])
	    {
		    state = INIT_countCOOP;
	    }
        if(keyPressed[K_UP]){
            state = INIT_countInfection;
        }
}

void moveCharacter_settings(){
		if (keyPressed[K_ENTER])
		{
			state = menu;
		}
        if (keyPressed[K_LEFT])
	    {
		    state = settings_PVP;
	    }
		if (keyPressed[K_DOWN])
	    {
		    state = settings_Survival;
	    }
		if (keyPressed[K_RIGHT])
	    {
		    state = settings_COOP;
	    }
        if(keyPressed[K_UP]){
            state = settings_Infection;
        }
}

void moveCharacter_settings_PVP(){
		if (keyPressed[K_ENTER])
		{
			state = settings;
		}
        if (keyPressed[K_LEFT])
	    {
			if (Lives > 1)
			{
				Lives -= 1;
			}
	    }
		if (keyPressed[K_DOWN])
	    {
			if (GhostSpeed > 1)
			{
				GhostSpeed -= 1;
			}
	    }
		if (keyPressed[K_RIGHT])
	    {
		    Lives += 1;
	    }
        if(keyPressed[K_UP]){
            GhostSpeed += 1;
        }
}

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

void moveCharacter_settings_Infection(){
		if (keyPressed[K_ENTER])
		{
			state = settings;
		}
}

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

void moveCharacter_transition(){
    	if(keyPressed[K_ENTER]){
			state=INIT_countPVP2;
		}
}

void moveCharacter_PVP_stage1(){
    if (keyPressed[K_UP] && charLocation.Y > 0 && wall_up(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.Y--;
        }
        if (keyPressed[K_LEFT] && charLocation.X > 0 && wall_left(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.X--;
        }
        if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && wall_down(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.Y++;
        }
        if (keyPressed[K_RIGHT] && charLocation.X < console.getConsoleSize().X - 1 && wall_right(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.X++;
        }
    
	    if(keyPressed[K_M])
	    {
		    g_iChangeMod += 1;
	    }
	    if(keyPressed[K_N])
	    {
		    g_iChangeCol += 1;
	    }



	    if (keyPressed[K_W])
	    {
		    g_iauto = 1;
	    }
	    if (g_iauto == 1 && charLocation2.Y > 0 && wall_up(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.Y--;

        }

	    if (keyPressed[K_A])
	    {
		    g_iauto = 2;
	    }
	    if (g_iauto == 2 && charLocation2.X > 0 && wall_left(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.X--; 

        }

	    if (keyPressed[K_S])
	    {
		    g_iauto = 3;
	    }

        if (g_iauto == 3 && charLocation2.Y < console.getConsoleSize().X - 1 && wall_down(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.Y++; 
        }

	    if (keyPressed[K_D])
	    {
		    g_iauto = 4;
	    }

        if (g_iauto == 4 && charLocation2.X < console.getConsoleSize().X  - 1 && wall_right(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.X++; 
        }
        
        monster(ghost1,g_idirection);
        monster(ghost2,g_idirection2);
        monster(ghost3,g_idirection3);
}

void moveCharacter_PVP_stage2(){
    if (keyPressed[K_W] && charLocation.Y > 0 && wall_up(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.Y--;
        }
        if (keyPressed[K_A] && charLocation.X > 0 && wall_left(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.X--;
        }
        if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && wall_down(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.Y++;
        }
        if (keyPressed[K_D] && charLocation.X < console.getConsoleSize().X - 1 && wall_right(charLocation)==false)
        {
            //Beep(1440, 30);
            charLocation.X++;
        }
    
	    if(keyPressed[K_M])
	    {
		    g_iChangeMod += 1;
	    }
	    if(keyPressed[K_N])
	    {
		    g_iChangeCol += 1;
	    }



	    if (keyPressed[K_UP])
	    {
		    g_iauto = 1;
	    }
	    if (g_iauto == 1 && charLocation2.Y > 0 && wall_up(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.Y--;

        }

	    if (keyPressed[K_LEFT])
	    {
		    g_iauto = 2;
	    }
	    if (g_iauto == 2 && charLocation2.X > 0 && wall_left(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.X--; 

        }

	    if (keyPressed[K_DOWN])
	    {
		    g_iauto = 3;
	    }

        if (g_iauto == 3 && charLocation2.Y < console.getConsoleSize().X - 1 && wall_down(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.Y++; 
        }

	    if (keyPressed[K_RIGHT])
	    {
		    g_iauto = 4;
	    }

        if (g_iauto == 4 && charLocation2.X < console.getConsoleSize().X  - 1 && wall_right(charLocation2)==false)
        {
            Beep(1440, 30);
            charLocation2.X++; 
        }
        teleport(ghost1,tp1,tp2);
        teleport(ghost2,tp1,tp2);
        teleport(ghost3,tp1,tp2);
        teleport(charLocation,tp1,tp2);
        teleport(charLocation2,tp1,tp2);
        monster(ghost1,g_idirection);
        monster(ghost2,g_idirection2);
        monster(ghost3,g_idirection3);
}

void moveCharacter_end(){
    if(keyPressed[K_ENTER]){
        state=INIT_menu;
    }
}

void moveCharacter(stage state)
{
    switch(state){
        //init states
        case INIT_intro:
			init_intro(intro);
			break;
        case INIT_menu:
            init_menu(menu);
            break;
        case INIT_stage_survival:
            init_survival(stage_survival);
            break;
		case INIT_countPVP1:
			init_countdown321(countPVP1);
			break;
		case INIT_countPVP2:
			init_countdown321(countPVP2);
			break;
		case INIT_countSurvival:
			init_countdown321(countSurvival);
			break;
		case INIT_countCOOP:
			init_countdown321(countCOOP);
			break;
		case INIT_countInfection:
			init_countdown321(countInfection);
			break;
        case INIT_PVP_stage1:
            init_PVP_stage1(PVP_stage1);
            break;
        case INIT_transition:
            init_menu(transition);
            break;
        case INIT_PVP_stage2:
            init_PVP_stage2(PVP_stage2);
            break;
        case INIT_end:
            init_menu(end);
            break;
        case INIT_end2:
            init_menu(end2);
            break;
        case INIT_COOP_stage:
            init_COOP(COOP_stage);
            break;
        case INIT_COOP_end:
            init_COOP_end(COOP_end);
            break;
        case INIT_infection:
            init_infection(infection);
            break;
		case INIT_end_survivors:
			init_infection_end(end_survivors);
			break;
		case INIT_end_infectants:
			init_infection_end(end_infectants);
			break;
        // actual controls
		case intro:
			break;
        case menu:
            moveCharacter_menu();
            break;
		case settings:
			moveCharacter_settings();
			break;
		case settings_PVP:
			moveCharacter_settings_PVP();
			break;
		case settings_COOP:
			moveCharacter_settings_COOP();
			break;
		case settings_Survival:
			moveCharacter_settings_Survival();
			break;
		case settings_Infection:
			moveCharacter_settings_Infection();
			break;
        case stage_survival:
            moveCharacter_survival();
            break;
        case PVP_stage1:
            moveCharacter_PVP_stage1();
            break;
        case transition:
            moveCharacter_transition();
            break;
        case PVP_stage2:
            moveCharacter_PVP_stage2();
            break;
        case end:
            moveCharacter_end();
            break;
        case end2:
            moveCharacter_end();
            break;
        case COOP_stage:
            moveCharacter_COOP();
            break;
        case COOP_end:
            moveCharacter_end();
			break;
        case infection:
            moveCharacter_infection();
            break;
		case end_survivors:
			moveCharacter_end();
			break;
		case end_infectants:
			moveCharacter_end();
			break;
    }
}

void eneXp1(COORD &ene , COORD &p1)
{
	SHORT x = 38;
	SHORT y = 20;
	SHORT * k = &x;
	SHORT * t = &y;

	if(ene.Y == p1.Y && ene.X == p1.X)
	{
		g_bOrigin = true;
		if(g_bOrigin == true)
		{
			if(state==stage_survival){
				state=INIT_end2;
				PlaySound(NULL,0,0);
				PlaySound(TEXT("Super Mario Bros. - Game Over Sound Effect.wav"),NULL,SND_LOOP|SND_ASYNC);
			}
            if(state==PVP_stage1){
                state=INIT_transition;
				PlaySound(NULL,0,0);
				PlaySound(TEXT("Super Mario Bros. - Game Over Sound Effect.wav"),NULL,SND_LOOP|SND_ASYNC);
            }
            else if(state==PVP_stage2){
                state=INIT_end;
				PlaySound(NULL,0,0);
				PlaySound(TEXT("Super Mario Bros. - Game Over Sound Effect.wav"),NULL,SND_LOOP|SND_ASYNC);
            }
		}
	}
	else if(ene.Y != p1.Y || ene.X != p1.X)
	{
		g_bOrigin = false;
	}
}


bool p1Xcoin(COORD location)
{
	if(pacMap->data[location.Y-ciOffsetY][location.X-ciOffsetX] == '0')
	{
		pacMap->data[location.Y-ciOffsetY][location.X-ciOffsetX] = ' ';
        if(state==PVP_stage1){
		    score++;
        }
        if(state==PVP_stage2){
            score2++;
        }
		if(state==COOP_stage){
            score++;
        }
        return true;
    }
	else
	{
        return false;
    }
}

void teleport(COORD& a,COORD b, COORD c){
    
    if (a.X == b.X && a.Y==b.Y){
        a.X = c.X-1;
        a.Y = c.Y;
    }
    if (a.X == c.X && a.Y==c.Y){
        a.X = b.X+1;
        a.Y = b.Y;
    }
}

void processUserInput()
{
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
        g_bQuitGame = true;
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    console.clearBuffer(0x00);
}

void renderMap()
{
    // Set up sample colours, and output shadings
    colour(0x0F);
    insertmap(pacMap);
}

void renderTransition()
{
	colour(0x0F);
}

void render_end(){
       if(score>score2){
            console.writeToBuffer(30,15,"Player one wins",0x0F);
        }
        else if(score < score2){
            console.writeToBuffer(30,15,"Player two wins",0x0F);
        }
}

void renderCharacter()
{
	if(state==stage_survival)
	{
		renderCharacterSurvival();
	}
	if(state==PVP_stage1 || state==PVP_stage2)
	{
		// Draw the location of the character
		console.writeToBuffer(charLocation, (char)g_iChangeMod, 0x0C+g_iChangeCol);
		console.writeToBuffer(ghost1,232,0x0B);
		console.writeToBuffer(ghost2,232,0x0B);
		console.writeToBuffer(ghost3,232,0x0B);
		if(g_iChangeMod > 6)
		{
			g_iChangeMod = 1;
		}
		if(g_iChangeCol > 6)
		{
			g_iChangeCol = 1;
		}
		eneXp1(charLocation2,charLocation);
		eneXp1(ghost1,charLocation);
		eneXp1(ghost2,charLocation);
		eneXp1(ghost3,charLocation);
		p1Xcoin(charLocation);
		teleport(charLocation,tp1,tp2);
		console.writeToBuffer(charLocation2, 148, 0x0C);
	}

	eneXp1(charLocation2,charLocation);
	eneXp1(ghost1,charLocation);
    eneXp1(ghost2,charLocation);
    eneXp1(ghost3,charLocation);
	p1Xcoin(charLocation);
	console.writeToBuffer(charLocation2, 148, 0x0C);

}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / deltaTime << "fps";
    c.X = 35;
    c.Y = 0;
    console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << elapsedTime << "secs";
    c.X = 35;
    c.Y = 1;
    console.writeToBuffer(c, ss.str(), 0x59);
}
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    console.flushBufferToConsole();
}