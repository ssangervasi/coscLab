#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv){
	DIR* location = opendir((const char*) argv[argc-1]);
	struct dirent* locinfo = readdir(location);
	printf("Name\t| Type\t| Size\n");
	char type = ' ';
	struct stat * locstat= malloc(sizeof(struct stat));
	for(;locinfo!=NULL; locinfo = readdir(location)){
		printf("%s\t| ",locinfo->d_name);
		type = locinfo->d_type;
		if(type == DT_DIR){
			printf("dir\n");
		}
		else{
			stat((const char*) locinfo->d_name, locstat);
			printf("file\t| %d\n", (int)(locstat->st_size));
		}
		
	}
	free(locstat);
	closedir(location);
	
	return 0;
}
