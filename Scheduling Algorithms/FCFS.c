#include<stdio.h>
#include<stdlib.h>


int main()
{
	int i=0,n;
	int*at,*bt,*wt,*ct,*visited,*tat;
	printf("\nEnter the number of processes:: ");
	scanf("%d",&n);
	if(n>0)
	{
		at=(int*)malloc(n*sizeof(int));
		bt=(int*)malloc(n*sizeof(int));
		ct=(int*)malloc(n*sizeof(int));
		wt=(int*)malloc(n*sizeof(int));
		tat=(int*)malloc(n*sizeof(int));
		visited=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			printf("\nEnter the arrival time for process %d:: ",i+1);
			scanf("%d",&at[i]);
			printf("\nEnter the Burst Time for the process %d:: ",i+1);
			scanf("%d",&bt[i]);
			visited[i]=i;
		}
		for(i=0;i<n-1;i++)
		{
			int j;
			for(j=0;j<n-i-1;j++)
			{
				if(at[j]>at[j+1])
				{
					int temp=at[j];
					at[j]=at[j+1];
					at[j+1]=temp;
					temp=visited[j];
					visited[j]=visited[j+1];
					visited[j+1]=temp;
					temp=bt[j];
					bt[j]=bt[j+1];
					bt[j+1]=temp;
				}
			}
		}
		int currenttime=at[0];
		for(i=0;i<n;i++)
		{
			
			
			wt[i]=currenttime-at[i];
			currenttime=bt[i]+currenttime;
			ct[i]=currenttime;
			tat[i]=wt[i]+bt[i];
			
		}
		printf("\nProcess Id\tArrival Time\tBurst Time\tCompletion Time\tTurn-Arund Time\t Waiting Time");
		float avgtat=0;
		float avgwt=0;
		for(i=0;i<n;i++)
		{
		printf("\n   %d      \t     %d      \t   %d     \t       %d      \t     %d       \t     %d",visited[i]+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		avgtat=avgtat+tat[i];
		avgwt=avgwt+wt[i];	
		}
		printf("\nAverage Waiting Time:: %.2f\nAverage Turn-Around-Time::%.2f",avgwt/n,avgtat/n);
		
	}
	else
	{
		printf("\nInvalid Input");
	}
	return 0;
}
