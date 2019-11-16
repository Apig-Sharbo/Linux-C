#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO "fifo.l"
#define MAXBUFF 80

int main(int argc,char **argv){

	int fd,n;
	char res[MAXBUFF];

	if(mkfifo(FIFO,S_IFIFO | 0666)<0){
		printf("error\n");
		exit(-1);	
	}

	if((fd=open(FIFO,O_RDONLY))<0){
		printf("error\n");
		exit(-1);
	}
	
	while((n=read(fd,res,MAXBUFF))>0){
		write(1,res,n);
		if(!strncmp(res,"exit",4))
			break;	
	}

	close(fd);
	return 0;
}
