// Author: Vannear Por
// Description: This is card test #3. This program will test the great_hall card.

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {
    printf("Card Test #3: Great_Hall Card\n");
    
    struct gameState testGame;
    int currentPlayer = 0;  //Player 1
    int handPos = 0;    //great_hall card is pos 0
    testGame.numActions = 1;
    testGame.handCount[0] = 6;
    
    printf("Test Case 1 Running...\n");
    testGame.hand[0][0] = great_hall;
    testGame.hand[0][1] = silver;
    testGame.hand[0][2] = gold;
    testGame.hand[0][3] = silver;
    testGame.hand[0][4] = gold;
    testGame.hand[0][5] = village;
    
    useGreatHall(currentPlayer, handPos, &testGame);
    
    //Hand card count should stay the same, and numActions should decrease by 1.
    
    if(testGame.numActions == 0) {
        printf("Test Case 1 Passed!\n");
    }
    else {
        printf("Test Case 1 Failed!\n");
    }
    
    printf("--Card Test #3 End--\n");
    
    return 0;
}


