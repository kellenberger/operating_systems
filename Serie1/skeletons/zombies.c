/* gcc -Wall -std=gnu99 zombies.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* this method creates a child process and instantly completes (exits) it */
void create_zombie() {
	if(fork() == 0)
	{
		exit(0);
	}
}

int main(void)
{
	int wait = 15;

	create_zombie();

	/* this will wait for 15 seconds */
	while(wait)
	{
		wait = sleep(wait);
	}

	/* this finishes the current process and with it the child (zombie) process */
	exit(0);

	return 0;
}
