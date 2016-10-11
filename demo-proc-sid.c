#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();

	if (pid < 0)
	{
		printf("Create new process failed\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		pid_t pid = getpid();
		pid_t sid = setsid();
		printf("This is child process with Process ID = %d and Session ID = %d\n",
			(int)pid, (int)sid);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		printf("This is parent process with Process ID = %d\n",
			(int) getpid());
	}

	return EXIT_SUCCESS;
}
