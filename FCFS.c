#include<stdio.h>

void findWaitingTime(int pid[], int n, int bt[], int wt[], int at[])
{
	int service_time[n];
	service_time[0] = 0;
	wt[0] = 0;
	for (int i = 1; i < n ; i++)
	{
		service_time[i] = service_time[i-1] + bt[i-1];
		wt[i] = service_time[i] - at[i];
		if (wt[i] < 0)
			wt[i] = 0;
	}
}

void findTurnAroundTime(int pid[], int n, int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void fcfs(int n, int pid[], int bt[], int at[])
{
	int wt[n], tat[n];
	int i, j, t;
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(at[j] > at[j + 1])
			{
				t = at[j];
				at[j] = at[j + 1];
				at[j + 1] = t;
				t = bt[j];
				bt[j] = bt[j + 1];
				bt[j + 1] = t;
				t = pid[j];
				pid[j] = pid[j + 1];
				pid[j + 1] = t;
			}
		}
	}

	// for(i = 0; i < n; i++)
	// {
	// 	printf("%d ", at[i]);
	// }

	findWaitingTime(pid, n, bt, wt, at);

	findTurnAroundTime(pid, n, bt, wt, tat);

	printf("Processes\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time \n");
	int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int compl_time = tat[i] + at[i];
		printf("%d \t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", pid[i], bt[i], at[i], wt[i], tat[i], compl_time);
	}

	printf("Average waiting time = %f", (float)total_wt / (float)n);
	printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
}

int main()
{
    int n;
    printf("Enter number of processes : ");
    scanf("%d", &n);
	int pid[n], burst_time[n], arrival_time[n], i;
    printf("Enter pid values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &pid[i]);
    printf("Enter arrival time values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &arrival_time[i]);
    printf("Enter burst time values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &burst_time[i]);
	fcfs(n, pid, burst_time, arrival_time); 
	return 0;
}
