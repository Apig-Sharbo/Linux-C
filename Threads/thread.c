#include <stdio.h>
#include <pthread.h>
void *mythread1(void * arg){
	int i;
	printf("mythread1 arg = %d\n",arg);
	//here we will wait 2s
	sleep(2);
	return NULL;
}

void *mythread2(void * arg){
	//here we will wait 4s
	sleep(4);
	printf("mythread2 arg = %s\n",arg);
	return NULL;
}
int main(){
	pthread_t p1,p2;
	int k=5;
	
	//thread1 is created and starts working
	pthread_create(&p1,NULL,mythread1,(int*)k);

	//thread2 is created and is working alongside with thread1
	pthread_create(&p2,NULL,mythread2,"Hello students!");

	// join is to make the main process wait for thread completion before process termination, NULL is what you expect thread to return.
	// It is ,i think,different from the return NULL which is mandatory and can't be changed in the body of the thread. 
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	return 0;
}
