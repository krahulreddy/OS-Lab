#include<stdio.h>
#define size 5

int read = 1, wrt = 1, read_cnt;

int wait(int s)
{
	return --s;
}

int signal(int s)
{
	return ++s;
}

void start_read()
{
	read = wait(read);
	printf("Reader %d started reading\n", ++read_cnt);
}

void end_read()
{
	printf("Reader %d stopped reading\n", read_cnt--);
	read = signal(read);
}

void start_write()
{
	wrt = wait(wrt);
        printf("Writer Started\n");
}

void end_write()
{
        wrt = signal(wrt);
        printf("Writer Ended\n");
}

int main()
{
	int flag = 0, n;
	while(!flag)
	{
		printf("1. Start Write\t2. Start Read\n3. End Write\t4. End Read\t5. Exit\nEnter Choice : ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:	if(wrt == 1 && read_cnt == 0)
					start_write();
				else
					printf("Currently not Possible!!\n");
				break;
			case 2:	if(wrt == 1)
					start_read();
				else
					printf("Currently not Possible!!\n");
				break;
			case 3:	if(wrt == 0)
					end_write();
				else
					printf("No Writers!!\n");
				break;
			case 4:	if(read_cnt > 0)
					end_read();
				else
					printf("No Readers!!\n");
				break;
			default:flag++;
		}
	}
}
