#include <stdio.h>

int main(int argc, char const *argv[])
{
	int h=0,l=0,s=0,i=0,m=0,t=0;
	h=atoi(argv[2]);
	l=atoi(argv[1]);
	i=l;
	if(h<l)
	{
		printf("Not in Range\n");
		exit(0);
	}
	for(i=l;i<=h;i++)
	{
		t=i;
		s=0;
		while(t>0)
		{
			m=t%10;
			s+=m;
			t=t/10;
		}
		if(s==8)
		{
			printf("Number is %d\n",i);
		}
	}
	return 0;
}