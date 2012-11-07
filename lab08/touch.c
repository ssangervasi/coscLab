#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){
	int fdescriptor = creat((const char*) argv[argc-1], S_IRWXU);
	if (fdescriptor > -1){
		close(fdescriptor);
		return 0;
	}
	else{
		return -1;
	}

}
