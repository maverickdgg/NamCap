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

// Console object
Console console(82, 35, "NamCap");

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNTbv];
extern short sPacMap[21][38];
short sCountdown[21][15];
short sCountdown2[21][15];
short sCountdown3[21][15];
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
extern short sPacMap[21][38];
extern short sCountdown[21][15];
extern Console console;

extern unsigned char coin;
int score = 0;
int score2=0;
double countdown = 0.0;
double coutndwodntiemr = 0;

// Game specific variables here
COORD tp1;
COORD tp2;
COORD charLocation;
COORD charLocation2;
char map1[]="map.txt";
char map2[]="map2.txt";
char map3[]="map3.txt";
char countdown3[]="3.txt";
char countdown2[]="2.txt";
char countdown1[]="1.txt";

// Initialize variables, allocate memory, load data from file, etc. 
// This is called once before entering into your main loop
void init()
{   
    elapsedTime=0.0;
	PlaySound(TEXT("pacman_beginning.wav"), NULL,SND_LOOP | SND_ASYNC);
    readfile(sPacMap,map2);

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
    console.setConsoleFont(100, 50, L"RasterFonts");
}

void init_PVP_stage1(){
     elapsedTime = 0.0;
        readfile(sPacMap,map2);

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
}

void init_PVP_stage2(){
        elapsedTime = 0.0;
        readfile(sPacMap,map1);

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
}

void init_countdown321()
{
	elapsedTime = 0.0;

	readExactFile(sCountdown,countdown3);
	readExactFile(sCountdown2,countdown2);
	readExactFile(sCountdown3,countdown1);
}

void init(stage state){
    switch(state){
        case menu:
            init();
            break;
        case stage_survival:
            init_survival();
            break;
		case countPVP1:
			init_countdown321();
			break;
		case countPVP2:
			init_countdown321();
			break;
		case countSurvival:
			init_countdown321();
			break;
		case countCOOP:
			init_countdown321();
			break;
		case countInfection:
			init_countdown321();
			break;
        case PVP_stage1:
            init_PVP_stage1();
            break;
        case transition:
            init();
            break;
        case PVP_stage2:
            init_PVP_stage2();
            break;
        case end:
            init();
            break;
        case end2:
            init();
            break;
        case COOP_stage:
            init_COOP();
            break;
        case COOP_end:
            init();
            break;
        case infection:
            init_infection();
            break;
    }
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
        case menu:
            renderMainMenu();
            break;
		case countPVP1:
			rendercountdown321(PVP_stage1);
			break;
		case countPVP2:
			rendercountdown321(PVP_stage2);
			break;
		case countSurvival:
			rendercountdown321(stage_survival);
			break;
		case countCOOP:
			rendercountdown321(COOP_stage);
			break;
		case countInfection:
			rendercountdown321(infection);
			break;
		//case count3:
		//	rendercountdown3();
		//	break;
		//case count2:
		//	rendercountdown2();
		//	break;
		//case count1:
		//	rendercountdown1();
		//	break;
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
        case end:
            render_end();
            break;
		case end2:
            render_end2();
            break;
    }
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void renderMainMenu()
{   
	console.writeToBuffer(25,17,"Press LEFT to play PVP",0x0F);
	console.writeToBuffer(25,18,"Press DOWN to play Survival",0x0F);
	console.writeToBuffer(25,19,"Press RIGHT to play COOP",0x0F);
    console.writeToBuffer(25,20,"Press UP to play Infection",0x0F);
}

void rendercountdown321(stage changeState)
{
	colour(0x0F);
	if(elapsedTime <=1)
	{
		printExactFile(sCountdown);
	}

	if(elapsedTime <=2 && elapsedTime >1)
	{
		printExactFile(sCountdown2);
	}
	
	if(elapsedTime <=3 && elapsedTime >2)
	{
		printExactFile(sCountdown3);
	}
	if(elapsedTime >= 3)
	{
		state=changeState;
	}
}


void render_transition()
{
	console.writeToBuffer(25,15,"Player 2 Ready? Press Enter!",0x0F);         
}

void moveCharacter_menu(){
        if (keyPressed[K_LEFT])
	    {
		    state = countPVP1;
	    }
		if (keyPressed[K_DOWN])
	    {
		    state = countSurvival;
	    }
		if (keyPressed[K_RIGHT])
	    {
		    state = countCOOP;
	    }
        if(keyPressed[K_UP]){
            state = countInfection;
        }
}

void moveCharacter_transition(){
    	if(keyPressed[K_ENTER]){
			state=PVP_stage2;
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
}

void moveCharacter_end(){
    if(keyPressed[K_ENTER]){
        state=menu;
    }
}

void moveCharacter(stage state)
{
    // Updating the location of the character based on the key press
    // switches constrols based on state
    switch(state){
        case menu:
            moveCharacter_menu();
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
        case infection:
            moveCharacter_infection();
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
				state=end2;
			}
            if(state==PVP_stage1){
                state=transition;
            }
            else if(state==PVP_stage2){
                state=end;
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
	if(sPacMap[location.Y-ciOffsetY][location.X-ciOffsetX] == 0)
	{
		sPacMap[location.Y-ciOffsetY][location.X-ciOffsetX] = ' ';
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
    insertmap(sPacMap);
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