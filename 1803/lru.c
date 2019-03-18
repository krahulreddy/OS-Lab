#include<stdio.h>

int m, n;

int isahit(int ref, int slot[])
{
	int i;
	for(i = 0; i < m; i++)
		if(slot[i] == ref)
			return 1;
	return 0;
}


int main()
{
	printf("Enter number of page slots : ");
	scanf("%d", &m);
	printf("Enter page reference string length: ");
	scanf("%d", &n);
	printf("Enter page reference string : ");
	int pr[n], i, slot[m], index[m];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &pr[i]);
//		index[pr[i]] = i;
	}
	for(i = 0; i < m; i++)
	{
		slot[i] = -1;
		index[i] = -1;
	}

	int used = 0, hit = 0, miss = 0;

	for(i = 0; i < n; i++)
	{
		printf("%d\n", pr[i]);
		if(isahit(pr[i], slot))
		{
			printf("Hit\n");
			hit++;
			int j;
			for(j = 0; j < m; j++)
				if(slot[j] == pr[i])
					index[j] = i;
			continue;
		}
		miss++;
		if(used < m)
		{
			index[used] = i;
			slot[used++] = pr[i];
		}
		else
		{
			int j, min = n + 1, min_index = -1;
			for(j = 0; j < m; j++)
			{
				if(index[j] < min)
				{
					min = index[j];
					min_index = j;
				}
			}
			index[min_index] = i;
			slot[min_index] = pr[i];
			printf("replace : %d@%d\n", pr[min_index], min_index);
		}
	}
	printf("Hits = %d\nMisses = %d\n", hit, miss);
}
