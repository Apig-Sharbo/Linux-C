#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	
	char *c[]={"/bin/cat","hello.txt","z.c",NULL};
	char *c1[]={"cat","hello.txt","z.c",NULL};
	//execv("/bin/cat",c);
	execvp("cat",c1);
	printf("Students\n");
	return 0;
}
