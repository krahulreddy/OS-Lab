#include<stdio.h>
#define size 5

int mutex_c = 1, mutex_p = 1, read_cnt, full;

int wait(int s)
{
	return --s;
}

int signal(int s)
{
	return ++s;
}

void start_consume()
{
	mutex_c = wait(mutex_c);
	printf("Started consuming %d\n", full);
}

void end_consume()
{
	printf("Consumed %d\n", full--);
	mutex_c = signal(mutex_c);
}

void start_produce()
{
	mutex_p = wait(mutex_p);
        printf("Production Started\n");
}

void end_produce()
{
        mutex_p = signal(mutex_p);
        printf("Produced %d\n", ++full);
}

int main()
{
	int flag = 0, n;
	while(!flag)
	{
		printf("1. Start Production\t2. Start Consumption\n3. End Production\t4. End Consumption\t5. Exit\nEnter Choice : ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:	if(mutex_p && mutex_c && full < size)
					start_produce();
				else
					printf("Currently not Possible!!\n");
				if(full == size)
				{
					printf("Buffer is full!!\n");
					break;
				}
				break;
			case 2:	if(mutex_p && mutex_c && full > 0)
					start_consume();
				else
					printf("Currently not Possible!!\n");
				if(full == 0)
				{
					printf("Buffer is empty!!\n");
                                        break;
                                }
				break;
			case 3:	if(!mutex_p)
					end_produce();
				else
					printf("No Producer!!\n");
				break;
			case 4:	if(!mutex_c)
					end_consume();
				else
					printf("No Consumer!!\n");
				break;
			default:flag++;
		}
	}
}
