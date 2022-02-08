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
Step #3: Experimented with a variety of different values for the number of processes. On average, 28.64% of the processes were adopted by init.  
Step #4: Added "sleep(10);" before the final fprintf statement. I then experimented with a variety of different values for the number of processes On average, 40.50% of the processes were adopted by init. I also noticed that once the number of processes exceeded 27, the program would stop forking more processes (fork() returned error -1).  
Step #5: I put sleep(sleeptime); and the final fprintf statement inside a loop that loops niters times. I observed that init adoptions would only occur on the final iteration of this for loop. This is because, for all the first iterations, the processes don't terminate. However, processes will terminate after completing the final iteration. So for any processes that complete out of order, the child process will be adopted by init before the child runs the fprintf statement (since the parent had already terminated).  
Step #6: After adding wait(); before fprintf, I noticed that the youngest child ran all iterations and fprintf statements first and then terminated. Next, its parent ran all iterations and fprintf statements and terminated. The same idea continued until all processes terminated... Because the parent processes waited for the children to terminate, there were no init adoptions made, and the output was ordered nicely. Also, I am still unable to run 100 processes because during wait, the processes are still alive/running (so we are still restricted by the process limit).   
Step #7: Splitting up fprintf into 4 separate fprintf statements resulted in no difference in the output of the program. However, removing the 'wait' statement on top of this resulted in a race condition where the processes performed their fprintf statements simultaneously resulting in the output becoming unordered and difficult to decipher which process generated each part of the output.  
Step #8:  
  
  
Problems with this Project or Anything that I missed  
/--  
