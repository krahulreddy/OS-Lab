#include<stdio.h>
#define size 5

int semaphore = 1, full, item;

int wait(int s)
{
	return --s;
}

int signal(int s)
{
	return ++s;
}

void produce()
{
	semaphore = wait(semaphore);
	full++;
	item++;
	printf("Produced %d\n", item);
	semaphore = signal(semaphore);
}

void consume()
{
	semaphore = wait(semaphore);
        full--;
        item--;
        printf("Consumed %d\n", item + 1);
        semaphore = signal(semaphore);
}

int main()
{
	int flag = 0, n;
	while(!flag)
	{
		printf("1. Produce\t2. Consume\t3. Exit\nEnter Choice : ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:	if(semaphore == 1 && full != size)
					produce();
				else
					printf("Buffer is full!!\n");
				break;
			case 2:	if(semaphore == 1 && full != 0)
					consume();
				else
					printf("Buffer is empty!\n");
				break;
			default:flag++;
		}
	}
}
