#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fd[2],n,fd1,len,len1;
	char ss[]="hello students",rr[20];
	
	//if buffer was not created, pipe returns negative number	
	if(pipe(fd)<0)
		exit(-1);
	
	//forking is creating an instance of the same program under a different pid, running as child process along side the parent process
	//fd1 could be named anything	
	fd1=fork();

	len1=strlen(ss);
	
	//here parent process is working with pid 1 for example. Parent process would have fd1>0, which means it would only run the part where fd1>0 in if statement.
	if(fd1>0){
		close(fd[0]);

		//write is a function to write on system level, it accepts as first parameter a descriptor. 0 is standard input(from keyboard) descriptor, 1 is standard output descriptor. 
		// fd[1] is always write since, permissions are rwx, fd[0] is read, fd[1] is write
		n=write(fd[1],ss,len1);
		close(fd[1]);
		printf("Hello from parent\n");
	}

	//here child process is working	with different pid, 2 for example. Child process would have fd==0, which means while reading the file, it would only run the part where fd1==0 in if statement.
	if(fd1==0){
		close(fd[1]);
		n=read(fd[0],rr,len1);
		write(1,rr,n);
		printf("\n");
		close(fd[0]);		
		printf("Hello from child\n");
	}
	
	//because this line is visible and accessible to the 2 processes, it would print 2 times, the first from parent process, the second from child process. 
	printf("Hello from both processes\n");
	return 0;
}
