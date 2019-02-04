#include<stdio.h>

int isempty(int a[], int n)
{
  int i;
  for(i = 0; i < n; i++);
    if(a[i] != -1)
      return 0;
  return 1;
}

int minind(int a[], int n)
{
  int i, min = 1000000;
  for(i = 0; i < n; i++);
    if(a[i] < min && a[i] > 0)
      min = a[i];
  for(i = 0; i < n; i++);
    if(a[i] == min)
      return i;
  return -1;
}

void rr(int k, int n, int pid[], int bt[], int at[])
{
  int order[n], q[n], ct[n], wt[n], tat[n];
  int i, j, T = 0, comp = 0, start = -1, end = -1, flag, o = 0;
  for(i = 0; i < n; i++)
  {
    q[i] = -1;
    order[i] = 0;
  }
  while(comp != n && T < 35)
  {
    flag = 0;
    for(i = 0; i < n; i++)
    {
      if(q[i] == -1 && at[i] <= T)
      {
        q[i] = bt[i];
        order[i] = ++o;
        end = i;
        flag = 1;
      }
    }
    
    //exec(minind(order));
  //  if(minind(order, n) == -1)
    //{
      //printf("1Idle at T = %d\n", T);
  //    T++;
    //  continue;
    //}
    
    if(flag == 0)
    {
      printf("Idle at T = %d\n", T);
      T++;
      continue;
    }
    
    if(q[minind(order, n)] <= k)
    {
      T = T + q[minind(order, n)];
      ct[minind(order, n)] = T;
      printf("%d %d", T, minind(order, n));  
      comp++;
      order[minind(order, n)] = 0;
      q[minind(order, n)] = 0;
    }
    else
    {
      q[minind(order, n)] -= k;
      T+= k;
      order[minind(order, n)] = o + 1;
    }
    
    
  }
  printf("Processes\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time \n");
	int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
	  tat[i] = ct[i] - at[i];
	  wt[i] = tat[i] - bt[i];
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("%d \t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", pid[i], bt[i], at[i], wt[i], tat[i], ct[i]);
	}

	printf("Average waiting time = %f", (float)total_wt / (float)n);
	printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
      
}

int main()
{
    int n, k;
    printf("Enter Qtime quantum value : ");
    scanf("%d", &k);
    printf("Enter number of processes : ");
    scanf("%d", &n);
	  int pid[n], burst_time[n], arrival_time[n], pty[n], i;
    printf("Enter pid values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &pid[i]);
    printf("Enter arrival time values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &arrival_time[i]);
    printf("Enter burst time values : ");
    for(i = 0; i < n; i++)
        scanf("%d", &burst_time[i]);
	  rr(k, n, pid, burst_time, arrival_time); 
	  return 0;
}
