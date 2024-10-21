#include <stdio.h>
#include "myid.h"

void IDgen(){
    char str[100];
    while(1){
        fprintf(stderr, "Press \"enter\" to generate a random ID, or press \"Q\" to exit...\n");
        fgets(str, sizeof str, stdin);
        if(str[0] == 'Q') break;
        if(str[0] != '\n'){
            printf("Unknown input!\n");
            continue;
        }
        str[0] = 'A' + rand()%26;
        str[1] = '0' + rand()%2+1;
        int N = cityCode_e[str[0]-'A'] + (str[1]-'0')*8;
        for(int i=2; i<9; i++){
            str[i] = (rand()%10==10) ? '0' : '0'+rand()%10;
            N += (str[i]-'0') * (9-i);
        }
        str[9] = ((10-(N%10))==10) ? '0' : '0'+(10-(N%10));
        str[10] = '\0';
        printf("%s\n", str);
    }

    return 0;
}
