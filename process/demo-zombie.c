#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int i;
	pid_t pids[10];
	printf("tesing\n");

	for (i = 9; i >= 0; --i) {
		pids[i] = fork();
		if (pids[i] == 0) {
			printf("PID of child %d is %d, sleeptime\n", i, getpid());
			if (i != 9 )
				sleep(i+1);	// sleep for i+1 seconds
			else
				sleep(15);	// sleep for 60 seconds
			printf("Child %d wake up\n", i);
			_exit(0);
		}
	}

	for (i = 9; i >= 0; --i)
	{
		printf("Waiting for child %d to wake up\n", i);
		waitpid(pids[i], NULL, 0);
	}

	return 0;
}
