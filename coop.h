#ifndef _COOP_H
#define _COOP_H

void init_COOP(stage changeState);
void init_COOP_end(stage changeState);
void moveCharacter_COOP();
void eneXp1Coop(COORD &ene , COORD &p1);
void coopP1xP2(COORD &p1 , COORD &p2);
void renderCoopCharacter();
void renderEndCondition();
void coopWinCon();

#endif