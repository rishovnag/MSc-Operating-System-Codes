#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void bestfit(int processsize[],int blocksize[],int psize,int bsize)
{
	int *allocation=(int*)malloc(psize*sizeof(int));
	int i,j;
	for(i=0;i<psize;i++)
	{
		allocation[i]=-1;
	}
	
	for(i=0;i<psize;i++)
	{
		int index=-1;
		for(j=0;j<bsize;j++)
		{
			if(processsize[i]<=blocksize[j])
			{
				index=j;
				break;
			}
			
		}
		if(index!=-1)
		{
			allocation[i]=index;
			blocksize[index]-=processsize[i];
		}
	}
	printf("\nDisplaying the allocation\n");
	printf("Process Id \t ProcessSize \t allocated Block Id");
	for(i=0;i<psize;i++)
	{
		printf("\n     %d    \t     %d",i+1,processsize[i]);
		if(allocation[i]==-1)
		{
			printf("\tNot Allocated");
		}
		else
		{
			printf("\t   %d",allocation[i]+1);
		}
	}
	
}
int main()
{
	int *processsize,*blocksize,psize,bsize;
	printf("Enter the number of processes:: ");
	scanf("%d",&psize);
	printf("Enter the number of memory blocks:: ");
	scanf("%d",&bsize);
	if((psize>0) && (bsize>0))
	{
		int i;
		processsize=(int*)malloc(psize*sizeof(int));
		blocksize=(int*)malloc(bsize*sizeof(int));
		printf("\nEnter the memory needed for each process\n");
		for(i=0;i<psize;i++)
		{
			printf("\nEnter the amount of memory needed for process %d :: ",i+1);
			scanf("%d",&processsize[i]);
		}
		printf("\nEnter the size of each block\n");
		for(i=0;i<bsize;i++)
		{
			printf("\nEnter the size of Block %d ::",i+1);
			scanf("%d",&blocksize[i]);
		}
		printf("\nBlock Details\nBlock Id\tBlock Size\n");
		for(i=0;i<bsize;i++)
		{
			printf("%d   \t   %d\n",i+1,blocksize[i]);
		}
			printf("\nProcess Details\nProcess Id\tProcess Size\n");
		for(i=0;i<psize;i++)
		{
			printf("%d    \t   %d\n",i+1,processsize[i]);
		}
		bestfit(processsize,blocksize,psize,bsize);
	}
	else
	{
		printf("\nInvalid Input\n");
	}
	return 0;
}
