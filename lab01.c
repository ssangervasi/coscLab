#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char** arrConcat(char** addto, char** addition, int* tosize, int* addsize);

void removewhitespace(char* spacey)
{
	if(spacey==NULL){
		return;
	}
	int slen = strlen(spacey);
	char filler[slen];
	int i = 0;
	int j = 0;
	for(; i<slen; i++){
		if(spacey[i]!=' ' && spacey[i]!='\n' && spacey[i]!='\t'){
			filler[j]=spacey[i];
			j++;
		}
	}
	i=0;
	spacey[j]='\0';
	for(; i<j; i++){
		spacey[i]=filler[i];
	}

	return;
}

char* c2pascal(char* cstr)
{	
	int clen = strlen(cstr);
	if(cstr==NULL || clen>255){
		return NULL;
	}
	unsigned char plen = clen;
	char *pstr = malloc(sizeof(char)*(clen+1));
	pstr[0]=plen;
	int i=1;
	for(; i<=clen+1; i++){
		pstr[i]=cstr[i-1];
	}
	return pstr;
}

char* pascal2c(char* pstr)
{
	if(pstr == NULL){
		return NULL;
	}
	int stop = pstr[0]+1;
	char *cstr = malloc(sizeof(char)*stop);
	cstr[stop]='\0';
	for(; stop>0; stop--){
		cstr[stop-1]=pstr[stop];
	}
	return cstr;
}

/* 	Array Concatonation is a helper function I wrote that is used in "tokenify"  
	to make the combination of the total array and a buffer array (of strings).
*/
char** arrConcat(char** addto, char** addition, int* tosize, int* addsize)
{
	int i=0;
	int j=0;
	int totsize = (*tosize)+(*addsize)+1;
	int memsize;
	char** newarr = malloc(totsize*sizeof(char*));
	while(i<*tosize){
		memsize = strlen(addto[i])*sizeof(char);
		newarr[i] = malloc(memsize);
		newarr[i] = strdup(addto[i]);
		free(addto[i]);
		i++; 
	}	
		
	while(j<*addsize){
		memsize = strlen(addition[j])*sizeof(char);
		newarr[i] = malloc(memsize);
		newarr[i] = strdup(addition[j]);
		free(addition[j]);
		i++;
		j++;
	}
	newarr[totsize] = NULL;
	return newarr; 
}

char** tokenify(char* str)
{
	int i = 0;
	const int slen = strlen(str);
	int buffsize =7; // I'm using this variable so that you can set how big the buffer is during this process not including the concluding NULL element.
	int totalsize = 0; //Refers to the number of places in totalarray that are not the concluding NULL element. 
	
	char** totalarray = malloc(sizeof(char*));
	char** buffarray = malloc(sizeof(char*)*(buffsize+1));
	int inbuff = 0;
	
	char* begin = NULL;
	int gotill = -1;
	int fullword = 0;
	int upto = 0;

	totalarray[0] = NULL;
	buffarray[buffsize+1] = NULL;

	for(; i<=slen; i++){
		if(!isspace(str[i])){
			if(begin == NULL){
				begin = (str+i);
				gotill++;
			}
			else{
				gotill++;
			}			
		}
		else{
			if(begin != NULL){
				gotill++;
				fullword = 1;
			}
			
			if(begin != NULL && 1 == fullword){
				
				buffarray[inbuff] = malloc(sizeof(char)*(gotill));
				for(; upto<gotill; upto++){
					(buffarray[inbuff])[upto]= *(begin+upto);
				}
				(buffarray[inbuff])[upto] = '\0';
				
				inbuff++;
				gotill=-1;
				begin = NULL;
				upto = 0; 
				fullword = 0;	
			
				if(buffsize==inbuff){					
					totalarray = arrConcat(totalarray, buffarray, &totalsize, &buffsize);
					totalsize += (buffsize);
					inbuff = 0;						
					free(buffarray);	
					buffarray = malloc(sizeof(char*)*(buffsize));
					
				}
			}
			
		}
	}
	if(inbuff>0){		
		totalarray = arrConcat(totalarray, buffarray, &totalsize, &inbuff);		
	}
	free(buffarray); //I hope I have taken care of all memory leaks...
	return totalarray;
}













 
