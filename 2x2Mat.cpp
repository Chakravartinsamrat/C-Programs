#include<stdio.h>
int main()
{
	int a[10][10],i,j,n;
	printf("Enter the number of elements in an array\n");
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter the elements of the array\n");
			scanf("%d\n",&a[i][j]);
		}
	}
	return 0;
}