#include<stdio.h>
#include<malloc.h>
int*at,*bt,*track_bt,*flag,*ct,*tat,*wt,atat=0,awt=0;

void heap_build_bt(int n, int i)
{
    int largest = i;  /* Initialize largest as root*/
    int l = 2*i + 1;  /*leftchild of largest(i.e. i) = 2*i + 1[0<=i<=n-1]*/
    int r = 2*i + 2;  /* right = 2*i + 2*/
 	int temp;
    /*If left child is larger than root*/
    if (l < n && bt[l] > bt[largest])
        largest = l;	/*Make l as the largest*/
 
    /*If right child is larger than largest so far*/
    /**/
    if ((r < n) && (bt[r] > bt[largest]))
        largest = r;
 
    // If largest is not root
    if(largest!=i)
    {
        temp=bt[i];
        bt[i]=bt[largest];	/*Swap between the old largest and current largest*/
        bt[largest]=temp;
    	temp=track_bt[i];
    	track_bt[i]=track_bt[largest];
    	track_bt[largest]=temp;
        // Recursively heapify the affected sub-tree
        heap_build_bt(n, largest);			/*To check whether the current moved small node is greater than the other child*/
    }
}
int min(int n)
{
    int i=1,min=at[0];
    for(i=1;i<n;i++)
    {
        if(min>at[i])
        {
            min=at[i];
        }
    }
    return min;
}
int nottrueflag(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            return 1;
        }
     }
        return 0;
}
void heapsort(int n)
{
	int i,temp,sum;
    
for (i = n / 2 - 1; i >= 0; i--)
	heap_build_bt(n, i);				/*n/2-1 gives us the flexibility to check all the child of a node*/

    // One by one extract an element from heap
    for (i=n-1; i>=0; i--)
    {

	// Deleting the root and making the i th element the root
	temp=bt[0];
	bt[0]=bt[i];
	bt[i]=temp;
		
	temp=track_bt[0];
	track_bt[0]=track_bt[i];
	track_bt[i]=temp;
	// call max heapify on the reduced heap and adjust the heap for new insertion of the ith element in the heap
	heap_build_bt(i, 0);
	}
     sum=min(n);	//get the minimum arrival time; if the timeline doesn't start from 0.
i=0;
    while(nottrueflag(n))
    {
        int c=track_bt[i];
        if((at[c]<=sum) && (flag[c]==0))		//if the arrival time<= current completion time
        {
            wt[c]=sum-at[c];
             awt=awt+wt[c];
		     sum=sum+bt[i];
	        ct[c]=sum;					//Doing Calculation staff
	        tat[c]=ct[c]-at[c];
            atat=atat+tat[c];
            flag[c]=1;
        }
        else if(i>=n)
        {
            i=0;
        }
        else
        {
            i++;
        }
        
    }

}
int main()
{
	int n,i;
	label:printf("\nEnter the number of Processes: ");	/*label for wrong input checking*/
	scanf("%d",&n);
	if(n>0)
	{
		at=(int*)malloc(n*sizeof(int));
		bt=(int*)malloc(n*sizeof(int));
		ct=(int*)malloc(n*sizeof(int));
		wt=(int*)malloc(n*sizeof(int));
		tat=(int*)malloc(n*sizeof(int));
        flag=(int*)malloc(n*sizeof(int));
        track_bt=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			printf("\n Enter the arrival time for the process%d: ",i+1);
			scanf("%d",&at[i]);
			printf("\n Enter the burst time for the process%d: ",i+1);
			scanf("%d",&bt[i]);
            track_bt[i]=i;
            flag[i]=0;
		}
		heapsort(n);
        printf("\nShortest Job First(SJF) Algorithm");
        printf("\nComplexity=0(nlogn)");
        printf("\n=================================================\n");
		printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
		for(i=0;i<n;i++)
		{
			printf("P%d\t     %d\t            %d\t          %d\t             %d\t           %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		}
        printf("\nAverage Turn Around Time=%lf\nAverage Waiting Time=%lf",(double)(atat/n),(double)(awt/n));
        
	}
	else
	{
		printf("\nWrong Input:Ready to give correct input");
		goto label;
	}
	return 0;
	
}
