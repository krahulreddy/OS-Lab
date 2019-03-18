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

	int used = 0, hit = 0, miss = 0, ind = m - 1, rep;

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
					rep = j;
			continue;
		}
		miss++;
		if(used < m)
		{
			index[used] = i;
			slot[used++] = pr[i];
			rep = used - 1;
		}
		else
		{
			int j, max = -1, max_index = -1;
//			for(j = 0; j < m; j++)
//			{
//				if(index[j] > max)
//				{
//					max = index[j];
//					max_index = j;
//				}
//			}
//			index[max_index] = i;
			int r1, r2;
			r1 = slot[rep];
			slot[rep] = pr[i];
			printf("replace : %d@%d\n", r1, rep);
		}
	}
	printf("Hits = %d\nMisses = %d\n", hit, miss);
}
