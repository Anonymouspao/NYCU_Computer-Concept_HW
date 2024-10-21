#include <stdio.h>
#include "myid.h"

int main( ) {
    srand(time(0));
    char input[100];
    init();                                                     // print documentation for ID check/generate

    while(1) {
        fprintf(stderr, "Input ID for check, or \"HELP\" for help info: ");
        fgets(input, sizeof input, stdin);
        if(isQuit(input)) break;
        if(isHelp(input)){
            Help( );
            continue;
        }
        if(isGen(input)){
            IDgen();
            continue;
        }
        if(checkID(input) != NULL){
            printf("%s", input);
            errorCode(checkID(input));
        }
   }

   printf("Thank you for using IDGen, Goodbye!\n");
   return 0;
}
