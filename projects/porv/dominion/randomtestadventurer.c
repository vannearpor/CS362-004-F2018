/*This random test tests the Adventurer card function.*/

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
    
    int i, j;
    bool testFlag;
    int deckTotal, handTotal;
    int startDeck, finishDeck;
    int startHand, finishHand;
    int startDiscardPile = 0;
    int tempHand[500];
    int finishDiscardPile;
    int handPos;
    
    int pickedCard;
    int nonTreasure;
    
    int failCount = 0;
    int passCount = 0;
    
    int players = 2;
    int currentPlayer = 0;
    int testSeed = 100;
    
    srand(time(NULL));
    for(i = 0; i < 50000; i++){
        initializeGame(players, k, testSeed, &testGame);
        
        testFlag = true;
        deckTotal = rand() % 501;
        handTotal = rand() % 501;
        
        testGame.deckCount[0] = deckTotal - handTotal;
        startDeck = testGame.deckCount[0];
        testGame.handCount[0] = handTotal;
        startHand = testGame.handCount[0];
        handPos = testGame.hand[currentPlayer][testGame.handCount[currentPlayer] -1];
        
        testGame.playedCardCount = startDiscardPile;
        
        //fill up deck with cards
        for(j = 0; j < startDeck; j++){
            pickedCard = rand() % 11;
            if(pickedCard == 1){
                testGame.deck[0][j] = gold;
            }
            else if(pickedCard == 2){
                testGame.deck[0][j] = silver;
            }
            else if(pickedCard == 3){
                testGame.deck[0][j] = copper;
            }
            else {
                nonTreasure = rand() % 10;
                testGame.deck[0][j] = k[nonTreasure];
            }
        }
        
        useAdventurer(0, 0, currentPlayer, &testGame, 0, tempHand);
        
        finishDiscardPile = testGame.playedCardCount;
        finishDeck = testGame.deckCount[0];
        finishHand = testGame.handCount[0];
        
        if(finishDeck != ((startDeck - finishDiscardPile)-2)){
            testFlag = false;
        }
        
        if(finishHand != (startHand+2)){
            testFlag = false;
        }
        
        if(finishDiscardPile == 0){
            testFlag = false;
        }
        
        if(testFlag == false){
            failCount++;
            printf("\nTests Failed: %d\n", failCount);
        }
        else {
            passCount++;
            printf("\nTests Passed: %d\n", passCount);
        }
    }
}
