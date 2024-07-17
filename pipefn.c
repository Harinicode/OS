#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int main()
{
    int p;
    int fp[2];
    char name[10],buff[10];
    printf("Enter a string");
    scanf("%s",name);
    if(pipe(fp)==-1)
    {
        perror("pipe");
        return 1;
    }
    if(fork()>0)
    {
        close(fp[0]);
        write(fp[1],name,strlen(name)+1);
        close(fp[1]);
    }
    else
    {
        close(fp[1]);
        read(fp[0],buff,sizeof(buff));
        close(fp[0]);
        printf("\n I/P string %s successfully stored",buff);
    }
     return 0;
}
