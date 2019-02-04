#include<stdio.h>

struct process
{
    int pid, bt, wt, at, ct, pty, tat;
};

void priority(int n, struct process p[])
{
    int T = 0, complete = 0, completed[n], i;
    for(i = 0; i < n; i++)
    {
        completed[i] = 0;
    }
    while(complete < n)
    {
//        printf("%d %d\n", complete, T);
        int rem = n - complete, ex_pty = 10000000, execute;
//        process av[rem];
        execute = -1;
        for(i = 0; i < n; i++)
        {
            if(!completed[i] && p[i].at <= T && p[i].pty < ex_pty){
                ex_pty = p[i].pty;
                execute = i;
            }
            else if(!completed[i] && p[i].pty == ex_pty && p[i].at < p[execute].at)
            {
                ex_pty = p[i].pty;
                execute = i;
            }
        }
        if(execute != -1)
        {
            printf("//%d// %d//\n", execute, T);
            p[execute].ct = T + p[execute].bt;
            T += p[execute].bt;
            completed[execute]++;
            complete++;
            
        }
        else
            T++;
    }
    for(int i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
	printf("\nProcesses\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurn-Around Time\tCompletion Time \n");
	int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt += p[i].wt;
		total_tat +=p[i].tat;
		printf("%d \t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i].pid, p[i].bt, p[i].at, p[i].pty, p[i].wt, p[i].tat, p[i].ct);
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
    printf("Enter priority values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i].pty);
	priority(n, p); 
	return 0;
}
