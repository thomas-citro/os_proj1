#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
int main (int argc, char *argv[]) {
	int option;
	while ((option = getopt(arc, argv, "cf")) != -1) {
		switch (option) {
			case 'c' :
				printf("chose c flag\n");
			case 'f' :
				printf("chose f flag\n");
			default:
				printf("Error");
		}
	}
	
	
	int i, n;
	pid_t childpid = 0;
	/*if (argc != 2){ check for valid number of command-line arguments 
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	/*
	
	for (i = 1; i < n; i++)
		if (childpid = fork())
			break;
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
/* This is a comment */
