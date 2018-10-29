// Author: Vannear Por
// Description: This is card test #2. This program will test the Village card.

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {
    printf("Card Test #2: Village Card\n");
    
    struct gameState testGame;
    int currentPlayer = 0;  //Player 1
    int handPos = 0;    //village is card 0
    testGame.numActions = 1;
    testGame.handCount[0] = 6;
    
    printf("Test Case 1 Running...\n");
    testGame.hand[0][0] = village;
    testGame.hand[0][1] = silver;
    testGame.hand[0][2] = gold;
    testGame.hand[0][3] = silver;
    testGame.hand[0][4] = gold;
    testGame.hand[0][5] = village;
    
    useVillage(currentPlayer, handPos, &testGame);
    
    //Hand card count should increase by 1, and numActions should increase by 2.
    
    if(testGame.numActions == 3) {
        printf("Test Case 1 Passed!\n");
    }
    else {
        printf("Test Case 1 Failed!\n");
    }
    
    printf("--Card Test #2 End--\n");
    
    return 0;
}


