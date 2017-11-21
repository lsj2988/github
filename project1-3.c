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

void Sign_up(struct person *lp, int *num);

int main(void) {
    struct person p[5];

    int i=0;
    
    Sign_up(p,&i);

    printf("---------------------------\n");
    printf("Name : %s\n",p[i].name);
    printf("Id : %s\n",p[i].id);
    printf("Password : %s\n",p[i].psw);
    printf("School : %s\n",p[i].sch);
    printf("City : %s\n",p[i].city);
    printf("Age : %s\n",p[i].age);

    return (0);
}

void Sign_up(struct person *lp, int *num) {
    if (*num < MAX_NUM) {
        
    printf("Name : ");
    fgets(lp[*num].name,sizeof(lp[*num].name),stdin);
    printf("\n"); 
    
    printf("Id : ");
    fgets(lp[*num].id,sizeof(lp[*num].id),stdin);
    printf("\n"); 
    
    printf("Password : ");
    fgets(lp[*num].psw,sizeof(lp[*num].psw),stdin);
    printf("\n"); 
    
    printf("School : ");
    fgets(lp[*num].sch,sizeof(lp[*num].sch),stdin);
    printf("\n"); 
    
    printf("City : ");
    fgets(lp[*num].city,sizeof(lp[*num].city),stdin);
    printf("\n"); 
    
    printf("Age : ");
    fgets(lp[*num].age,sizeof(lp[*num].age),stdin);
    printf("\n"); 
    }

    else
        printf("User is Full\n");
}
