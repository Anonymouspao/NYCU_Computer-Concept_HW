#include <stdio.h>
#include "myid.h"

int checkID(char* str){
    str[0] = toupper(str[0]);
    if(strlen(str)-1 > 10) return -5;
    if(strlen(str)-1 < 10) return -6;
    if(str[0]<'A' || str[0]>'Z') return -2;
    if(str[1]-'0'>=3 && str[1]-'0'<=7 || str[1]-'0'<=0) return -3;

    int N = cityCode_e[str[0]-'A'] + (str[9]-'0');
    for(int i=1; i<9; i++){
        if(!isdigit(str[i])) return -4;
        N += (str[i]-'0') * (9-i);
    }
    if(N%10 == 0) return 1;
    return 2;
}

