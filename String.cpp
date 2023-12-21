#include<stdio.h>
int main()
{
	char s[]="String";
	printf("%s\n",s);
	for(int i=0;i<6;i++)
	{
		printf("%c\t",s[i]);
	}
	
	return 0;
}