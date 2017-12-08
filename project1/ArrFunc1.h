#ifndef _ARRFUNC1_H_
#define _ARRFUNC1_H_
#include <stdio.h>
#include <stdlib.h>

void Signup() {
    system("clear"); 
    Sign_up(arr, &pnum);
}

void Signin() {
    system("clear");
    Sign_in(arr, &pnum, &osnum);
}

void Listofuser() {
    system("clear");
    List_of_user(arr, &pnum);
}
#endif
