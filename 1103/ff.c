#include<stdio.h>

int main()
{
	int b, p;
	printf("Enter no of blocks and processes : ");
	scanf("%d %d", &b, &p);
	int bl[b], pr[p], i, used[b], j, best_block;
	printf("Enter block sizes : ");
	for(i = 0; i < b; i++)
	{
		used[i] = 0;
		scanf("%d", &bl[i]);
	}
	printf("Enter process sizes : ");
        for(i = 0; i < p; i++)
                scanf("%d", &pr[i]);
	printf("pid\t\tp.size\t\tb.block\t\trem_fragment\n");
        for(i = 0; i < p; i++)
	{
		printf("%d\t\t%d\t\t", i + 1, pr[i]);
		best_block = -1;
		for(j = 0; j < b && best_block == -1; j++)
		{
			if(best_block == -1 && bl[j] >= pr[i] && used[j] == 0)
				best_block = j;
			if(bl[j] >= pr[i] && bl[j] < bl[best_block] && used[j] == 0)
			{
				best_block = j;
			}
		}
		//printf("%d\t\t", best_block);
		if(best_block == -1)// || (i == 0 && (bl[best_block] >= pr[i])))
			printf("Cannot allocate\n");
		else
		{
			used[best_block]++;
			printf("%d\t\t%d\n", best_block, bl[best_block] - pr[i]);
		}
	}
}
