#include<stdio.h>
#include<pthread.h>

pthread_t phil[100];
pthread_mutex_t chop[100];

int p, i, j;

void *dining(int i)
{
	while(1)
	{
	printf("Phil %d is thinking\n", i);
	pthread_mutex_lock(&chop[i]);
	pthread_mutex_lock(&chop[(i + 1) % p]);
	printf("Phil %d is eating\n", i);
	for(j = 0; j < 100000; j++)
		;
	printf("Phil %d finished eating\n", i);
	pthread_mutex_unlock(&chop[i]);
	pthread_mutex_unlock(&chop[(i + 1) % p]);
	}
}
int main()
{
	scanf("%d", &p);
	for(i = 0; i < p; i++)
		pthread_mutex_init(&chop[i], NULL);
	for(i = 0; i < p; i++)
		pthread_create(&phil[i], NULL, (void *)dining, i);
	for(i = 0; i < p; i++)
	{
		pthread_join(phil[i], NULL);
		pthread_mutex_destroy(&chop[i]);
	}
}
