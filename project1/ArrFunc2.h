#ifndef _ARRFUNC2_H_
#define _ARRFUNC2_H_
#include<stdio.h>
#include<stdlib.h>

void Towritenote()
{
    system("clear");
    presenttime();
    savetime(arr, &osnum, tnum);
    to_write_note(arr, &tnum[osnum], &osnum, &pnum);
}

void Toview()
{
    system("clear");
    to_view_note(arr, tnum, &osnum, &pnum);
}
#endif
