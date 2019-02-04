#include<stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int at[])
{
	int rt[n], i, complete = 0, T = 0, min = 100000000, job = 0, flag = 0;
	for(i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }
    while(complete != n)
    {
        
        for(i = 0; i < n; i++)
        {
            if(at[i] <= T && rt[i] < min && rt[i] > 0)
            {
                min = rt[i];
                job = i;
                flag = 1;
                //printf("%d %d\n", complete, T);
            }
        }
        if (flag == 0)
        {
            T++;
            continue;
        }
        rt[job]--;
        min = rt[job];
        if(min == 0)
            min = 100000000;
        if(rt[job] == 0)
        {
            //printf("%d", complete);
            complete++;
            flag = 0;
            wt[job] = T + 1 - bt[job] - at[job];
            if(wt[job] < 0)
                wt[job] = 0;
        }
        T++;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void srtf(int n, int pid[], int bt[], int at[])
{
	int wt[n], tat[n];
	int i;
	

	// for(i = 0; i < n; i++)
	// {
	// 	printf("%d ", at[i]);
	// }

	findWaitingTime(n, bt, wt, at);

	findTurnAroundTime(n, bt, wt, tat);

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
	srtf(n, pid, burst_time, arrival_time); 
	return 0;
}
