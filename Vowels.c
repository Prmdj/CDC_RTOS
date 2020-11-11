#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
#include<stdio.h>

 

int main(int argc,char* argv[])
{
    
  int cp[2];
  if(pipe(cp)<0)
    exit(0);
  int pid=fork();
    if(pid==-1)
    {
        printf("can't fork,error\n");
        exit(0);
    } 
    else
        if(pid==0)
        {
           close(cp[0]);
           int vowels=0;
           printf("child process, pid = %u\n",getpid());
           fflush(stdout);
           for(int i=1;i<argc;i++)
            for(int j=0;argv[i][j]!='\0';j++)
             { 
        if(argv[i][j]=='a' || argv[i][j]=='e' || argv[i][j]=='i' || argv[i][j]=='o' || argv[i][j]=='u' || argv[i][j]=='A' || 
        argv[i][j]=='E' || argv[i][j]=='I' || argv[i][j]=='O' || argv[i][j]=='U')
            vowels++;
             }  
             write(cp[1],&vowels,sizeof(vowels));
             close(cp[1]);
             exit(2);
        }
      else
      {
        close(cp[1]);
        int vowels;
        printf("Parent id:%d\n",getpid());
        printf("Parent Process\n"); 
        wait(NULL);
        printf("Parent Printing\n");
        read(cp[0],&vowels,sizeof(vowels));
        close(cp[0]);
        printf("vowel count in command line arrgument is %d\n",vowels);
        exit(2);
      }
}