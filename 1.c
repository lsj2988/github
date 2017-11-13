#include <stdio.h>
#include <string.h>

struct person {
    char name[20];
    char id[20];
    char psw[20];
    char sch[20];
    char city[20];
    char age[4];
    char memo[80][200];
    char stime[80][200];
};

int main(void) {
    struct person p[5];

    int i=0;

    printf("Name : ");
    fgets(p[i].name,sizeof(p[i].name),stdin);
    /*

    */
    
    printf("Id : ");
    fgets(p[i].id,sizeof(p[i].id),stdin);
    /*

    */

    printf("Password : ");
    fgets(p[i].psw,sizeof(p[i].psw),stdin);
    /*

    */

    printf("School : ");
    fgets(p[i].sch,sizeof(p[i].sch),stdin);
    /*

    */

    printf("City : ");
    fgets(p[i].city,sizeof(p[i].city),stdin);
    /*

    */

    printf("Age : ");
    fgets(p[i].age,sizeof(p[i].age),stdin);
    /*

    */

   
    printf("---------------------------\n");

    printf("Id : %s\n",p[i].name);
    printf("Password : %s\n",p[i].psw);
    printf("School : %s\n",p[i].sch);
    printf("City : %s\n",p[i].city);
    printf("Age : %s\n",p[i].age);

    return (0);
}
