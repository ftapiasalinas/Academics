/* This program takes in an argument, a number of seconds.
It creates a copy of itself, the child waits that many seconds and dies,
the parent waits for the child to die, and then the parent dies.  */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DEFAULT_TIME 5

int main (int argc, char **argv) {
	int child_id;
	int seconds;
	int status;
	pid_t whodied;

	if (argc == 1)
		seconds = DEFAULT_TIME;
	else
		seconds = atoi (argv[1]);

	printf ("Here I am in the program!  Time to wait = %d\n", seconds);

	child_id = fork();

	if (child_id) //parent process
{
		printf ("I'm the parent.  Here's a process list:\n");
		system ("ps -l");
		whodied = wait (&status);
		printf ("Child %d exited ", whodied);
		if (! WIFEXITED(status)) {
			printf ("abnormally!\n");
			}
		else {
			printf ("with status %d.\n", WEXITSTATUS(status));
			}
		printf ("Here's another process list:\n");
		system ("ps -l");
		return 0;
		}
	else {
		sleep(seconds);
		printf ("I'm the child.  Here's a process list:\n");
		system ("ps -l");
		printf ("Bye now!\n");
		return 0;
		}
	}
