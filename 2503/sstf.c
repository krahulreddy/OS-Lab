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
	int p, m, T = 0;
	scanf("%d %d", &p, &m);
	for(i = 0; i < n; i++)
	{
		int j, min = m + 1, min_pos = -1;
		for(j = 0; j < n; j++)
		{
			if(!complete[j] && d(s[j], p) < min)
			{
				min = d(s[j], p);
				min_pos = j;
			}
		}
		if(min_pos != -1)
		{
			T += d(s[min_pos], p);
			p = s[min_pos];
			complete[min_pos] = 1;
			printf("%d\t", s[min_pos]);
		}
	}
	printf("\nTotal : %d\n", T);
}
