#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_NUM 10

struct person {
    char name[20];
    char id[20];
    char psw[20];
    char sch[20];
    char city[20];
    char age[4];
    char title[80][20];
    char memo[80][200];
    char stime[80][30];
};

int Sign_up(struct person *pp, int n) {
    if (n < MAX_NUM) {
        
    printf("Name : ");
    fgets(pp[n].name,sizeof(pp[n].name),stdin);
    printf("\n"); 
    
    printf("Id : ");
    fgets(pp[n].id,sizeof(pp[n].id),stdin);
    printf("\n"); 
    
    printf("Password : ");
    fgets(pp[n].psw,sizeof(pp[n].psw),stdin);
    printf("\n"); 
    
    printf("School : ");
    fgets(pp[n].sch,sizeof(pp[n].sch),stdin);
    printf("\n"); 
    
    printf("City : ");
    fgets(pp[n].city,sizeof(pp[n].city),stdin);
    printf("\n"); 
    
    printf("Age : ");
    fgets(pp[n].age,sizeof(pp[n].age),stdin);
    printf("\n");

    return (n + 1);
    }

    else
        printf("User is Full\n");
}

int To_write_note(struct person *lp,int n_note) {
    char temp[200];
    char blanc = 0;

    printf("Write : ");
    fgets((temp,sizeof(temp),stdin);

    if() {
        fgets((*lp).memo[n_note],sizeof((*lp).memo[n_note]),stdin);
    }
    printf("\n");
    
    for(j=0; j<strlen(); j++) {
        if((*lp).memo[j] == " ") {
            blanc++;
            if(blanc == 4) break;
        }
    }

    strncpy((*lp).title[n_note],(*lp).memo[n_note],j);
}



    printf("Print : %s",(*lp).memo[n_note]);
    return (n_note + 1);
}  
