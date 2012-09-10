#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char** arrConcat(char** addto, char** addition, int* totalsize);

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
		if(spacey[i]!=' ' && spacey[i]!='\n' & spacey[i]!='\t'){
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
char** arrConcat(char** addto, char** addition, int* totalsize)
{
	int i=0;
	int j=0;
	int memsize = 0;
	char** newarr = malloc((*totalsize+1)*sizeof(char*));
	while(addto[i] != NULL){
		memsize = strlen(addto[i])*sizeof(char);
		newarr[i] = malloc(memsize);
		//newarr[i] = strdup(addto[i]);
		newarr[i] = memcpy(newarr[i], addto[i], memsize);
		i++; 
	}		
	while(addition[j] !=NULL){
		memsize = strlen(addition[j])*sizeof(char);
		newarr[i] = malloc(memsize);
		//newarr[i] = strdup(addition[j]);
		newarr[i] = memcpy(newarr[i], addition[j], memsize);
		i++;
		j++;
	}
	//free(addto);
	newarr[i+1] = NULL;
	return newarr; 
}

char** tokenify(char* str)
{
	int i = 0;
	const int slen = strlen(str);
	const int buffsize = 8; // I'm using this variable so that you can set how big the buffer is during this process (note: this includes up to the NULL element).
	int totalsize = 0; //Refers to the number of places in totalarray that are not the concluding NULL element.
	
	char** totalarray = malloc(sizeof(char*));
	char** holder;
	char** buffarray = malloc(sizeof(char*)*buffsize);
	int inbuff = 0;
	char* tobuff = NULL;
	
	char* begin = NULL;
	int gotill = -1;
	int fullword = 0;
	int upto = 0;


	totalarray[0] = NULL;
	buffarray[buffsize] = NULL;
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
				if(buffsize-1==inbuff){
					totalsize += (buffsize-1);
					holder = arrConcat(totalarray, buffarray, &totalsize);
					printf("Did arrConcat\n");
					//free(totalarray);
					totalarray=holder;
					inbuff = 0;	
				}
				if(inbuff<buffsize-1){ //I realize this condition isn't actually necessary because this step happens every time regardless, I might edit this out later.
					free(buffarray[inbuff]);
					buffarray[inbuff] = malloc(sizeof(char)*(gotill+1));
					tobuff = malloc(sizeof(char)*(gotill+1)); /*I guess I could save some memory space by exluding tobuff completely instead of copying it into the buffer after, but I already typed it up this way...*/
					for(; upto<gotill; upto++){
						tobuff[upto] = *(begin+upto);
					}
					tobuff[upto] = '\0';
					
					printf("Words: ~%d; Begin Char:%c;  Word: %s \n", inbuff+totalsize, *begin, tobuff);
					//memcpy(buffarray[inbuff], tobuff, sizeof(char)*(upto));
					buffarray[inbuff] = strdup(tobuff);
					buffarray[inbuff+1] = NULL;
					free(tobuff);
					inbuff++;
					gotill=-1;
					begin = NULL;
					upto = 0; 
					fullword = 0;
				}
			}
			
		}
	}
	if(inbuff>0){
		totalsize += (inbuff);
		holder = arrConcat(totalarray, buffarray, &totalsize);
		printf("Did final arrConcat\n");
		//free(totalarray);
		totalarray=holder;
	}
	free(buffarray);
	return totalarray;
}













 
