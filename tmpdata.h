#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
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
int pnum = 0; // This New User count
int pnum1 = 0; // This Old User count
int t_num[10] = {0}; // This Memo number

void Sign_up(info *arr, int *pnum) {
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

    (*pnum)++;
    }

    else
        printf("User is Full\n");
}

void To_write_note(info *arr, int *tnum, int *n_num) {
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
        strncpy(arr[*tnum].memo[*n_num],temp,(strlen(temp)-1));
        for(l=0; l<19; l++) {
            if(temp[l] == 10) {
                strncpy(arr[*tnum].title[*n_num],temp,l);
                break;
            }
            else if(temp[l] == 32) {
                strncpy(arr[*tnum].title[*n_num],temp,l); 
                break;
            }
            else if(l == 18) {
                strncpy(arr[*tnum].title[*n_num],temp,l);
                break;
            }
        }
        (*n_num)++;
    }
            
    else {
        printf("Memo is Full\n");
    
    }
}

void Store1(info *arr, int rnum1) {
    FILE *file1 = fopen("a.txt","wt");
    fprintf(file1,"%s %s %s %s %s %s",arr[rnum1].name,arr[rnum1].id,arr[rnum1].psw,arr[rnum1].sch,arr[rnum1].city,arr[rnum1].age);
}

void Store2(info *arr, int tnum, int n_num) {
    FILE *file2 = fopen("b.txt","wb");
    fprintf(file2,"%s %s",arr[tnum].title[n_num],arr[tnum].memo[n_num]);
}

void Signup() {
    Sign_up(arr,&pnum);
    Store1(arr,pnum1);
}

void Towritenote() {
    To_write_note(arr,&pnum1,&t_num[pnum1]);
    Store2(arr,pnum1,t_num[pnum1]);
}


