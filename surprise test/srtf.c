#include<stdio.h>

struct processes
{
	int id, at, bt, rt, ct, wt, tat;
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
                p[i].bt = p[i].rt = t;
        }
	int completed = 0, T = 0;
	while(completed != n)
	{
		t = 1000;
		int exec_id = -1;
		for(i = 0; i < n; i++)
		{
			if(p[i].rt < t && p[i].at <= T && !complete[i])
			{
				exec_id = i;
				t = p[i].rt;
			}
		}
		if(exec_id == -1)
			T++;
		else
		{
			if(p[exec_id].rt == 1)
			{
				completed++;
				complete[exec_id]++;
				p[exec_id].ct = T + 1;
			}
			p[exec_id].rt--;
			T++;
		}
	}
	for(i = 0; i < n; i++)
	{
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
	}
}
