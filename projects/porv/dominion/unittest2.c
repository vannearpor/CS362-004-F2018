// Author: Vannear Por
// Description: This is unit test #2 which will test the
// getWinners function. This test will prepopulate score cards in
// 2 player's hands, then it will calculate the score of each player
// and determine

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
    int playerScores[2];
    
    printf("Unit Test #2: getWinners Function\n");
    
    printf("Test Case 1 Running...\n");
    printf("Populating hand of Player 1\n");
    testGame.hand[0][0] = province; //score +6
    testGame.hand[0][1] = great_hall; //score +1
    testGame.hand[0][2] = curse; //score -1
    testGame.hand[0][3] = duchy; //score +3
    testGame.hand[0][4] = curse; //score -1
    testGame.hand[0][5] = curse; //score -1
    //Player 1 should be 7.
    
    printf("Populating hand of Player 2\n");
    testGame.hand[1][0] = estate; //score +1
    testGame.hand[1][1] = province; //score +6
    testGame.hand[1][2] = province; //score +6
    testGame.hand[1][3] = curse; //score -1
    testGame.hand[1][4] = great_hall; //score +1
    testGame.hand[1][5] = estate; //score +1
    //Player 2 Total should be 14
    
    printf("Player 1's score should be +7\n");
    printf("Player 2's score should be +14\n");
    printf("Calculating winner...");
    
    getWinners(playerScores, testGame); //Calculates score and determines the winner.
    
    if(playerScores[1] == 1) {
        printf("Unit Test #2 Case 1 Passed!\n");
    }
    else {
        printf("Unit Test #2 Case 1 Failed!\n");
    }
    
    
    printf("Test Case 2 Running...\n");
    printf("Populating hand of Player 1\n");
    testGame.hand[0][0] = estate; //score +1
    testGame.hand[0][1] = estate; //score +1
    testGame.hand[0][2] = curse; //score -1
    testGame.hand[0][3] = duchy; //score +3
    testGame.hand[0][4] = duchy; //score +3
    testGame.hand[0][5] = duchy; //score +3
    //Player 1 should be 10.
    
    printf("Populating hand of Player 2\n");
    testGame.hand[1][0] = curse; //score -1
    testGame.hand[1][1] = curse; //score -1
    testGame.hand[1][2] = curse; //score -1
    testGame.hand[1][3] = duchy; //score +3
    testGame.hand[1][4] = estate; //score +1
    testGame.hand[1][5] = curse; //score -1
    //Player 2 Total should be 0
    
    printf("Player 1's score should be +10\n");
    printf("Player 2's score should be 0\n");
    printf("Calculating winner...");
    
    getWinners(playerScores, testGame); //Calculates score and determines the winner.
    
    if(playerScores[0] == 1) {
        printf("Unit Test #2 Case 2 Passed!\n");
    }
    else {
        printf("Unit Test #2 Case 2 Failed!\n");
    }
    
    printf("--Unit Test #2 End--\n");
    
    return 0;
}


