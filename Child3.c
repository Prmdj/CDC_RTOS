#include<stdio.h> 


int main() 
{ 
	for(int i=0;i<3;i++) 
	{ 
		if(fork() == 0) 
		{ 
			printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid()); 
			exit(0); 
		} 
	} 
	for(int i=0;i<3;i++)
	wait(NULL); 
	
} 
