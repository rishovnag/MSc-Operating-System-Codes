#include<stdio.h>
int main()
{
    int i,n,j,min,temp;
    int bt[50],at[50],wt[50],tat[50],p[50];
    int burst_time=0,ta=0,sum=0,k=1;
    float avg_wt=0,avg_tat=0,sum_tat=0,sum_wt=0;

    printf("Enter the Number of processes : ");
    scanf("%d",&n);

    //entering the process number, arrival time and the burst time for each of the processes
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        printf("\n\n Enter the process number: ");
        scanf("%d",&p[i]);
		printf("\nEnter The Arrival Time Of Process %d : ",i+1);
        scanf(" %d",&at[i]);
        printf("Enter The Burst Time Of Process%d : ",i+1);
        scanf(" %d",&bt[i]);

    }

    //Sorting the processes according to arrival time
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(at[i]<at[j])
            {
				temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                
				
                temp=at[j];
                at[j]=at[i];
                at[i]=temp;
				
                temp=bt[j];
                bt[j]=bt[i];
                bt[i]=temp;
            }
        }
    }
	
    //Calculating turn around time and waiting time for each process
    for(j=0;j<n;j++)
    {
        burst_time=burst_time+bt[j];
        min=bt[k];
    for(i=k;i<n;i++)
    {
        if (burst_time>=at[i] && bt[i]<min)
            {
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				
                temp=at[k];
                at[k]=at[i];
                at[i]=temp;
				
                temp=bt[k];
                bt[k]=bt[i];
                bt[i]=temp;
            }
    }
    k++;
    }
	
	wt[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum-at[i];
        sum_wt=sum_wt+wt[i];
    }
	avg_wt=(sum_wt/n);
	
    for(i=0;i<n;i++)
    {
        ta=ta+bt[i];
        tat[i]=ta-at[i];
        sum_tat=sum_tat+tat[i];
    }
	avg_tat=(sum_tat/n);
	
	printf("\nProcess Name\tBurst Time\t Arrival Time\t Waiting Time\t Turn Around Time" );
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t%d\t\t %d\t\t %d\t\t %d",p[i],bt[i],at[i],wt[i],tat[i]);
    }
	printf("\n\nAVERAGE WAITING TIME : %.2f",avg_wt);
	printf("\nAVERAGE TURN AROUND TIME : %.2f\n",avg_tat);
    return 0;
}