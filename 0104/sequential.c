#include<stdio.h>

struct file_alloc{
	char id[10];
	int start, end, size;
}f[20];

int main()
{
	f[0].start = 0;
	int cnt = 0, i;
	while(1)
	{
		printf("Enter 1 to add file and 2 to view table : ");
		int n;
		scanf("%d", &n);
		switch(n)
		{
			case 1:	printf("Enter filename and size :");
				scanf("%s %d", f[cnt].id, &f[cnt].size);
				if(cnt != 0)
					f[cnt].start = f[cnt - 1].end + 1;
				f[cnt].end = f[cnt].start + f[cnt].size - 1;
				cnt++;
				break;
			case 2:	printf("ID\t\tStart\t\tEnd\n");
				for(i = 0; i < cnt; i++)
				{
					printf("%s\t\t%d\t\t%d\n", f[i].id, f[i].start, f[i].end);
				}
		}
	}
}
