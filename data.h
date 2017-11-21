#include <stdio.h>
#include <string.h>
#define MAX_NUM 5

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

int Sign_up(struct person *pp, int n_person) {
    if (*num < MAX_NUM) {
        
    printf("Name : ");
    fgets(pp[n_person].name,sizeof(pp[n_person].name),stdin);
    printf("\n"); 
    
    printf("Id : ");
    fgets(pp[n_person].id,sizeof(pp[n_person].id),stdin);
    printf("\n"); 
    
    printf("Password : ");
    fgets(pp[n_person].psw,sizeof(pp[n_person].psw),stdin);
    printf("\n"); 
    
    printf("School : ");
    fgets(pp[n_person].sch,sizeof(pp[n_person].sch),stdin);
    printf("\n"); 
    
    printf("City : ");
    fgets(pp[n_person].city,sizeof(pp[n_person].city),stdin);
    printf("\n"); 
    
    printf("Age : ");
    fgets(pp[n_person].age,sizeof(pp[n_person].age),stdin);
    printf("\n");

    return (n_person + 1);
    }

    else
        printf("User is Full\n");
}
