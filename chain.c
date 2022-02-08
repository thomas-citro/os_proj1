#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
int main (int argc, char *argv[]) {
	int nprocs = 4;
	int nchars = 80;
	int sleeptime = 3;
	int niters;
	
	int option;
	while ((option = getopt(argc, argv, "hp:c:s:i:")) != -1) {
		switch (option) {
			case 'h' :
				printf("Chose h flag. Will have to see what this is supposed to do.\n");
				break;
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
	
	printf("nprocs: %d, nchars: %d\n",nprocs,nchars);
	
	int i;
	pid_t childpid = 0;
	for (i = 0; i < nprocs; i++) {
		if (childpid = fork()) {
			printf("I'm a parent (PID: %ld) that just forked off a child with PID: %ld\n", (long)getpid(),(long)childpid);

			wait();
			printf("I'm a parent (PID: %ld) that just finished waiting for my child (PID: %ld) to complete execution.", (long)getpid(), (long)childpid);
			printf(" I'm now breaking out of for loop\n"); 
			break;
		}
		char mybuf[nchars];
		char c;
		for (i = 0; i < nchars; i++) {
			c = getc(stdin);
			printf("(PID: %ld)... character #%d: %c\n", (long)getpid(), i, c);
		}
	}
	printf("Someone is out of the for loop\n");
	
	/*
	int i;
	pid_t childpid, wpid;
	int status = 0;
	int id = 0;
	for (id = 0; id < nprocs; id++) {
	    if ((childpid = fork()) == 0) {
		//child code
		exit(0);
	    }
	}
	while ((wpid = wait(&status)) > 0);
	printf("Hello, I am process ID: %ld. Just finished waiting on all child processes.\n", (long)getpid());
	*/
	
	for (i = 1; i < niters; i++)
		sleep(sleeptime);
	
	/*
	char mybuf[nchars];
	char c;
	for (i = 0; i < nchars; i++) {
		c = getc(stdin);
		printf("(PID: %ld)... character #%d: %c\n", (long)getpid(), i, c);
	}
	mybuf[nchars] = '\0';
	*/
	
	/*fscanf(stdin, "%s", mybuf);*/
	
	/*fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);*/
	
	return 0;
}
