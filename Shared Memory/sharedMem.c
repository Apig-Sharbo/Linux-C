#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(){
	int *array;
	int shmid;
	int mmm=1;
	char ss[]="sharedMem.c";
	key_t key;
	if((key=ftok(ss,0))<0){
		printf("can not create key\n");
		exit(-1);
	}
	
	if((shmid=shmget(key,3*sizeof(int),IPC_CREAT | IPC_EXCL | 0642))<0){
		if(errno!=EEXIST){
			printf("can not create shared memory\n");
			exit(-1);
		}
		else{
			if((shmid=shmget(key,3*sizeof(int),0))<0){
				printf("can not find shared memory\n");
				exit(-1);
			}
			mmm=0;
		}
	}
	
	if((array=(int *)shmat(shmid,NULL,0))==(int *)(-1)){
		printf("can not attach shared memory\n");
		exit(-1);
	}

	if(mmm){
		array[0]=0;
		array[1]=0;
		array[2]=0;
	}
	else{
		array[0]+=1;
		array[2]+=1;
	}
	
	printf("array0=%d, array1=%d, array2=%d\n",array[0],array[1],array[2]);

	if(shmdt(array)<0){
		printf("can not detach shared memory\n");
		exit(-1);
	}
	return 0;

}
