// C program to implement sighup(), sigint()
// and sigquit() signal functions
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// function declaration
void sigint();

// driver code
int main()
{
	int pid;

	if ((pid = fork()) < 0) {
		exit(1);
	}

	if (pid == 0) {
		signal(SIGINT, sigint);
		for (;;);
	}
	else 
	{ 
		sleep(3); 
		printf("\nPARENT: sending SIGINT\n\n");
		kill(pid, SIGINT);
	}
}

void sigint()
{
	signal(SIGINT, sigint); /* reset signal */
	printf("CHILD: I have received a SIGINT\n");
}
