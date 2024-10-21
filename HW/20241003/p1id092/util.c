#include "myid.h"
#include <stdio.h>
#include <ctype.h>

char * toUppers(char * str){
   char*p = str;
   while(*p) {
     *p = toupper(*p);
     ++p;
   }
   return str;
}

int startsWith(const char *prefix, const char *str){
    int len = strlen(prefix);
    return strncmp(prefix, str, len) == 0;
}
int isHelp(const char* str) {
    return startsWith("HELP", str);
}
int isQuit(const char* str) {
    if(startsWith("QUIT", str)) return 1;
    if(startsWith("EXIT", str)) return 1;
    return 0;
}
int isGen(const char* str) {
    if(startsWith("GEN", str)) return 1;
    return 0;
}
void init(){
    system("CLS");
    printf("Welcome to IDGen, here are some tips to guide you:\n");
    Help();
}
void Help(){
    printf("Type \"HELP\" for this command prompt\n" \
           "Type \"GEN\" to generate an ID number\n" \
           "Type \"CHECK to check your ID information\n" \
           "Type \"QUIT\" or \"EXIT\" to leave IDGen...\n\n");
}

int errorCode(int index){
    switch (index){
        case 1:
            printf("is valid.\n");
            break;
        case -5:
            printf("is invalid. Too long.\n");
            break;
        case -6:
            printf("is invalid. Too short.\n");
            break;
        case -2:
            printf("is invalid. Unknown city code.\n");
            break;
        case -3:
            printf("is invalid. Unknown gender code.\n");
            break;
        case -4:
            printf("is invalid. Contains non digits.\n");
            break;
        default:
            printf("is invalid. Wrong check sum.\n");
            break;
    }
}
