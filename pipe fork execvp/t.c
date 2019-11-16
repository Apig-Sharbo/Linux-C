#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	
    pid_t pids[10]; // declaration of an array of pids( processor ID)
    int i;
    int n = 10;

    /* Start children. */
    for (i = 0; i < 3; ++i) {
      if ((pids[i] = fork()) < 0) {   // if fork() returns a -ve number, creation of child process failed
        perror("fork");                 // displaying error
        abort();
      } else if (pids[i] == 0) {        // If child process was created successfully
        char *arr1[] = {argv[0], argv[1],argv[2],argv[3], NULL};
        char *arr2[] = {argv[0], argv[1],argv[2],argv[4], NULL};
        char *arr3[] = {argv[0], argv[1],argv[2],argv[5], NULL}; 
        switch(i){
            case 0:
                execvp("ping", arr1);
            case 1:
                execvp("ping", arr2);
            case 2:
                execvp("ping", arr3);
        }
        exit(0);
      }
    }

	return 0;
}
