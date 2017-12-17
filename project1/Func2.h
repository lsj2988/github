#ifndef _FUNC2_H_
#define _FUNC2_H_
#include<stdio.h>
#include<string.h>
#include<time.h>

void Loadtext(int *tnum) 
{
    FILE *file = fopen("d.txt","rb");
    
    if(file == NULL)
    {
        return;
    }
    
    fread(tnum,sizeof(tnum),10,file);

    fclose(file);
}
void Loadtext1(info *arr, int *pnum, int *tnum)
{
    int j;

    FILE *file = fopen("memo.txt", "rb");

    if(file == NULL)
    {
        return;
    }
    
    fread(tnum,sizeof(tnum),10,file);

    for(j=0;j<(*pnum);j++) {
        fread(arr[j].title, sizeof(arr[j].title), tnum[j], file);
        fread(arr[j].memo, sizeof(arr[j].memo), tnum[j], file);
        fread(arr[j].stime, sizeof(arr[j].stime), tnum[j], file);
    }
    fclose(file);
}

void Savetext(int *tnum) 
{
    FILE *file = fopen("d.txt","wb");
    
    if(file == NULL)
    {
        return;
    }
    
    fwrite(tnum,sizeof(tnum),10,file);

    fclose(file);
}

void Savetext1(info *arr, int *pnum, int *tnum)
{

    int j;
    FILE *file = fopen("memo.txt", "wb");

    if(file == NULL)
    {
        return;
    }

    fwrite(tnum,sizeof(tnum),10,file);

    for(j=0;j<(*pnum);j++) {
        fwrite(arr[j].title, sizeof(arr[j].title), tnum[j], file);
        fwrite(arr[j].memo, sizeof(arr[j].memo), tnum[j], file);
        fwrite(arr[j].stime, sizeof(arr[j].stime), tnum[j], file);
    }
    fclose(file);
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

void to_write_note(info *arr, int *tnum, int *osnum)
{
    
    char tmp[200];
    char ch;
    int i = 0;
    int j;
    int flag = 0;

        
    printf("//////////////////////////////////\n");
    
    while(1)
    {
        ch = getchar();      
        tmp[i] = ch;
        i++;
        if(flag != 2) 
        {
            if(ch  == '\n')
                flag++;
            else
                flag = 0;
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
        if(tmp[j] == ' ')
        {
            flag++;
        }
        else if (tmp[j] == '\n') 
        {
            flag++;
            tmp[j] = ' ';
        }

        if(flag == 3)
        {
            strncpy(arr[*osnum].title[tnum[*osnum]], tmp, j);
            break;
        }
        
    }
    (tnum[*osnum])++;
}

void to_view_note(info *arr, int *tnum, int *osnum, int *pnum)
{   

    int i, j;
    
    for(i = 0;i < *pnum;i++)
    {
        if(tnum[i] > 0) {
        printf("------------------------------------\n");
        for(j = 0;j < tnum[i];j++)
        {
            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
            printf("Title : %s", arr[i].title[j]);
            printf("\nTime : %4d.%d.%d  %d:%d:%d\n", arr[i].stime[j][0], arr[i].stime[j][1], arr[i].stime[j][2], arr[i].stime[j][3], arr[i].stime[j][4], arr[i].stime[j][5]);
            printf("User : %s\n", arr[i].id);
            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
            printf("Memo : %s", arr[i].memo[j]);
        }
        printf("------------------------------------\n");
    }
    }

}
#endif
