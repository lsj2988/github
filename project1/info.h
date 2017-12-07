#ifndef _INFO_H_
#define _INFO_H_

#include <stdio.h>
#include <string.h>
#define MAX_P 10
#define MAX_N 80

typedef struct information {
    char name[20];
    char id[20];
    char psw[20];
    char sch[20];
    char city[20];
    char age[4];
    char title[80][20];
    char memo[80][200];
    int stime[80][6];
}info;

info arr[10];
int pnum = 0; // User Number
int osnum = 0; // Occupied User
int tnum[10] = {0,}; // Memo Number fo Each User 

#endif
