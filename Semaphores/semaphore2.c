#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int id;
	key_t my_key;
	struct sembuf buf;
	my_key = ftok("semaphore1.c",0);
	if(my_key<0){
		printf("can not create key\n");
		exit(-1);
	}

	if((id = semget(my_key, 1, IPC_CREAT | 0644)) < 0){
		printf("can not recieve description\n");
		exit(-1);
	}
	
	printf("second process has started.\n");

	buf.sem_op = 2;
	buf.sem_num = 0;
	buf.sem_flg = 0;
	
	if(semop(id, &buf, 1) < 0){
		printf("can not wait\n");
		exit(-1);
	}

	int k = 0;
	for( k = 0; k<10; k++)
		printf("%d\n", k);

	printf("exit from second process\n");
	return 0;
}
