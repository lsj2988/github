#include <stdio.h>

int main(void) {

    int menu2;

    printf("-----------------\n");
    printf(" 1.To write note\n 2.To edit note\n 3.To view note\n 4.Back to Menu\n");
    printf("-----------------\n");

    printf("Press : ");
    scanf("%d",&menu2);
    
    switch (menu2)
    {
        case 1: //To_write_note(); 
            break;
        case 2: //To_edit_note(); 
            break;
        case 3: //To_view_note(); 
            break;
        case 4: //Back_to_Menu(); 
            break;
        default: printf("You press Wrong Number\n"); break;
    }

    return 0;
}
