#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pids[10];
	int i;

	for (i = 9; i >= 0; --i) {
		pids[i] = fork();
		if (pids[i] == 0) {
			sleep(i+1);
			printf("Child %d with Process ID : %d\n", i, (int)getpid());
			if (i == 9 )
				sleep(100);
			printf("Child %d wake up\n", i);
			_exit(0);
		}
	}

	for (i = 9; i >= 0; --i)
	{
		printf("Waiting on child %d to end\n", i);
		waitpid(pids[i], NULL, 0);
	}

	return 0;
}
