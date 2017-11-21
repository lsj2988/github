#include <stdio.h>
#include <string.h>
#include "data.h"

int  main(void) {
    struct person p[5];

    int i=0;
    int n1=0;
    int n2=0;
    i = Sign_up(p,i);
    n2 = To_write_note(&p[n1],n2);
    printf("---------------------------\n");
    printf("Name : %s\n",p[i].name);
    printf("Id : %s\n",p[i].id);
    printf("Password : %s\n",p[i].psw);
    printf("School : %s\n",p[i].sch);
    printf("City : %s\n",p[i].city);
    printf("Age : %s\n",p[i].age);
    
    
    printf("%d\n",i);
    printf("%d\n",n2);

    return (0);
}


