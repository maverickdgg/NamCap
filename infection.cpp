#include "game.h"
#include "GameUI.h"
#include "infection.h"
#include "ai.h"
#include "map.h"

extern bool keyPressed[K_COUNTbv];
extern Console console;
extern double elapsedTime;
extern double deltaTime;
extern stage state;
extern int score;
extern PMAP pacMap;

extern short sPacMap[21][38];
extern char map1[];
extern const int ciOffsetX;
extern const int ciOffsetY;

extern int g_iChangeMod;
extern int g_iChangeCol;
extern int g_iauto;
int g_iauto2=4;

extern int g_idirection;
extern int g_idirection2;
extern int g_idirection3;
extern COORD tp1;
extern COORD tp2;


const int ciInfect_count=5;
//COORD infectants[ciInfect_count]={charLocation,charLocation2,ghost1,ghost2,ghost3};
//bool bInfection_status[ciInfect_count]={0,0,0,1,0};

double timeLeft=60;

infectants infectantAI_1;
infectants infectantAI_2;
infectants infectantAI_3;
infectants player1;
infectants player2;

infectants* arrInfectants[ciInfect_count]={&player1,&player2,&infectantAI_1,&infectantAI_2,&infectantAI_3};

//Done By Daniel(Leader)
void init_infection(stage changeState){
        elapsedTime = 0.0;
        pacMap=load_map(10);
		PlaySound(TEXT("Star Fox Corneria Theme.wav"),NULL,SND_LOOP|SND_ASYNC);

        arrInfectants[0]->coordinates.X = 38;
        arrInfectants[0]->coordinates.Y = 20;

	    arrInfectants[1]->coordinates.X = 32;
        arrInfectants[1]->coordinates.Y = 10;

        arrInfectants[2]->coordinates.X=39;
        arrInfectants[2]->coordinates.Y=13;

        arrInfectants[3]->coordinates.X=2+ciOffsetX;
        arrInfectants[3]->coordinates.Y=2+ciOffsetY;

        arrInfectants[4]->coordinates.X=36+ciOffsetX;
        arrInfectants[4]->coordinates.Y=19+ciOffsetY;

        srand(time(NULL));
        g_idirection=rand()%4;
        g_idirection2=rand()%4;
        g_idirection3=rand()%4;


    infectantAI_1.bInfect_status=true;
    infectantAI_2.bInfect_status=false;
    infectantAI_3.bInfect_status=false;
    player1.bInfect_status=false;
    player2.bInfect_status=false;


    //arrInfectants[0].bInfect_status=false;
    //arrInfectants[1].bInfect_status=false;
    //arrInfectants[2].bInfect_status=true;
    //arrInfectants[3].bInfect_status=false;
    //arrInfectants[4].bInfect_status=false;
    state=changeState;
}

//Done By Daniel(Leader)
void init_infection_end(stage changeState)
{
	
	PlaySound(NULL,0,0);
	PlaySound(TEXT("Super Mario Bros. - Game Over Sound Effect.wav"),NULL,SND_LOOP|SND_ASYNC);
	 pacMap=load_map(6);
     state=changeState;
}

//Done By Daniel(Leader)
void moveCharacter_infection(){
    if (keyPressed[K_UP] && arrInfectants[0]->coordinates.Y > 0 && wall_up(arrInfectants[0]->coordinates)==false)
        {
            //Beep(1440, 30);
            arrInfectants[0]->coordinates.Y--;
        }
    if (keyPressed[K_LEFT] && arrInfectants[0]->coordinates.X > 0 && wall_left(arrInfectants[0]->coordinates)==false)
        {
            //Beep(1440, 30);
            arrInfectants[0]->coordinates.X--;
        }
    if (keyPressed[K_DOWN]&& arrInfectants[0]->coordinates.Y < console.getConsoleSize().Y - 1 && wall_down(arrInfectants[0]->coordinates)==false)
        {
            //Beep(1440, 30);
            arrInfectants[0]->coordinates.Y++;
        }
    if (keyPressed[K_RIGHT]&& arrInfectants[0]->coordinates.X < console.getConsoleSize().X - 1 && wall_right(arrInfectants[0]->coordinates)==false)
        {
            //Beep(1440, 30);
            arrInfectants[0]->coordinates.X++;
        }
    
	    if(keyPressed[K_M])
	    {
		    g_iChangeMod += 1;
	    }
	    if(keyPressed[K_N])
	    {
		    g_iChangeCol += 1;
	    }



	    if (keyPressed[K_W] && arrInfectants[1]->coordinates.Y > 0 && wall_up(arrInfectants[1]->coordinates)==false)
        {
            Beep(1440, 30);
            arrInfectants[1]->coordinates.Y--;

        }

	    if (keyPressed[K_A] && arrInfectants[1]->coordinates.X > 0 && wall_left(arrInfectants[1]->coordinates)==false)
        {
            Beep(1440, 30);
            arrInfectants[1]->coordinates.X--; 

        }

        if (keyPressed[K_S] && arrInfectants[1]->coordinates.Y < console.getConsoleSize().X - 1 && wall_down(arrInfectants[1]->coordinates)==false)
        {
            Beep(1440, 30);
            arrInfectants[1]->coordinates.Y++; 
        }

        if (keyPressed[K_D] && arrInfectants[1]->coordinates.X < console.getConsoleSize().X  - 1 && wall_right(arrInfectants[1]->coordinates)==false)
        {
            Beep(1440, 30);
            arrInfectants[1]->coordinates.X++; 
        }
    monster(arrInfectants[2]->coordinates,g_idirection);
    monster(arrInfectants[3]->coordinates,g_idirection2);
    monster(arrInfectants[4]->coordinates,g_idirection3);
}

//Done By Daniel(Leader)
bool infected_win(){
    bool checker=true;
    for(int i=0;i<ciInfect_count;++i){
        if(arrInfectants[i]->bInfect_status==0){
            checker=false;
            break;
        }
    }
    return checker;
}


//Done By Daniel(Leader)
void infect_collision(infectants infect1,infectants infect2){
    int i=0;
    int j=0;

    bool bSkipCoord=false;
    if(infect1.coordinates.X==infect2.coordinates.X && infect1.coordinates.Y==infect2.coordinates.Y){
        for(i=0;i<ciInfect_count;++i){
            if(infect1.coordinates.X==arrInfectants[i]->coordinates.X && infect1.coordinates.Y==arrInfectants[i]->coordinates.Y && bSkipCoord==false){
                j=i;
                bSkipCoord=true;
            }
            if(infect1.coordinates.X==arrInfectants[i]->coordinates.X && infect1.coordinates.Y==arrInfectants[i]->coordinates.Y && bSkipCoord==true && i!=j){
                if(arrInfectants[i]->bInfect_status==true || arrInfectants[j]->bInfect_status==true){
                    arrInfectants[i]->bInfect_status=true;
                    arrInfectants[j]->bInfect_status=true;
                }
                break;
            }
        }
    }
}

//Done By Daniel(Leader)
void renderCharacter_infection()
{
    // Draw the location of the character
    if(arrInfectants[0]->bInfect_status==false)
        console.writeToBuffer(arrInfectants[0]->coordinates, (char)1, 0x0B);
    else
        console.writeToBuffer(arrInfectants[0]->coordinates, (char)1, 0x0C);

    if(arrInfectants[1]->bInfect_status==false)
        console.writeToBuffer(arrInfectants[1]->coordinates, 148, 0x0B);
    else
        console.writeToBuffer(arrInfectants[1]->coordinates, 148, 0x0C);

    if(arrInfectants[2]->bInfect_status==false)
        console.writeToBuffer(arrInfectants[2]->coordinates,232,0x0B);
    else
        console.writeToBuffer(arrInfectants[2]->coordinates,232,0x0C);

    if(arrInfectants[3]->bInfect_status==false)
        console.writeToBuffer(arrInfectants[3]->coordinates,232,0x0B);
    else
        console.writeToBuffer(arrInfectants[3]->coordinates,232,0x0C);

    if(arrInfectants[4]->bInfect_status==false)
        console.writeToBuffer(arrInfectants[4]->coordinates,232,0x0B);
    else
        console.writeToBuffer(arrInfectants[4]->coordinates,232,0x0C);
	

    //infection collision between all ai and players
    infect_collision(infectantAI_1,infectantAI_2);
    infect_collision(infectantAI_1,infectantAI_3);
    infect_collision(infectantAI_1,player1);
    infect_collision(infectantAI_1,player2);
    infect_collision(infectantAI_2,player1);
    infect_collision(infectantAI_2,player2);
    infect_collision(infectantAI_2,infectantAI_3);
    infect_collision(infectantAI_3,player1);
    infect_collision(infectantAI_3,player2);
    infect_collision(player2,player1);
    // detect if win
    if(infected_win()==true){
        score=100;
        state=INIT_end_infectants;
    }
    timer(timeLeft);
    if(timeLeft<=0.0){
        state=INIT_end_survivors;
    }
}

//Done By Amirul
void render_end_infectants()
{
		insertmap(pacMap);
		console.writeToBuffer(20,27,"CONGRATULATIONS!!!!!! WHOOOOOOOO!!!!!!!!",0x0C);
		console.writeToBuffer(30,28,"INFECTANTS WIN!!!",0x0C);
		console.writeToBuffer(25,29,"HAHAHAHAHAHAHAHAHA!!!!!!!!!!",0x0C);
		console.writeToBuffer(20,30,"Press Enter To Play Another Mode!!!!!!",0x0C);
		console.writeToBuffer(25,31,"Press Escape To Quit, HAHAHAHA",0x0C);
}

//Done By Amirul
void render_end_survivors()
{
		insertmap(pacMap);
		console.writeToBuffer(20,27,"CONGRATULATIONS!!!!!! WHOOOOOOOO!!!!!!!!",0x0C);
		console.writeToBuffer(30,28,"SURVIVORS WIN!!!",0x0C);
		console.writeToBuffer(25,29,"HAHAHAHAHAHAHAHAHA!!!!!!!!!!",0x0C);
		console.writeToBuffer(20,30,"Press Enter To Play Another Mode!!!!!!",0x0C);
		console.writeToBuffer(25,31,"Press Escape To Quit, HAHAHAHA",0x0C);
}