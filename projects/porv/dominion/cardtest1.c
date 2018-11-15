// Author: Vannear Por
// Description: This is card test #1. This program will test the Adventurer card.

#incldue "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {
    struct gameState testGame;
    int p1_score = 0;
    int p2_score = 0;
    
    printf("Unit Test #1: scoreFor Function\n");
    
    printf("Test Case 1 Running...\n");
    testGame.hand[0][0] = province; //score +6
    testGame.hand[0][1] = great_hall; //score +1
    testGame.hand[0][2] = curse; //score -1
    testGame.hand[0][3] = duchy; //score +3
    testGame.hand[0][4] = curse; //score -1
    testGame.hand[0][5] = curse; //score -1
    //Total should be 7.
    
    p1_score = scoreFor(0, testGame); //Calls function scoring player 1's hand
    printf("Player 1's score should be +7\n");
    printf("Player 1 Score: %d\n", p1_score);
    
    if (p1_score == 7) {
        printf("Unit Test #1 Case 1 Passed!\n");
    }
    else {
        printf("Unit Test #1 Case 1 Failed!\n");
    }
    
    printf("Test Case 2 Running...\n");
    testGame.hand[1][0] = estate; //score +1
    testGame.hand[1][1] = province; //score +6
    testGame.hand[1][2] = province; //score +6
    testGame.hand[1][3] = curse; //score -1
    testGame.hand[1][4] = great_hall; //score +1
    testGame.hand[1][5] = estate; //score +1
    //Total should be 14
    
    p2_score = scoreFor(1, testGame); //Calls function scoring player 2's hand
    printf("Player 2's score should be +14\n");
    printf("Player 2 Score: %d\n", p2_score);
    
    if (p2_score == 14) {
        printf("Unit Test #1 Case 2 Passed!\n");
    }
    else {
        printf("Unit Test #1 Case 2 Failed!\n");
    }
    
    printf("--Unit Test #1 End--\n");
    
    return 0;
}


