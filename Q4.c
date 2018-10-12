#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0,sum9=0,sum10=0,totalsum;
	int arr[1000];
	for(int i=0;i<1000;i++){
		arr[i]=i;
	}	
	int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];
	
	if (pipe(fd1)==-1)
	{
        	printf("Pipe 1 Failed" );
        	return 1;
	}

	if (pipe(fd2)==-1)
	{
        	printf("Pipe 2 Failed" );
        	return 1;
	}
	if (pipe(fd3)==-1)
	{
        	printf("Pipe 3 Failed" );
        	return 1;
	}
	if (pipe(fd4)==-1)
	{
        	printf("Pipe 4 Failed" );
        	return 1;
	}
	if (pipe(fd5)==-1)
	{
        	printf("Pipe 5 Failed" );
        	return 1;
	}
	if (pipe(fd6)==-1)
	{
        	printf("Pipe 6 Failed" );
        	return 1;
	}
	if (pipe(fd7)==-1)
	{
        	printf("Pipe 7 Failed" );
        	return 1;
	}
	if (pipe(fd8)==-1)
	{
        	printf("Pipe 8 Failed" );
        	return 1;
	}
	if (pipe(fd9)==-1)
	{
        	printf("Pipe 9 Failed" );
        	return 1;
	}
	if (pipe(fd10)==-1)
	{
        	printf("Pipe 10 Failed" );
        	return 1;
	}

	int pid1=fork();
	
	if(pid1==-1){
		printf("failed");
		return 1;	
	}
	
	if(pid1==0){
		
		for(int i=0; i<100; i++){
			sum1=sum1+arr[i];
		}
		printf("first sum: %d",sum1);
		write(fd1[1],&sum1,sizeof(sum1));
		close(fd1[1]);
	}
	else{
		
		int pid2=fork();
		if(pid2==0){
			for(int i=100; i<200; i++){
				sum2=sum2+arr[i];
			}
			printf("\nsecond sum: %d",sum2);
			write(fd2[1],&sum2,sizeof(sum2));
			close(fd2[1]);
		}
		else{
			
			int pid3=fork();
			if(pid3==0){
				for(int i=200; i<300; i++){
					sum3=sum3+arr[i];
				}
				printf("\nThird sum: %d",sum3);
				write(fd3[1],&sum3,sizeof(sum3));
				close(fd3[1]);
			}
			else{
				
				int pid4=fork();
				if(pid4==0){
					for(int i=300; i<400; i++){
					sum4=sum4+arr[i];
					}
					printf("\nfourth sum: %d",sum4);
					write(fd4[1],&sum4,sizeof(sum4));
					close(fd4[1]);
				}
				else{
					
					int pid5=fork();
					if(pid5==0){
						for(int i=400; i<500; i++){
							sum5=sum5+arr[i];
						}
						printf("\nFifth sum: %d",sum5);
						write(fd5[1],&sum5,sizeof(sum5));
						close(fd5[1]);
					}
					else{
						
						int pid6=fork();
						if(pid6==0){
							for(int i=500; i<600; i++){
								sum6=sum6+arr[i];
							}
							printf("\nSixth sum: %d",sum6);
							write(fd6[1],&sum6,sizeof(sum6));
							close(fd6[1]);
						}
						else{
							
							int pid7=fork();
							if(pid7==0){
								for(int i=600; i<700; i++){
									sum7=sum7+arr[i];
								}
								printf("\nSeventh sum: %d",sum7);
								write(fd7[1],&sum7,sizeof(sum7));
								close(fd7[1]);
							}
							else{
								
								int pid8=fork();
								if(pid8==0){
									for(int i=700; i<800; i++){
										sum8=sum8+arr[i];
									}
									printf("\nEighth sum: %d",sum8);
									write(fd8[1],&sum8,sizeof(sum8));
									close(fd8[1]);
								}
								else{
									
									int pid9=fork();
									if(pid9==0){
										for(int i=800; i<900; i++){
											sum9=sum9+arr[i];
										}
										printf("\nNinth sum: %d",sum9);
										write(fd9[1],&sum9,sizeof(sum9));
										close(fd9[1]);
									}
									else{
										
										int pid10=fork();
										if(pid10==0){
											for(int i=900; i<1000; i++){
												sum10=sum10+arr[i];
											}
											printf("\nTenth sum: %d",sum10);
											write(fd10[1],&sum10,sizeof(sum10));
											close(fd10[1]);
										}
										else{
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											read(fd1[0],&sum1,sizeof(sum1));
											totalsum+=sum1;
											close(fd1[0]);
											read(fd2[0],&sum2,sizeof(sum2));
											totalsum+=sum2;
											close(fd2[0]);
											read(fd3[0],&sum3,sizeof(sum3));
											totalsum+=sum3;
											close(fd3[0]);
											read(fd4[0],&sum4,sizeof(sum4));
											totalsum+=sum4;
											close(fd4[0]);
											read(fd5[0],&sum5,sizeof(sum5));
											totalsum+=sum5;
											close(fd5[0]);
											read(fd6[0],&sum6,sizeof(sum6));
											totalsum+=sum6;
											close(fd6[0]);
											read(fd7[0],&sum7,sizeof(sum7));
											totalsum+=sum7;
											close(fd7[0]);
											read(fd8[0],&sum8,sizeof(sum8));
											totalsum+=sum8;
											close(fd8[0]);
											read(fd9[0],&sum9,sizeof(sum9));
											totalsum+=sum9;
											close(fd9[0]);
											read(fd10[0],&sum10,sizeof(sum10));
											totalsum+=sum10;
											close(fd10[0]);
											printf("total sum: %d",totalsum);
										}
									}
								}
							}
						}
					}
				}
			}
		}	
	}



}

