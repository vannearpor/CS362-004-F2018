/*This random test tests the Smithy card function.*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int main() {
    struct gameState testGame;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    int i;
    bool testFlag;
    int deckTotal, handTotal;
    int startDeck, finishDeck;
    int startHand, finishHand;
    int startDiscardPile = 0;
    int finishDiscardPile;
    int handPos;
    
    int failCount = 0;
    int passCount = 0;
    
    int players = 2;
    int currentPlayer = 0;
    int testSeed = 100;
    
    srand(time(NULL));
    
    //Run test iterations
    for(i = 0; i < 50000; i++){
        initializeGame(players, k, testSeed, &testGame);
        testFlag = true;
        deckTotal = rand() % 501;   //get random deck total between 0 and 500;
        handTotal = rand() % 501;   //get random hand total between 0 and 500;
        
        //get numbers for deck and hand
        testGame.deckCount[0] = deckTotal - handTotal;
        startDeck = testGame.deckCount[0];
        testGame.handCount[0] = handTotal;
        startHand = testGame.handCount[0];
        handPos = testGame.hand[currentPlayer][testGame.handCount[currentPlayer] - 1];
        
        testGame.playedCardCount = startDiscardPile;
        
        //Call function
        playSmithy(&testGame, handPos);
        
        //Deck and hand counts after function is called
        finishDeck = testGame.deckCount[0];
        finishHand = testGame.handCount[0];
        finishDiscardPile = testGame.playedCardCount;
        
        //Check for fail game states
        if (finishDeck != (startDeck-1)){
            testFlag = false;
        }
        
        if (finishHand != startHand){
            testFlag = false;
        }
        
        if (finishDiscardPile != 1){
            testFlag = false;
        }
        
        if (testFlag == false){
            failCount++;
            printf("\nTests Failed: %d\n", failCount);
        }
        else{
            passCount++;
            printf("\nTests Passed: %d\n", passCount);
        }
        
    }
    return 0;
}
