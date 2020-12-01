#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void sighandler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\nProgram exited due to SIGINT\n");
		exit(0);
	}
	else if (signo == SIGUSR1)
	{
		printf("Parent PID: %d\n",getppid());
	}
}

int main()
{
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);

	while (1)
	{
		printf("My PID: %d\n", getpid());
		sleep(1);
	}

	return 0;
}