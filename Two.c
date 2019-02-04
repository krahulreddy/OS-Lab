#include<stdio.h>

struct process
{
    int pid, bt, wt, at, ct, tat, rt;
};

void priority(int q, int n, struct process p[])
{
    int T = 0, complete = 0, i, j, completed[n];
    for(i = 0; i < n; i++)
    {
        completed[i] = 0;
        p[i].rt = p[i].bt;
    }
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
        {
            struct process t;
            if(p[j].at > p[j + 1].at)
            {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
       for(i = 0; i < n; i++)
        printf("%d ", p[i].bt);
    for(i = 0; i < n && complete < n; i++)
    {
        printf("\n%d %d %d\n", T, complete, i);
        for(j = 0; j < n; j++)
            printf("%d", p[j].rt);
        if(p[i].at <= T && !completed[i])
        {
            if(p[i].rt <= q)
            {
                T += p[i].rt;
                p[i].ct = T;
                complete++;
                completed[i]++;
                //printf("%d %d\n", p[i].pid, T);
                p[i].rt = 0;
            }
            else
            {
                T += q;
                p[i].rt -= q;
            }
            
        }
        int flag = 0;
        for(j = 0; j < n; j++)
        {
            if(p[j].at <= T && !completed[j])
                flag = 1;
        }
        if(!flag)
            T++;
        if(i == n - 1)
                i = -1;
    }
    printf("\n%d %d\n", T, i);
    for(j = 0; j < n; j++)
            printf("%d ", p[j].rt);
    for(int i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
	printf("\nProcesses\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time \n");
	int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt += p[i].wt;
		total_tat +=p[i].tat;
		printf("%d \t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i].pid, p[i].bt, p[i].at, p[i].wt, p[i].tat, p[i].ct);
	}

	printf("Average waiting time = %f", (float)total_wt / (float)n);
	printf("\nAverage turn around time = %f\n", (float)total_tat / (float)n);
}

int main()
{
    int n, i;
    printf("Enter number of processes : ");
    scanf("%d", &n);
	struct process p[n];
	printf("Enter pid values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i].pid);
    printf("Enter arrival time values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i].at);
    printf("Enter burst time values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i].bt);
	priority(2, n, p); 
	return 0;
}
