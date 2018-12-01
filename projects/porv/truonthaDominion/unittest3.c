// Author: Vannear Por
// Description: This is unit test #3 which will test the
// updateCoins function. This test will prepopulate treasure cards into
// the hands of 2 players and test to see if updateCoins generates
// the correct coin count.

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {
    struct gameState testGame;
    int player1 = 0;
    int player2 = 1;
    
    printf("Unit Test #3: updateCoins Function\n");
    
    printf("Test Case 1 Running...\n");
    printf("Populating hand of Player 1\n");
    testGame.hand[0][0] = copper; //+1
    testGame.hand[0][1] = silver; //+2
    testGame.hand[0][2] = gold; //+3
    testGame.hand[0][3] = gold; //+3
    testGame.hand[0][4] = silver; //+2
    testGame.hand[0][5] = copper; //+1
    //Player 1 should have a total of 12 coins.
    
    printf("Updating the coin count of Player 1...");
    
    updateCoins(player1, &testGame, 0);
    
    if(testGame.coins == 12) {
        printf("Unit Test #3 Case 1 Passed!\n");
    }
    else {
        printf("Unit Test #3 Case 1 Failed!\n");
    }
    
    printf("Test Case 2 Running...\n");
    printf("Populating hand of Player 2\n");
    testGame.hand[1][0] = silver; //+2
    testGame.hand[1][1] = silver; //+2
    testGame.hand[1][2] = gold; //+3
    testGame.hand[1][3] = gold; //+3
    testGame.hand[1][4] = gold; //+3
    testGame.hand[1][5] = silver; //+2
    //Player 2 should have a total of 15 coins.
    
    printf("Updating the coin count of Player 2...");
    
    updateCoins(player2, &testGame, 0);
    
    if(testGame.coins == 15) {
        printf("Unit Test #3 Case 2 Passed!\n");
    }
    else {
        printf("Unit Test #3 Case 2 Failed!\n");
    }
    
    printf("--Unit Test #3 End--\n");
    
    return 0;
}


