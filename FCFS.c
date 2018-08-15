#include<stdio.h>
int main()
{
	int n, p[50] = { 0 }, at[50] = { 0 }, bt[50] = { 0 }, wt[50] = { 0 }, tat[50] = { 0 }, ct[50] = { 0 }, i=0, j, temp = 0;
	float avtat = 0.0, avwt = 0.0;

	printf("Enter total number of processes:");
	scanf("%d", &n);

	//entering the arrival time for the processes
	for (i = 0; i < n; i++)
	{
		printf("Enter the arrival time for process number %d: ",i + 1);
		scanf("%d", &at[i]);

	}

	//entering the burst time for the processes
	for (i = 0; i<n; i++)
	{
		printf("Enter the burst time for process number %d:", i + 1);
		scanf("%d", &bt[i]);
	}

	//sorting the processes according to arrival time
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < (n - i); j++)
		{
			if (at[j] > at[j + 1])
			{
				temp = at[j];
				at[j] = at[j + 1];
				at[j + 1] = temp;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
			}
		}
	}

	//calculating completion time
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			ct[i] = ct[i] + bt[j];

	//calculating waiting time
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			wt[i] = wt[i] + bt[j];

	//calculating turn around time and summation of waiting time and turn around time
	for (i = 0; i < n; i++)
	{
		tat[i] = ct[i] - at[i];
		avwt += wt[i];
		avtat += tat[i];
	}

	avwt = avwt / n;	//average waiting time
	avtat = avtat / n;	//average turn around time

	printf("\nProcess Number\tArrival Time \tBurst Time \tCompletion Time \tWaiting Time \tTurnaround Time\n");
		for (i = 0; i < n; i++)
			printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],wt[i],tat[i]);
	printf("The Average Waiting Time is %.2f\n", avwt);
	printf("The Average Turn Around Time is %.2f", avtat);
}
