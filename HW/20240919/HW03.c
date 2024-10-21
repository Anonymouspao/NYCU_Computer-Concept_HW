#include <stdio.h>
#include "NIM.h"
#include <time.h>
#define NOT !

int userTurn();
int computerTurn();


int main(){
    srand(time(0));
    int playAgain = 1;
    while (playAgain)
    {
        prepareGame();
        userFirst = askGoFirst();
        if (userFirst)
            gameOver = userTurn();
        while (NOT gameOver)
        {
            gameOver = computerTurn();
            if (gameOver)
                break;
            gameOver = userTurn();
        }
        judgeResult();
        printf("\nDo you want to play again? (0: no, 1: yes):");
        scanf("%d", &playAgain);
    }

    printf("Good Bye!\n");
    printf("113611092 Àj¦ö¸Û");
    return 0;
}

