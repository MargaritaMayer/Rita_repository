#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 5
#define NULL_PTHREAD 0

pthread_t arr[N]; 

void* thread_work(void *arg){
	pthread_t id=pthread_self();
	int i = 0;
	for(i; i < N; i++){
		if(pthread_equal(id,arr[i])){
			printf("Thread N = %d is working now\n",i);
			break;
		}
	}
}


int main(){
	int i = 0;	
	
//	for(i; i < N; i++){
//		pthread_create(&(arr[i]),NULL,&thread_work,NULL);//We should first of all create new thread and then save its id into array
//		printf("Thread N = %d is created\n",i);
//	}
//	sleep(0.5);//
//The result is different every time you run it.

	for(i;i<N;i++){
		pthread_create(&(arr[i]),NULL,&thread_work,NULL);//We should first of all create new thread and then save its id into array
		printf("Thread N = %d is created\n",i);
		
		pthread_join(arr[i],NULL);//This line provides the same result every time the program is run
								  //It tells you to wait until the previous thread finishes working
		
		arr[i]=NULL_PTHREAD;//We used this thread and don't want to access it anymore
	}
	
	return 0;
}


