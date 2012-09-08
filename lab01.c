#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
	char pstr[clen+1];
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
	char* cstr[stop];
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
	/*int maxstr=0;
	while(addto[i]!=NULL || addition[i]!=NULL){
		if(addto[i]!=NULL && strlen(addto[i])>maxstr)
	}*/
	newarr = malloc((totalsize+1)*sizeof(char*));
	while(addto[i] != NULL){
		memsize = strlen(addto[i])*sizeof(char);
		newarr[i] = malloc(memsize);
		newarr[i] = memcopy(newarr[i], addto[i], memsize);
		i++; 
	}		
	while(addition[j]!=NULL){
		memsize = strlen(addition[j])*sizeof(char);
		newarr[i] = malloc(memsize);
		newarr[i] = memcopy(newarr[i], addition[j], memsize);
		i++;
		j++;
	}
	newarr[i+1] = NULL;
	return newarr; 
}

char** tokenify(char* str)
{
	int i = 0;
	const int slen = strlen(str);
	const int buffsize = 6; // I'm using this variable so that you can set how big the buffer is during this process (note: this includes up to the NULL element).
	int totalsize = 0; //Refers to the number of places in totalarry that are not the concluding NULL element.
	
	char** totalarray = malloc(sizeof(char*));
	char** holder;
	char** buffarray = malloc(sizeof(char*)*buffsize);
	int inbuff = 0;
	char* tobuff = NULL;
	
	char* begin = NULL;
	int gotill = -1;
	int upto = 0;

	totalarry[0] = buffarray[0] = buffaray[buffsize] = NULL;
	for(; i<slen; i++){
		if(isspace(str[i]) != 0){
			if(gotill != -1){
				begin = str[i];
				gotill++;
			}
			else{
				gotill++;
			}			
		}
		else{
			if(begin != NULL){
				if(buffsize==inbuff){
					totalsize += (buffsize-1);
					holder = arrConcat(totalarray, buff, totalsize);
					free(totalarray);
					totalarray=holder;
					inbuff = 0;	
				}
				if(inbuff<buffsize){ //I realize this condition isn't actually necessary because this step every time regardless, I might edit this out later.
					buffarray[inbuff] = malloc(sizeof(char)*(gotill+1));
					tobuff = malloc(sizeof(char)*(gotill+1)); /*I guess I could save some memory space by exluding tobuff completely instead of copying it into the buffer after, but I already typed it up this way...*/
					for(; upto<gotill; upto++){
						tobuff[upto] = begin+upto;
					}
					tobuff[upto] = '\0';
					memcopy(buffarray[inbuff], tobuff, sizeof(char)*(upto));
					free(tobuff);
					inbuff++;
					gotill=-1;
					begin = NULL;
					upto = 0; 
				}
			}
			
		}
	}

}













 
