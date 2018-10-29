// Author: Vannear Por
// Description: This is unit test #4 which will test the
// isGameOver function. This test will alter the card piles to amounts which
// should end the game, or keep the game going, and test whether the isGameOver
// function correctly determines if the game has ended or not.

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
    int gameOverFlag = 0;
    
    printf("Unit Test #4: isGameOver Function\n");
    printf("Test Case 1: Stack of Province cards is empty, should end game.\n");
    
    testGame.supplyCount[province] = 0;
    
    gameOverFlag = isGameOver(&testGame);
    
    if(gameOverFlag == 1) {
        printf("Unit Test #4 Case 1 Passed!\n");
    }
    else {
        printf("Unit Test #4 Case 1 Failed!\n");
    }
    
    printf("Test Case 2: Stack of Province cards is not empty, game should not end.\n");
    
    testGame.supplyCount[province] = 2;
    
    gameOverFlag = isGameOver(&testGame);
    
    if(gameOverFlag == 0) {
        printf("Unit Test #4 Case 2 Passed!\n");
    }
    else {
        printf("Unit Test #4 Case 2 Failed!\n");
    }
    
    printf("--Unit Test #4 End--\n");
    
    return 0;
}


