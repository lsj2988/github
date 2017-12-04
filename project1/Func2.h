#include<stdio.h>
#include<string.h>
#include<termios.h>
#include<time.h>


void Loadtext1(info *arr, int *pnum, int *tnum)
{
    int i,j,k;

    FILE *file = fopen("memo.txt", "rb");

    if(file == NULL)
    {
        return;
    }
    for(i=0;i<10;i++) {
        fread(&tnum[i],sizeof(tnum[i]), 1, file);
    }

    for(j=0;j<(*pnum);j++) {
        for(k=0;k<tnum[j];k++) {
        fread(arr[j].title[tnum[k]], sizeof(arr[j].title[tnum[k]]), 1, file);
        fread(arr[j].memo[tnum[k]], sizeof(arr[j].memo[tnum[k]]), 1, file); 
        fread(arr[j].stime[tnum[k]], sizeof(arr[j].stime[tnum[k]]), 1, file);  
        }
        if(feof(file) != 0)
        {
            break;
        }
    }
}

void Savetext1(info *arr, int *pnum ,int *tnum)
{

    int i,j,k;
    FILE *file = fopen("memo.txt", "wb");

    if(file == NULL)
    {
        return;
    }

    for(i = 0;i < 10; i++)
    {
        fwrite(&tnum[i], sizeof(tnum[i]), 1, file);
    }
    for(j=0;j<(*pnum);j++) {
        for(k=0;k<tnum[j];k++) {
            fwrite(arr[j].title[tnum[k]], sizeof(arr[j].title[tnum[k]]), 1, file);
            fwrite(arr[j].memo[tnum[k]], sizeof(arr[j].memo[tnum[k]]), 1, file);
            fwrite(arr[j].stime[tnum[k]], sizeof(arr[j].stime[tnum[k]]), 1, file);
        }
    }
}

void savetime(info *arr, int *osnum, int *tnum)
{

    time_t now;
    struct tm t;


    time(&now);
    t = *localtime(&now);
    
    arr[*osnum].stime[tnum[*osnum]][0] = t.tm_year+1900;
    arr[*osnum].stime[tnum[*osnum]][1] = t.tm_mon+1;
    arr[*osnum].stime[tnum[*osnum]][2] = t.tm_mday;
    arr[*osnum].stime[tnum[*osnum]][3] = t.tm_hour;
    arr[*osnum].stime[tnum[*osnum]][4] = t.tm_min;
    arr[*osnum].stime[tnum[*osnum]][5] = t.tm_sec;
    

}

void presenttime()
{

    time_t now;
    struct tm t;


    time(&now);
    t = *localtime(&now);
    

    printf("Present Time : %4d.%d.%d %d:%d:%d\n", t.tm_year+1900, 
    t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

}

void to_write_note(info *arr, int *n_num, int *osnum, int *pnum)
{
    
    char tmp[200];
    char ch;
    int i = 0;
    int j;
    int flag = 0;

        
    printf("//////////////////////////////////\n ");
    
    while(1)
    {
        ch = getchar();      
        tmp[i] = ch;
        i++;

        if(flag != 2)
        {
            if(ch  == '\n')
            {
                flag++;
            }
            else
            {
                flag = 0;
            }
        }
        else if(flag == 2)
        {
            break;
        }
    }
    tmp[i - 1] = '\0';
    strncpy(arr[*osnum].memo[tnum[*osnum]], tmp, strlen(tmp));
    
    flag = 0;
    
    for(j = 0;j < 19;j++)
    {
        if(tmp[j] == 32)
        {
            flag++;
            if(flag == 3)
            {
                strncpy(arr[*osnum].title[tnum[*osnum]], tmp, j);
            }
        }
    }
    (tnum[*osnum])++;
}

void to_view_note(info *arr, int *tnum, int *osnum, int *pnum)
{   

    int i, j;

    for(i = 0;i < *pnum;i++)
    {
        printf("------------------------------------\n");
        for(j = 0;j < tnum[*osnum];j++)
        {
            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
            printf("Title : %s", arr[i].title[j]);
            printf("%4d.%d.%d  %d:%d:%d\n", arr[i].stime[j][0], arr[i].stime[j][1], arr[i].stime[j][2], arr[i].stime[j][3], arr[i].stime[j][4], arr[i].stime[j][5]);
            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
            printf("Memo : %s", arr[i].memo[j]);
        }
        printf("------------------------------------\n");
    }

}
        
