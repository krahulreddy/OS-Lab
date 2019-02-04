#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

pthread_t prod[10], cons[10];

sem_t mutex, full, empty;
int item;

int size = 10;

void *producer()
{
  sem_wait(&mutex);
  if(item == size)
    printf("Buffer full\n");
  else
{    printf("Produced item : %d\n", ++item);
  sem_post(&full);
  sem_wait(&empty);}
  sem_post(&mutex);
}

void *consumer()
{
  sem_wait(&mutex);
  if(item == 0)
    printf("Buffer Empty!!\n");
  else
  {  printf("Consumed item : %d\n", item--);
  sem_wait(&full);
  sem_post(&empty);}
  sem_post(&mutex);
}

int main()
{
  sem_init(&mutex, 0, 1);
  sem_init(&empty, 0, size);
  sem_init(&full, 0, 0);
  
  int p, c, i;
  printf("Enter number of producers and consumers : ");
  scanf("%d %d", &p, &c);
  for(i = 0; i < p && i < c; i++)
  {
    pthread_create(&prod[i], NULL, producer, NULL);
    pthread_create(&cons[i], NULL, consumer, NULL);
  }
  if(p > c)
  {
    while(i < p)
      pthread_create(&prod[i++], NULL, producer, NULL);
  }
  else
    while(i < c)
      pthread_create(&cons[i++], NULL, consumer, NULL);
  
  for(i = 0; i < p; i++)
    pthread_join(prod[i], NULL);
    
  for(i = 0; i < c; i++)
    pthread_join(cons[i], NULL);
    
}
