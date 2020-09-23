#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NULL_PTHREAD 0
#define MAX 100000

int buf=0;

pthread_t thr_producer,thr_consumer;

void* producer(void *arg){
	int i = 0;
	while(1){
		while(buf==MAX);//Buffer should be full
		
		if(buf<MAX){//Make product
			i = i + 1;
			buf = buf + 1;
		}
		
		if(i%1000==0){
			printf("producer N = %d ",i);//Output number of made product and the size of buffer
			printf("%d\n", buf);//Output number of made product and the size of buffer
		}
			
	}
}

void* consumer(void *arg){
	int i = 0;
	while(1){
		while(buf==0);//Buffer should be empty
		
		if(buf>0){
			i = i + 1;
			buf = buf - 1;
		}
		
		if(i%1000==0){
			printf("consumer N = %d ",i);//Output number
			printf("%d\n", buf);//The size of buffer
		}
			
	}
}

int main(){
	pthread_create(&thr_producer,NULL,&producer,NULL);
	pthread_create(&thr_consumer,NULL,&consumer,NULL);
	pthread_join(thr_producer,NULL);
	return 0;
}

