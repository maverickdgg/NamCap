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
#include <iostream>

#include "map.h"


// Console object
Console console(82, 35, "NamCap");

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNTbv];
extern short sPacMap[21][38];
short sMap2[21][38];
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
int g_idirection;
int g_idirection2;
int g_idirection3;
int g_idirection4;
int g_idirection5;
extern stage state;
extern short sPacMap[21][38];
extern Console console;
extern unsigned char coin;
int i = 0;
int score = 0;
int score2=0;

// Game specific variables here
COORD tp1;
COORD tp2;
COORD charLocation;
COORD charLocation2;
char map1[]="map.txt";
char map2[]="map2.txt";
char map3[]="map3.txt";
// Initialize variables, allocate memory, load data from file, etc. 
// This is called once before entering into your main loop
void init(stage state)
{
    // Set precision for floating point output
    charLocation.X=1;
    charLocation.Y=1;
    switch(state){
    case menu:
        elapsedTime = 0.0;
        break;
	case stage_survival:
        elapsedTime = 0.0;
        readfile(sPacMap,map3);

        charLocation.X = 38;
        charLocation.Y = 20;

        ghost1.X=39;
        ghost1.Y=13;

        ghost2.X=2+ciOffsetX;
        ghost2.Y=2+ciOffsetY;

        ghost3.X=36+ciOffsetX;
        ghost3.Y=19+ciOffsetY;

		ghost4.X=23+ciOffsetX;
        ghost4.Y=19+ciOffsetY;

		ghost5.X=15+ciOffsetX;
        ghost5.Y=19+ciOffsetY;

        srand(time(NULL));
        g_idirection=rand()%4;
        g_idirection2=rand()%4;
        g_idirection3=rand()%4;
		g_idirection4=rand()%4;
		g_idirection5=rand()%4;
        break;
    case PVP_stage1:
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
        break;
    case transition:    
        elapsedTime = 0.0;
        break;
    case PVP_stage2:    
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
        break;
    case end:
        elapsedTime = 0.0;
        break;
    }
    // sets the width, height and the font name to use in the console
    console.setConsoleFont(0, 40, L"derp");
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
void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    //processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();// moves the character, collision detection, physics, etc

    // sound can be played here too.
}

void update2(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    // sound can be played here too.
}

void timer(double seconds)
{
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait);
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
            renderMap2();
            renderCharacter(); 
            break;
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
	console.writeToBuffer(10,10,"Press up to play",0x0F);
}

void render_transition()
{
	console.writeToBuffer(25,15,"Player 2 Ready? Press Enter!",0x0F);         
}

void moveCharacter()
{
		if(state == menu)
	{
		if (keyPressed[K_UP])
	    {
		    state = PVP_stage1;
	    }
	}
	if(state==transition){
		if(keyPressed[K_ENTER]){
			state=PVP_stage2;
		}
	}

    if(state==PVP_stage1){
    // Updating the location of the character based on the key press
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
    if(state==PVP_stage2){
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
        
        
    }
	if(state==stage_survival){
        survivalControls();
	}
    monster(ghost1,g_idirection);
    monster(ghost2,g_idirection2);
    monster(ghost3,g_idirection3);


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

//void processUserInput()
//{
//    // quits the game if player hits the escape key
//    if (keyPressed[K_ESCAPE])
//        g_bQuitGame = true;
//}

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

void renderMap2()
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
        else{
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

