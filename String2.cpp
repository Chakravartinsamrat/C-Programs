#include<stdio.h>
int main(){
	char s1[]="string";
	char s2[]={'s','t','r','i','n','g','\0'};
	printf("%lu\n",sizeof(s1));
	printf("%lu\n",sizeof(s2));
}