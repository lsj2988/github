#include <stdio.h>
#include <string.h>
#define MAX_P 10
#define MAX_N 80

typedef struct information {
    char name[20];
    char id[20];
    char psw[20];
    char sch[20];
    char city[20];
    char age[4];
    char title[80][20];
    char memo[80][200];
    char stime[80][30];
}info;

info arr[10];

void Sign_up(info *arr, int *pnum1) {
    if ((*pnum) < MAX_P) {
        
    printf("Name : ");
    fgets(arr[*pnum].name,sizeof(arr[*pnum].name),stdin);
    
    printf("Id : ");
    fgets(arr[*pnum].id,sizeof(arr[*pnum].id),stdin);
    
    printf("Password : ");
    fgets(arr[*pnum].psw,sizeof(arr[*pnum].psw),stdin);
    
    printf("School : ");
    fgets(arr[*pnum].sch,sizeof(arr[*pnum].sch),stdin);
    
    printf("City : ");
    fgets(arr[*pnum].city,sizeof(arr[*pnum].city),stdin);
    
    printf("Age : ");
    fgets(arr[*pnum].age,sizeof(arr[*pnum].age),stdin);
    

    (*pnum1)++;
    }

    else
        printf("User is Full\n");
}

void To_write_note(info *arr, int *pnum2, int *n_num) {
    char temp[200];
    char ch;
    int i = 0;
    int l = 0;
    int flag = 0;
    printf("Write : ");
    if((*n_num) < MAX_N) {
        ch = getchar();
        while(flag != 2) {
            if (ch == '\n') flag++;
            else flag = 0;
            temp[i] = ch;
            i++;
            ch = getchar();
        }
        temp[i-1] = '\0';
        strncpy(arr[*pnum].memo[*n_num],temp,(strlen(temp)-1));
        for(l=0; l<19; l++) {
            if(temp[l] == 10) {
                strncpy(arr[*pnum].title[*n_num],temp,l);
                break;
            }
            else if(temp[l] == 32) {
                strncpy(arr[*pnum].title[*n_num],temp,l); 
                break;
            }
            else if(l == 18) {
                strncpy(arr[*pnum].title[*n_num],temp,l);
                break;
            }
        }
        (*pnum2)++;
    }
            
    else {
        printf("Memo is Full\n");
    
    }
}
