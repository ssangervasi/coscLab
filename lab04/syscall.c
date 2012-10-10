/* Measurign the cost time of a system call
*/

#include <stdio.h>
#define __USE_BSD
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv){
	struct timeval begin, end, diff;
	struct timeval dtotal;
	int loops = 10;
	dtotal.tv_sec = 0;
	dtotal.tv_usec = 0;
	//Getting our base time to subtract:
	int i = 0;
	for(; i<loops; i++){
		gettimeofday(&begin, NULL);
		gettimeofday(&end, NULL);
		timersub(&end, &begin, &diff); 
		timeradd(&diff, &dtotal, &dtotal);
		
	}
	long long gtime = dtotal.tv_sec*(1000000) + dtotal.tv_usec;
	gtime *= 1000;
	gtime /=loops;

	//printf("gtime: %lld\n", gtime);
	dtotal.tv_sec = 0;
	dtotal.tv_usec = 0;
	//Doing it for fork():
	i = 0;
	pid_t PID = 0;
	for(; i<loops; i++){
		gettimeofday(&begin, NULL);
		//Now we just sandwich a call:
		PID = fork();
		gettimeofday(&end, NULL);
		timersub(&end, &begin, &diff);
		if(PID <1){
			exit(0);
		}
		
		wait();
		
		//timersub(&end, &begin, &diff); 
		printf("forktime: %ld -- %ld\n",diff.tv_sec, diff.tv_usec);
		timeradd(&diff, &dtotal, &dtotal);
		
	}
	
	long long forktime = dtotal.tv_sec*(1000000) + dtotal.tv_usec;
	
	forktime *= 1000;
	forktime /= loops; 
	printf("forktime: %ld -- %ld -- %lld\n",dtotal.tv_sec, dtotal.tv_usec, forktime);

	dtotal.tv_sec = 0;
	dtotal.tv_usec = 0;
	//Doing it for gethostname()
	char* name = malloc(sizeof(char));
	size_t len = sizeof(char);
	i= 0;
	for(; i<loops; i++){
		gettimeofday(&begin, NULL);
		gethostname(name, len);
		gettimeofday(&end, NULL);
		timersub(&end, &begin, &diff); 
		timeradd(&diff, &dtotal, &dtotal);
		
	}
	free(name);
	long long hosttime = dtotal.tv_sec*(1000000) + dtotal.tv_usec;
	hosttime *= 1000;
	hosttime /= loops;
	hosttime -= gtime; 
	
	


	printf("System Call: gettimeofday()\t Time to Execute: %lld\n", gtime);
	printf("System Call: fork()\t Time to Execute: %lld\n", forktime);
	printf("System Call: gethostname()\t Time to Execute: %lld\n", hosttime);

	return 0;
} 

