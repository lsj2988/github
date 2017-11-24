#include <stdio.h>
#include <stdlib.h>

void Signup() {
    system("clear"); 
    Sign_up(arr, &npnum, &pnum);
}

void Signin() {
    system("clear");
    Sign_in(arr, &pnum, &osnum);
}

void Towritenote() {
    system("clear"); 
    To_write_note(arr, &osnum ,&tnum[osnum]);
}

void Listofuser() {
    system("clear");
    List_of_user(arr, &pnum);
}
