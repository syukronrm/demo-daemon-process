#include <stdio.h>
#include <pthread.h>

int i = 0;

void *run(void *args) 
{
	while (i < 20)
	{
		++i;
		printf("Thread 1 : %d\n", i);
	}
}

void *run2(void *args)
{
	while (i < 40)
	{
		++i;
		printf("Thread 2 : %d\n", i);
	}
}

int main()
{
	int *tes = 0;
	pthread_t t1, t2;
	pthread_create(&t1, NULL, run, NULL);
	pthread_create(&t2, NULL, run2, NULL);
	
	int n = 0;
	pthread_join(t1, NULL);
	for (n = 100; n < 110; ++n)
	{
		printf("Main : %d\n", n);
	}
	pthread_join(t2, NULL);
	return 0;
}




