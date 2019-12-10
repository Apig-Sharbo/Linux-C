#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int a[10];
pthread_mutex_t dd=PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_init(&dd,null);

void *mythread1(void * arg){
	int i;
	//pthread_mutex_lock(&dd);
	for(i=0;i<10;i++){
		a[i]=i;
		printf("arg0 = %d\n",a[i]);
        // here we will wait 2s
		sleep(2);
	}

	//pthread_mutex_unlock(&dd);
	return NULL;

}


void *mythread2(void * arg){
	int i;
	//pthread_mutex_lock(&dd);
	for(i=0;i<10;i++){
		a[i]=i*100;
		printf("arg0 = %d\n",a[i]);
		sleep(1);
	}

	//pthread_mutex_unlock(&dd);	
	return NULL;
}
int main(){
	pthread_t p1,p2;
	int k=5;
	
	//thread1 is created and starts working
	pthread_create(&p1,NULL,mythread1,NULL);

	//thread2 is created and is working alongside with thread1
	pthread_create(&p2,NULL,mythread2,NULL);

	// join is to make the main process wait for thread completion before process termination, NULL is what you expect thread to return.
	// It is ,i think,different from the return NULL which is mandatory and can't be changed in the body of the thread. 
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	return 0;
}
