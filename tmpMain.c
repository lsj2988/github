#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tmpdata.h"

int  main(void) {
    int i = 0;
    int j = 0;
    Signup();
    system("clear");
    printf("---------------------------\n");
    system("clear");
    printf("Name : %s\n",arr[i].name);
    printf("Id : %s\n",arr[i].id);
    printf("School : %s\n",arr[i].sch);
    printf("City : %s\n",arr[i].city);
    printf("Age : %s\n",arr[i].age);
    
    Towritenote();
    printf("Title : %s\n",arr[i].title[j]);
    printf("Memo : %s\n",arr[i].memo[j]);

    return (0);
}
