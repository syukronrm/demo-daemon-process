#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();
	pid_t p_sid = getsid(getpid());	// parent sid
	printf("parent sid = %n\n", (int)p_sid);
	
	if (pid < 0)
	{
		printf("Create new process failed\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		pid_t c_pid = getpid();
		pid_t c_sid = setsid();
		printf("This is child process with Process ID = %d and Session ID = %d\n",
			(int)c_pid, (int)c_sid);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		printf("This is parent process with Process ID = %d\n",
			(int) getpid());
	}

	return EXIT_SUCCESS;
}
