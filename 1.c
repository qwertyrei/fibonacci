#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

int first=1;							//указываем переменные перед функциями, а не в main, иначе их не будет видно и на экране будет отображаться ерунда
int second=1;
int sum=1;
int i=1;
int j=-1;

void sig_handler(int signum){					//sigusr1
	printf("\n Poslediy element:\t %d \n",second);
}

void sigfun(int signum){					//ctrl+c
        printf("\n You have presses Ctrl-C");
	printf("\n Vsego elementov:\t %d \n",i);
	printf("\n Skolko sgenerirovano:\t %d \n",j);
	pid_t pid;
  	pid=getpid();						//Process ID of itself
  	signal(SIGUSR1,sig_handler);				//sigusr1
  	kill(pid,SIGUSR1);					//send SIGUSR1 to itself
	exit(1);						//завершаем программу
}

int main(int argc, char *argv[]){
	while(1){
		j=j+1;
		i=i+1;						//how many elements
		(void)signal(SIGINT, sigfun);			//ctrl+c
		usleep(500000);					//полсекунды
		int a;
		a=first;
		sum=second+first;				//fibonacci
		first=second;
		second=sum;
	}
	return 0;
}
