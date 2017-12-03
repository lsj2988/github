#include <stdio.h>
#include <string.h>

int menu_1(int *mnum) {
    printf("-------------------\n\n");
    printf("1. Sign Up\n 2. Sign In\n 3. List Of User\n\n");
    printf("-------------------\n\n");

    printf("SELECT : "); scanf("%d",&(*mnum));


    switch((*mnum)) {
        case 1: Sign_up(); break;
        case 2: Sign_in(); break;
        case 3: List_of_user(); break;
        default: printf("You press Wrong Number\n"); break;
        }
}
