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
	int p, m, T = 0, dir, k, temp;
	scanf("%d %d", &p, &m);
	printf("Enter direction (l ==> 1, r ==> 2) : ");
	scanf("%d", &dir);
	for(i = 0; i < n - 1; i++)
		for(k = 0; k < n - i + 1; k++)
		{
			if(s[k] > s[k + 1])
			{
				temp = s[k];
				s[k] = s[k + 1];
				s[k + 1] = temp;
			}
		}
	for(i = 0; i < n; i++)
		printf("%d ", s[i]);
	printf("\n");
	int completed = 0;
	if(dir == 2)
	{
		int pos = p;
		for(i = 0; i < n; i++)
                {
                        if(s[i] >= p)
                        {
				T += d(pos, s[i]);
				complete[i] ++;
				printf("%d(%d)\t", s[i], T);
				pos = s[i];
			}
                }
		T = T + m - pos;
		pos = m;
		printf("%d\t", T);
		for(i = n - 1; i >= 0; i--)
		{
			if(!complete[i])
			{
				T += d(pos, s[i]);
				complete[i] = 1;
				printf("%d(%d)\t", s[i], T);
				pos = s[i];
			}
		}
	}
	else
	{
                int pos = p;
                for(i = n - 1; i >= 0; i--)
                {
                        if(s[i] <= p)
                        {
                                T += d(pos, s[i]);
                                complete[i] ++;
                                printf("%d(%d)\t", s[i], T);
                                pos = s[i];
                        }
                }
                T = T + pos;
                pos = 0;
                printf("%d(%d)\t", pos, T);
                for(i = 0; i < n; i++)
                {
                        if(!complete[i])
                        {
                                T += d(pos, s[i]);
                                complete[i] = 1;
                                printf("%d(%d)\t", s[i], T);
                                pos = s[i];
                        }
                }
/*		int next = -1;
                for(i = 1; i < n; i++)
                {
                        if(s[i - 1] < p && s[i] > p)
                                next = i;
                }
                for(next = next; next >= 0; next--)
                {
                        if(!complete[next])
                        {
                                T += d(s[next], p);
                                p = s[next];
                                completed++;
                                complete[next] = 1;
                                printf("%d\t", s[next]);
                        }
                }
                for(next = 0; next < n; next++)
                {
                        if(!complete[next])
                        {
                                T += d(s[next], p);
                                p = s[next];
                                completed++;
                                complete[next] = 1;
                                printf("%d\t", s[next]);
                        }
                }
*/	}
	printf("\nTotal : %d\n", T);
}
