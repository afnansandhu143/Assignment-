#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

int ChunkSize=100;
int arr[1000];
void * Add(void *arg){
	int sum=0;	
	int start= (int)arg;
	int end = start+ChunkSize;
	for(int i=start;i<end;i++){
		sum+=arr[i];
	}
	return ((void*)sum);
}

int main(){
	int TotalSum=0;
	for(int i=0;i<1000;i++){
		arr[i]=i;
	}
	pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
	
	pthread_create(&t1,NULL,Add,(void*)(0*ChunkSize));
	pthread_create(&t2,NULL,Add,(void*)(1*ChunkSize));
	pthread_create(&t3,NULL,Add,(void*)(2*ChunkSize));
	pthread_create(&t4,NULL,Add,(void*)(3*ChunkSize));
	pthread_create(&t5,NULL,Add,(void*)(4*ChunkSize));
	pthread_create(&t6,NULL,Add,(void*)(5*ChunkSize));
	pthread_create(&t7,NULL,Add,(void*)(6*ChunkSize));
	pthread_create(&t8,NULL,Add,(void*)(7*ChunkSize));
	pthread_create(&t9,NULL,Add,(void*)(8*ChunkSize));
	pthread_create(&t10,NULL,Add,(void*)(9*ChunkSize));	
	
	pthread_join(t1,(void**)&s1);
	pthread_join(t2,(void**)&s2);
	pthread_join(t3,(void**)&s3);
	pthread_join(t4,(void**)&s4);
	pthread_join(t5,(void**)&s5);
	pthread_join(t6,(void**)&s6);
	pthread_join(t7,(void**)&s7);
	pthread_join(t8,(void**)&s8);
	pthread_join(t9,(void**)&s9);
	pthread_join(t10,(void**)&s10);

	TotalSum=s1+s2+s3+s4+s5+s6+s7+s8+s9+s10;
	printf("Total Sum: %d",TotalSum);
	return 0;
}
