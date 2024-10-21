#ifndef NIM_H_INCLUDED
#define NIM_H_INCLUDED
#include <stdio.h>
#define NOT !

enum player{
    USER = 38,
    COMPUTER = 49
};
enum player currentPlayer = USER;

int gameOver;
int userFirst = 0;
int lastToWin = -1;
int nPile, nStone[10];
int pile, stone, sum = 0;

void prepareGame(){
    system("CLS");
    printf("Welcome to NIM game!\nInitializing the game\n\n");
    int n = rand() % 100;
    lastToWin = (n > 49) ? -1 : 0;                    //random decide last to pick wins / last to pick lose
    nPile = rand() % 4 + 2;                         //2~5 piles
    for (int i = 0; i < nPile; i++){
        nStone[i] = rand() % 5 + 1;                 //1~6 stones each pile
    }
    showGameData();
}

void showGameData(){
    printf("Total number of piles: %d, ", nPile);
    if(lastToWin){
        printf("last to pick WINS.\n");
    }
    else{
        printf("last to pick LOSES.\n");
    }
    printf("\nGame status:\n");
    for(int k=0; k<nPile; k++){
        printf("Pile %d: %d stone(s)\n", k+1, nStone[k]);
    }
    printf("\n");
}

int askGoFirst(){                                   //random decide who goes first
    int num, tmp;
    printf("Pick a number from 1~10: ");
    while(scanf("%d", &num)){
        if(num>10 || num<1){
            printf("Out of range!\n");
            printf("Pick a number from 1~10: ");
            continue;
        }
        break;
    }

    tmp = rand() % 10 + 1;
    if (num >= tmp){
        printf("The computer pick %d, you go first.", tmp);
        return 1;
    }
    printf("The computer pick %d, computer go first.", tmp);
    return 0;
}

int isFinish(){
    for (int j = 0; j < nPile; j++){
        if(nStone[j]!=0) return 0;
    }

    return 1;
}
int userTurn(){
    currentPlayer = USER;
    printf("\nYour turn.\n");
    while(1){
        printf("Pick the pile and the number of stone you want:\n");
        printf("From pile:");
        scanf("%d", &pile);;
        printf("Pick how many stones:");
        scanf("%d", &stone);
        if(pile<1 || pile>nPile || nStone[pile-1]==0 || stone<1 || stone>nStone[pile-1]){
            printf("Invalid!\n");
            continue;
        }
        else{
            nStone[pile-1]-=stone;
            break;
        }
    }

    return isFinish();
}
int computerMove(int winCondition, int gameStatus[]);
int computerTurn(){
    currentPlayer = COMPUTER;
    printf("\nComputer's turn.\n");
    computerMove(lastToWin, nStone);
    showGameData();
    return isFinish();
}
int computerMove(int winCondition, int gameStatus[]){
    int nimSum=0;
    int count=1;
    for(int x=0; x<nPile; x++){
        nimSum^=gameStatus[x];
        if(gameStatus[x]>0) count++;
    }
    if(nimSum==0){
        int max=0;
        int pileIndex=0;
        for(int y=0; y<nPile; y++){
            max=(gameStatus[y]>=max) ? gameStatus[y] : max;
            pileIndex=y;
        }
        gameStatus[pileIndex]--;
        printf("Computer removes %d stone from pile %d\n", 1, pileIndex+1);
        return;
    }
    else{
        for (int z=0; z<nPile; z++) {
            int targetSize = gameStatus[z] ^ nimSum;                 // Find the target heap size after move
            if (targetSize < gameStatus[z]) {                        // Check if reducing heap[i] to targetSize is a valid move
                int removed = gameStatus[z] - targetSize;
                gameStatus[z] = targetSize;                          // Perform the optimal move
                printf("Computer removes %d stones from pile %d\n", removed, z+1);
                return;
            }
        }
    }
}

int judgeResult() {
    if(lastToWin){
        if(currentPlayer==USER) printf("\nFuiyoh! You pick the last one, you win! Good game! Good game!");
        else printf("\nHaiya! Computer pick the last one, you lose la! Such a Failure!");
    }
    if(NOT lastToWin){
        if(currentPlayer==USER) printf("\nHaiya! You pick the last one, you lose la! StooBid!");
        else printf("\nFuiyoh! Computer pick the last one, you win la! Not Bad! Not Bad");
    }

}

#endif // NIM_H_INCLUDED
