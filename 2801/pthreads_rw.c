#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

pthread_t rd[100], wrt[100];

sem_t mutex, wr;
int r_count;

int size = 10;

void *reader(int i)
{
  sem_wait(&mutex);
  printf("Reader added : %d\n", i);
  ++r_count;
  sem_post(&mutex);
  sem_wait(&wr);
  sleep(3);
  printf("Reader removed : %d\n", i);
  --r_count;
  sem_post(&wr);
}

void *writer(int i)
{
  sem_wait(&mutex);
  sem_wait(&wr);
  if(r_count != 0)
    printf("Writer %d is Waiting...\n", i);
  printf("Writer added : %d\n", i);
  sleep(1);
  printf("Writer removed : %d\n", i);
  sem_post(&wr);
  sem_post(&mutex);
}

int main()
{
  sem_init(&mutex, 0, 1);
  sem_init(&wr, 0, 1);
  int p, c, i;
  printf("Enter number of readers and writers : ");
  scanf("%d %d", &p, &c);
  for(i = 0; i < p && i < c; i++)
  {
    pthread_create(&rd[i], NULL, reader, i + 1);
    pthread_create(&wrt[i], NULL, writer, i + 1);
  }
  if(p > c)
  {
    while(i < p)
      pthread_create(&rd[i++], NULL, reader, i + 1);
  }
  else
    while(i < c)
      pthread_create(&wrt[i++], NULL, writer, i + 1);
  
  for(i = 0; i < p; i++)
    pthread_join(rd[i], NULL);
    
  for(i = 0; i < c; i++)
    pthread_join(wrt[i], NULL);
}
