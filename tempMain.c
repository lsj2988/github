#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Info.h"
#include "Func.h"
#include "ArrFunc.h"

int main(void) {
    char menu;
    printf("-------------------\n\n");
    printf("1. Sign Up\n2. Sign In\n3. List Of User\n\n");
    printf("-------------------\n\n");

    printf("SELECT : ");
    menu = getch();
    switch(menu) {
        case '1': Signup(); break;
        case '2': Signin(); break;
        case '3': Listofuser(); break;
        default: printf("You press Wrong Number\n"); break;
        }
}
