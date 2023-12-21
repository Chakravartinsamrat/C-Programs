#include <stdio.h>
#include<stdlib.h>
void countNucleotides(char*Sequence, int*counts)
{
	for(int i=0;Sequence[i]!='\0';i++)
	{
		switch(Sequence[i]){
			case'A':
				counts[0]++;
				break;
			case'C':
				counts[1]++;
				break;
			case'G':
				counts[2]++;
				break;
			case'T':
				counts[3]++;
				break;
		}
	}
}
double calculateGCContent(char*Sequence)
{
	int TotalNucleotides=0;
	int gcCount=0;
	for(int i=0;Sequence[i]!='\0';i++)
	{
		if(Sequence[i]=='G'||Sequence[i]=='C')
		{
			gcCount++;
		}
		TotalNucleotides++;
	}
	return((double)gcCount/TotalNucleotides)*100.00;
}
int main()
{
	int numSequences;
	printf("genetic Sequence Analyzer:\n\n");
	printf("enter the number of Genetic Sequence:\n");
	scanf("%d",&numSequences);
	char**Sequences=(char**)malloc(numSequences*sizeof(char*));
	int**nucleotideCounts=(int**)malloc(numSequences*sizeof(int*));
	double*gcContent =(double*)malloc(numSequences*sizeof(double*));
	for(int i=0;i<numSequences;i++)
	{
		Sequences[i]=(char*)malloc(100*sizeof(char));
		nucleotideCounts[i]=(int*)calloc(4,sizeof(int));
		gcContent[i]=0.0;
		printf("Enter Genetic Sequence %d:",i+1);
		scanf("%s",Sequences[i]);
		countNucleotides(Sequences[i],nucleotideCounts[i]);
		gcContent[i]=calculateGCContent(Sequences[i]);
	}
	printf("\nAnalysis Results:\n");
	for(int i=0;i<numSequences;i++)
	{
		printf("Sequence %d :\n",i+1);
		printf("A:%d\n",nucleotideCounts[i][0]);
		printf("C:%d\n",nucleotideCounts[i][1]);
		printf("G:%d\n",nucleotideCounts[i][2]);
		printf("T:%d\n",nucleotideCounts[i][3]);
		printf("GCContent:%.2f%%\n",gcContent[i]);
		printf("\n");
	}
	for(int i=0;i<numSequences;i++)
	{
		free(Sequences[i]);
		free(nucleotideCounts);
		free(gcContent);
		return 0;
	}
}
