#ifndef MYID_H_INCLUDED
#define MYID_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static int cityCode_e[26]={1, 0, 9, 8, 7, 6, 5, 4, 9, 3, 2, 2, 1, 0, 8, 9 ,8, 7, 6, 5, 4, 3, 1, 3, 2, 0};

void init();
void Help();
void IDgen();
int startsWith(const char *prefix, const char *str);
int isHelp(const char* str);
int isQuit(const char* str);
int isGen(const char* str);
int CMD(char* str);
int errorCode(int index);
int checkID(char* str);
#endif // MYID_H_INCLUDED
