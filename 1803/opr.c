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
//			for(j = 0; j < m; j++)
//				if(slot[j] == pr[i])
//					index[j] = i;
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
			int j, max, max_index = -1, dist[m], rep;
			for(j = 0; j < m; j++)
			{
				dist[j] = n + 1;
				int k;
				for(k = i + 1; k < n; k++)
					if(pr[k] == slot[j])
					{
						dist[j] = k - i;
						break;
					}
			}
			for(j = 0; j < m; j++)
				printf("\t\t%d:%d", slot[j], dist[j]);
			printf("\n");
			max = -1;
			for(j = 0; j < m; j++)
			{
				if(max < dist[j])
				{
					max_index = j;
					max = dist[j];
				}
			}
			int r1 = slot[max_index], r2;
			index[max_index] = i;
			slot[max_index] = pr[i];
			printf("dist = %d\t\treplace : %d@%d\n", max, r1, max_index);
		}
	}
	printf("Hits = %d\nMisses = %d\n", hit, miss);
}
