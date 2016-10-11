#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int i;
	pid_t pids[10];
	pid_t parentSid = null, childSid = null;

	parentSid = childSid = getsid(getpid());
	printf("All child's Session ID is %d\n", (int) parentSid);

	for (i = 9; i >= 0; --i) {
		pids[i] = fork();
		if (pids[i] == 0) {
			childSid = setsid();
			printf("Sesson ID of child %d is %d\n", i, (int) childSid);
			// printf("PID of child %d is %d, sleeptime\n", i, getpid());
			if (i != 9 )
				sleep(i+1);	// sleep for i+1 seconds
			else
				sleep(15);	// sleep for 60 seconds
			// printf("Child %d wake up\n", i);
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
