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
	
	
	int i, n;
	n = nprocs;
	pid_t childpid = 0;
	if (argc != 2){ check for valid number of command-line arguments 
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	
	
	for (i = 1; i < n; i++)
		if (childpid = fork())
			break;
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	
	return 0;
}
