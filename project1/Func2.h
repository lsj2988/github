#ifndef _FUNC2_H_
#define _FUNC2_H_
#include<stdio.h>
#include<string.h>
#include<time.h>

void Loadtext(int *tnum)//Load text-number for each user
{
    FILE *file = fopen("d.txt","rb");//read binary file for LOADING!!
    if(file == NULL) 
    {
        return;
    }
    fread(tnum,sizeof(tnum),10,file);
    fclose(file);
}

void Loadtext1(info *arr, int *pnum)//Load text-files for overwrite for so on
{
    int j;
    FILE *file = fopen("memo.txt", "rb");

    if(file == NULL)
    {
        return;
    }
    for(j=0;j<(*pnum);j++) 
    {
        fread(arr[j].title, sizeof(arr[j].title), tnum[j], file);
        fread(arr[j].memo, sizeof(arr[j].memo), tnum[j], file);
        fread(arr[j].stime, sizeof(arr[j].stime), tnum[j], file);
    }
    fclose(file);
}

void Savetext(int *tnum) //Save text-number for remembering how many text-file added on this session.
{
    FILE *file = fopen("d.txt","wb");
    if(file == NULL) 
    {
        return;
    }
    fwrite(tnum,sizeof(tnum),10,file);
    fclose(file);

}

void Savetext1(info *arr, int *pnum)//Saving text-file that user wrote to write in binary code.
{

    int j;
    FILE *file = fopen("memo.txt", "wb");

    if(file == NULL)
    {
        return;
    }

    for(j=0;j<(*pnum);j++) 
    {
        fwrite(arr[j].title, sizeof(arr[j].title), tnum[j], file);
        fwrite(arr[j].memo, sizeof(arr[j].memo), tnum[j], file);
        fwrite(arr[j].stime, sizeof(arr[j].stime), tnum[j], file);
    }
    fclose(file);
}

void savetime(info *arr, int *osnum, int *tnum)//Saving time that user's writing time.
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

void presenttime() //to show present time.to see what time I started writing.
{

    time_t now;
    struct tm t;


    time(&now);
    t = *localtime(&now);
    

    printf("Present Time : %4d.%d.%d %d:%d:%d\n", t.tm_year+1900, 
    t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

}

void to_write_note(info *arr, int *tnum, int *osnum) //to save the writing things on the raw for Save in structure.
{
    
    char tmp[200];//temporary space before saving the memo.
    char ch;//to get the character for to quit when pressing enter twice.
    int i = 0;
    int j;
    int flag = 0;//flag for quit the loop

        
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
    strncpy(arr[*osnum].memo[tnum[*osnum]], tmp, strlen(tmp));//when break from the loop save the memo from tmp to arr.memo
    
    flag = 0;
    
    for(j = 0;j < 19;j++)//for saving title.
    {
        if(tmp[j] == 32)//while reading memo tmp, when it faces enter, flag increases
        {
            flag++;
        }
        else if(tmp[j] == '\n')//while readingg memo tmp, when it faces space, flag increases
        {
            flag++;
            tmp[j] = ' ';
        }
            if(flag == 3)//when flag is three break from the loop.
            {
                strncpy(arr[*osnum].title[tnum[*osnum]], tmp, j);
                break;
            }
        
    }
    (tnum[*osnum])++;
}

void to_view_note(info *arr, int *tnum, int *pnum)
{   

    int i, j;
    
    for(i = 0;i < *pnum;i++)//until the present occupied user
    {
        if(tnum[i] > 0) {
        printf("------------------------------------\n");
        for(j = 0;j < tnum[i];j++)//until each textfile-number that user wrote
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
