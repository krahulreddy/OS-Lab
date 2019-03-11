#include<stdio.h>

struct processes
{
	int id, at, bt, ct, wt, tat;
};

int main()
{
	int n, t, i, j;
	printf("Enter no of processess : ");
	scanf("%d", &n);
	struct processes p[n];
	int complete[n];
	printf("Enter at : ");
	for(i = 0; i < n; i++)
	{
		p[i].id = i;
		complete[i] = 0;
		scanf("%d", &t);
		p[i].at = t;
	}
	printf("Enter bt : ");
        for(i = 0; i < n; i++)
        {
                scanf("%d", &t);
                p[i].bt = t;
        }
	int completed = 0, T = 0;
	while(completed != n)
	{
		t = -1;
		int exec_id = -1;
		for(i = 0; i < n; i++)
		{
			if(p[i].bt > t && p[i].at <= T && !complete[i])
			{
				exec_id = i;
				t = p[i].bt;
			}
		}
		if(exec_id == -1)
			T++;
		else
		{

			completed++;
			complete[exec_id]++;
			T += p[exec_id].bt;
			p[exec_id].ct = T;
		}
	}
	for(i = 0; i < n; i++)
	{
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
	}
}
