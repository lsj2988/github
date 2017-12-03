#include <stdio.h>
#include <string.h>
#include <termios.h>
#define MAX_P 10
#define MAX_N 80

void Loaddata1(info *arr, int *pnum) {
    FILE *file = fopen("a.txt","rt");
    if (file == NULL) {
        return;
    }
    while(1) {
        fscanf(file,"%s %s %s %s %s %s ",arr[*pnum].name,arr[*pnum].id,arr[*pnum].psw,arr[*pnum].sch,arr[*pnum].city,arr[*pnum].age);
        if (feof(file) != 0) {
            break;
        }
            (*pnum)++;
    }
}

void Savedata1(info *arr,int *pnum) {
    int i;
    FILE *file = fopen("a.txt","wt");
    if (file == NULL) {
        return;
    }
    for(i=0;i<(*pnum)+1;i++) {
         fprintf(file,"%s %s %s %s %s %s",arr[i].name,arr[i].id,arr[i].psw,arr[i].sch,arr[i].city,arr[i].age);
    }
}

int getch() {
    int ch;
    struct termios buf;
    struct termios save;

    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

void Sign_up(info *arr, int *npnum, int *pnum) {
    if ((*npnum) < MAX_P) {
    
    char ch;
    char psw[20];
    int j;

    printf("Name : ");
    fgets(arr[*npnum].name,sizeof(arr[*npnum].name),stdin);
    
    printf("Id : ");
    fgets(arr[*npnum].id,sizeof(arr[*npnum].id),stdin);
    
    printf("Password : ");
    for(j=0; j<19; j++) {
        ch = getch();
        if(ch == '\n') break;
        putchar('*');
        psw[j] = ch;
    }
    printf("\n");

    strncpy(arr[*npnum].psw,psw,strlen(psw));
    
    printf("School : ");
    fgets(arr[*npnum].sch,sizeof(arr[*npnum].sch),stdin);
    
    printf("City : ");
    fgets(arr[*npnum].city,sizeof(arr[*npnum].city),stdin);
    
    printf("Age : ");
    fgets(arr[*npnum].age,sizeof(arr[*npnum].age),stdin);
    
    (*npnum)++;
    (*pnum) = (*npnum) - 1;
    }

    else {
        printf("User is Full\n");
    }
}

void Sign_in(info *arr, int *pnum,int *osnum) {
    int i,j;
    char id[20];
    char psw[20];
    char ch;
    int pn;

    printf("----------------\n");
    printf("ID : ");
    fgets(id,sizeof(id),stdin);

    for(i = 0; i < (*pnum); i++) {
        if(strncmp(arr[i].id,id,strlen(id)) == 0) {
            break;
        }
    }

    pn = i;
    
    while(1) {
        printf("PASSWORD : ");
        for(j=0; j<19; j++) {
        ch = getch();
        if(ch == '\n') break;
        putchar('*');
        psw[j] = ch;
    }
    printf("\n");

    if(strncmp(arr[pn].psw, psw, strlen(psw)) == 0) {
        (*osnum) = pn;
        printf("---------------\n"); break;
        }
    else {
        printf("Acess Denied\n"); break;
    }
    }
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

void List_of_user(info *arr, int *pnum) {
    int i;
    for(i=0;i<(*pnum)+1;i++) {
        printf("\n-------------------------\n");
        printf("Name : %s\n",arr[i].name);
        printf("ID : %s\n",arr[i].id);
        printf("Age : %s\n",arr[i].age);
        printf("School : %s\n",arr[i].sch);
        printf("City : %s\n",arr[i].city);
    }
}
