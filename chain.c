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
				break;
			case 'c' :
				nchars = atoi(optarg);
				break;
			case 's' :
				sleeptime = atoi(optarg);
				break;
			case 'i' :
				niters = atoi(optarg);
				break;
			default:
				printf("Error");
		}
	}
	int processNumber = nprocs;
	
	int status = 0;
	int i;
	pid_t childpid = 0;
	for (i = 0; i < nprocs; i++) {
		if (childpid = fork()) {
			if (waitpid(childpid, &status, 0) == -1) {
				printf("%s: ", argv[0]);
				perror("Error: ");
				exit(1);
			}
			break;
		} else if (childpid < 0) {
			printf("%s: ", argv[0]);
			perror("Error: ");
			exit(1);
		} else {
			/* child process */
			processNumber--;
		}
	}
	
	pid_t wpid;
	for (i = 0; i < niters; i++) {
		sleep(sleeptime);
		fprintf(stderr, "i:%d ", i);
		fprintf(stderr, "process ID:%ld ", (long)getpid());
		fprintf(stderr, "parent ID:%ld ", (long)getppid());
		fprintf(stderr, "child ID:%ld ", (long)childpid);
		
		int j;
		char mybuf[nchars];
		char c;
		if (i == 0) {
			fseek(stdin, nchars * processNumber * niters, SEEK_SET); /* Seek where we need to read from the input file. */
		}
		for (j = 0; j < nchars; j++) {
			c = getc(stdin);
			mybuf[j] = c;
		}
		mybuf[nchars] = '\0';
		fprintf(stderr, "mybuf:%s\n", mybuf);
	}
	return 0;
}
