#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
int main (int argc, char *argv[]) {
	int nprocs = 4;
	int nchars = 80;
	int sleeptime = 3;
	int niters = 1;
	
	int option;
	while ((option = getopt(argc, argv, "hp:c:s:i:")) != -1) {
		switch (option) {
			case 'h' :
				printf("Usage: ./chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\n");
				printf("Runs chain processes with the specified arguments\n\n");
				printf("Options:\n");
				printf("-h 		for help\n");
				printf("-p nprocs 	(integer) Specify number of processes to fork (default 4).\n");
				printf("-c nchars 	(integer) Specify number of characters to read into the buffer (default 80).\n");
				printf("-s sleeptime 	(integer) Specify time to sleep in each iteration (default 3s).\n");
				printf("-i niters 	(integer) Specify number of iterations in the loop (default 1).\n");
				printf("< textfile 	File containing text to be read through stdin.\n");
				return 0;
			case 'p' :
				nprocs = atoi(optarg);
				printf("Chose p flag. Set nprocs to %d\n", nprocs);
				break;
			case 'c' :
				nchars = atoi(optarg);
				printf("Chose c flag. Set nchars to %d\n", nchars);
				break;
			case 's' :
				sleeptime = atoi(optarg);
				printf("Chose s flag. Set sleeptime to %d\n", sleeptime);
				break;
			case 'i' :
				niters = atoi(optarg);
				printf("Chose i flag. Set niters to %d\n", niters);
				break;
			default:
				printf("Error");
		}
	}
	
	int i;
	pid_t childpid = 0;
	for (i = 0; i < nprocs; i++) {
		if (childpid = fork()) {
			break;
		} else if (childpid == -1) {
			printf("\n\nMade it in the perror for the childpid\n\n");
			perror("chain: Error: ");
		}
	}
	
	/*mybuf[nchars] = '\0';*/
	/*fscanf(stdin, "%s", mybuf);*/
	
	int status = 0;
	pid_t wpid;
	for (i = 0; i < niters; i++) {
		sleep(sleeptime);
		waitpid(childpid, &status, 0);
		fprintf(stderr, "i:%d ", i);
		fprintf(stderr, "process ID:%ld ", (long)getpid());
		fprintf(stderr, "parent ID:%ld ", (long)getppid());
		fprintf(stderr, "child ID:%ld\n", (long)childpid);
		
		int j;
		char mybuf[nchars];
		char c;
		for (j = 0; j < nchars; j++) {
			c = getc(stdin);
			/*perror("getc");*/
			printf("(PID: %ld)... character #%d: %c\n", (long)getpid(), j, c);
		}
	}
	return 0;
}
