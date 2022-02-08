# os_proj1
Welcome to Thomas Citrowske's OS project 1.
  
To compile/run this project, enter the following two commands:  
make  
./chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile  
  
Options:  
-h            for help.  
-p nprocs     (integer value) Specify number of processes to fork (default 4).  
-c nchars     (integer value) Specify number of characters to read into the buffer (default 80).  
-s sleeptime  (integer value) Specify time to sleep in each iteration (default 3s).  
-i niters     (integer value) Specify number of iterations in the loop.  
< textfile    File containing text to be read through stdin.  
  
  
Version Control  
  
  
Task Observations  
Step #1: Results for different number of processes showed some processes adopted by init while the others maintained parent ID from parent process.  
Step #2: IMGUR LINK TO FIGURE I DREW...  
Step #3: Experimented with a variety of different values for the number of processes. On average, the number of processes adopted by init were 28.64% of the processes.  
Step #4:  
Step #5:  
Step #6:  
Step #7:  
Step #8:  
  
  
Problems with this Project or Anything that I missed  
/--  
