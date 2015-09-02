#ifndef _COOP_H
#define _COOP_H

void init_COOP(stage changeState);
void init_COOP_end(stage changeState);
void moveCharacter_COOP();
void ghostAndPlayer1CollisionCoop(COORD &ene , COORD &p1);
void ghostAndPlayer2CollisionCoop(COORD &ene , COORD &p2);
void renderCallForHelp(COORD &p1 , COORD &p2);
void renderCoopCharacter();
void renderEndCondition();
void coopWinCondition();

#endif