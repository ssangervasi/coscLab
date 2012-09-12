#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv)
{
	char *cmd[] = { "/bin/ps", "-ef", NULL };
	
	pid_t findchild = fork();
	if(findchild == 0){
		if (execv(cmd[0], cmd) < 0) {
			fprintf(stderr, "execv failed: %s\n", strerror(errno));
		}
	}
	else{
		int* whatever;
		waitpid(findchild, whatever, 0);
		printf("No worries, I'm the parent. %d\n", *whatever);
	}
	return 0;
}

