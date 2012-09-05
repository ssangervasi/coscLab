#include <lab01.h>

void rmwhite(char* spacey)
{
	if(spacey==NULL){
		return NULL;
	}
	int slen = strlen(spacey);
	char *filler[slen];
	int i = 0;
	int j = 0;
	for(; i<slen; i++){
		if(spacey[i]!=' ' && spacey[i]!='\n' & spacey[i]!='\t'){
			filler[j]=spacey[i];
			j++;
		}
	}
}


/*
void rmwhite(char* spacey)
{
	if(spacey==NULL){
		return NULL;
	}
	int slen = strlen(spacey);
	int fillfrom = -1;
	int fillto = -1;
	int starting = 1;
	char *fillwith[slen];
	int i=0;
	int j=0;
	for(; inti<slen; i++){
		if(spacey[i]==' ' || spacey[i]=='\n' || spacey[i]=='\t'){
			fillfrom=fillto=-1;
			starting = 0;
					
			
		}
		else if(starting == 0){
			if(fillfrom==-1){
				fillfrom = i;
		}
		
			
		
	}
	
} */
