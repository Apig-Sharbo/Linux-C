#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO "fifo.l"
#define MAXBUFF 80

int main(){
	
	int fd,n;
	char res[MAXBUFF];

	if((fd=open(FIFO,O_WRONLY))<0){
		printf("error\n");
		exit(-1);
	}

	while(1){
		fgets(res,MAXBUFF,stdin);
		n=strlen(res)+1;
		write(fd,res,n);
		if(!strncmp(res,"exit",4))
			break;
	}

	close(fd);

	if(unlink(FIFO)<0){
		printf("error\n");
		exit(-1);	
	}
	return 0;
}
