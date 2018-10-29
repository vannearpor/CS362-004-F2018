// Author: Vannear Por
// Description: This is card test #1. This program will test the Smithy card.

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {
    printf("Card Test #1: Smithy Card\n");
    
    struct gameState testGame;
    int i = 0;
    int currentPlayer = 0;  //Player 1
    int handPos = 0;    //smithy is card 0
    testGame.numActions = 1;
    testGame.handCount[0] = 6;
    
    printf("Test Case 1 Running...\n");
    testGame.hand[0][0] = smithy;
    testGame.hand[0][1] = silver;
    testGame.hand[0][2] = gold;
    testGame.hand[0][3] = silver;
    testGame.hand[0][4] = gold;
    testGame.hand[0][5] = smithy;
    
    useSmithy(i, currentPlayer, handPos, &testGame);
    
    //Card hand count should stay the same, since the introduced bug in Smithy
    //only draws 1 card, and smithy is discarded. numActions should be 2.
    
    if(testGame.numActions == 2) {
        printf("Test Case 1 Passed!\n");
    }
    else {
        printf("Test Case 1 Failed!\n");
    }
    
    printf("--Card Test #1 End--\n");
    
    return 0;
}


