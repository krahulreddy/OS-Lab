#include<stdio.h>

struct mem{
	int bno;
	struct mem* next;
};

struct file_alloc{
	char id[10];
	struct mem start, end;
	int size;
}f[20];

int blocks[100];

int main()
{
	int cnt = 0, i, j;
	printf("Enter no of allocated blocks : ");
	scanf("%d", &i);
	printf("Enter allocated blocks : ");
	for(j = 0; j < i; j++)
	{
		int y;
		scanf("%d", &y);
		blocks[y] = 1;
	}
	while(1)
	{
		printf("Enter 1 to add file and 2 to view table : ");
		int n;
		scanf("%d", &n);
		switch(n)
		{
			case 1:	printf("Enter filename and size :");
				scanf("%s %d", f[cnt].id, &f[cnt].size);
				for(i = 0; i < 100; i++)
					if(blocks[i] == 0)
					{
						f[cnt].start.bno = i;
						blocks[i]++;
						break;
					}
				struct mem* prev = &f[cnt].start;
				struct mem next;
				for(j = 0; j < f[cnt].size - 1; j++)
				{
					for(; i < 100; i++)
                                        if(blocks[i] == 0)
                                        {
                                                next.bno = i;
						next.next = NULL;
                                                blocks[i]++;
						prev->next = &next;
						prev = &next;
                                                break;
                                        }
				}
				f[cnt].end = *prev;
				cnt++;
				break;
			case 2:	printf("ID\t\tStart\t\tEnd\n");
				for(i = 0; i < cnt; i++)
				{
					printf("%s\t\t%d\t\t%d\t(%p)", f[i].id, f[i].start.bno, f[i].end.bno, f[i].start.next);
					struct mem* a = &f[i].start;
					for(j = 0; a != NULL && j < f[i].size; j++)
					{
						printf("%d->", a->bno);
						a = a->next;
					}
					printf("\n");
				}
		}
	}
}
