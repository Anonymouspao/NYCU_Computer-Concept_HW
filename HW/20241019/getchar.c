#include <stdio.h>
#include <conio.h>                                                      //for MSVC

int main( ) {
    int gg, yy;
    char arrowKeys[ ][33] = {"Home", "Up", "PageUp", "", "Left","", "Right",\
        "", "End", "Down", "PageDown", "Insert", "Delete"};
    char FKeys[ ] [9] = {"F11", "F12", };
    fprintf(stderr, "press \"Q\" to quit.\n");
    while(1){
        printf("Input: ");
        gg = _getch( );
        if(gg==0 || gg==224) yy = _getch( );
        printf("Got %d ===character %c\n", gg, gg);                     //some can't be shown
        if(gg==0 || gg==224) printf("\t Function key or Arrow Key: %d  %d ", gg, yy);
        if(gg==0) printf(" === F%d\n", yy-58);                          //59 == F1; 60 == F2, ... F10
        if(gg==224)//{      avoid bracket using tab
            if (yy >= 133) printf("  == %s  key\n", FKeys[ yy-133 ]);   // F11, F12
            else printf("  == %s  key\n", arrowKeys[ yy-71 ]);          // 71Home ,72up, 75L, 77R, 80down. ..
        //}
        if(gg == 'Q') break;
    }
    printf("Bye!\n");

    return 0;
}
