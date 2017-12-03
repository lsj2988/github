#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int age=17;
    char name[20]={"sejin"};
    FILE *fp = fopen("a.txt","wt");
        fprintf(fp,"%d",age);
    fprintf(fp,"%s",name);
    printf("Age : %d, Name : %s",age,name);
    return 0;
}
