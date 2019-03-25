#include<stdio.h>
#include<math.h>

int absolute(int x)
{
        if (x < 0)
                return x * -1;
        return x;
}


int d(int a, int b)
{
	return absolute(a - b);
}

int main()
{
	int n;
	printf("Enter no of requests: ");
	scanf("%d", &n);
	printf("Enter sequence :");
	int s[n], i, complete[n];
	for(i = 0; i < n; i++)
	{
		complete[i] = 0;
		scanf("%d", &s[i]);
	}
	printf("Enter header position and max :");
	int p, m, T = 0, dir;
	scanf("%d %d", &p, &m);
	printf("Enter direction (l ==> 1, r ==> 2) : ");
	scanf("%d", dir);
	for(i = 0; i < n; i++)
		for(k = 1;k < n - i + 1; k++)
		{
			if(s[k] >s[k + 1])
			{
				temp = s[k];
				s[k] = s[k + 1];
				s[k + 1] = temp;
			}
		}
	if(dir == 1)
	{
		int next = -1;
		
		for(i = 0; i < n - 1; i++)
		{
			if(s[i] < p && s[i + 1] > p)
				next = i;
		}
			int j, min = m + 1, min_pos = -1;
			for(j = 0; j < n; j++)
			{
				if(!complete[j] && d(s[j], p) < min)
				{
					min = d(s[j], p);
					min_pos = j;
				}
			}
			if(next != -1)
			{
				T += d(s[min_pos], p);
				p = s[min_pos];
				complete[min_pos] = 1;
				printf("%d (%d)\t", s[min_pos], s[i]);
			}
		}
	}
	else
	{
	}
	printf("\nTotal : %d\n", T);
}
