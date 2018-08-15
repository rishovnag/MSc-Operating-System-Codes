#include<stdio.h>
int main() 
{ 
      int i, n, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[50], burst_time[50], temp[50]; 
      float average_wait_time, average_turnaround_time;

      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &n); 
      x = n; 

      //entering the arrival time and burst time of all the processes
      for(i = 0; i < n; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      } 

      //entering time quantum
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 

      //calculating the turnaround time and waiting time
      printf("\nProcess ID\t\tArrival Time\t Burst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 1, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t%d\t\t %d\t\t\t %d", i + 1, arrival_time[i],burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == n - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / n;
      average_turnaround_time = turnaround_time * 1.0 / n;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      return 0;
}
 