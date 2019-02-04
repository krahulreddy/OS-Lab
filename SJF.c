#include<stdio.h>
void findWT(int n, int bt[], int wt[])
{
	wt[0] = 0;
	for (int i = 1; i < n ; i++)
		wt[i] = bt[i-1] + wt[i-1];
}

void findTAT(int n, int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void sort(int pid[], int n, int bt[], int at[])
{
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

	int k = 1, ind = 0, min;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if((at[j + 1] == at[j]) && (bt[j] > bt[j + 1]))
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
	int T = 0, complete = 0;
	while(complete != n)
	{
    for(i = 0; i < n; i++)
    {
      if(at[i] <= T)
      {
        
  }
    
}

void sjf(int n, int pid[], int bt[], int at[])
{
    int i, j;

	sort(pid, n, bt, at);
	int wt[n], tat[n];

	findWT(n, bt, wt);

	findTAT(n, bt, wt, tat);

	printf("Processes\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time \n");
	int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int compl_time = tat[i];
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
	sjf(n, pid, burst_time, arrival_time);
	return 0;
}
