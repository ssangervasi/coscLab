#include <stdio.h>
#include <string.h>

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

char* pascalstr(char* cstr)
{	
	int clen = strlen(cstr);
	if(clen>255){
		return NULL;
	}
	unsigned char plen = clen;
	char pstr[clen=1];
	plen[0]=clen;
	int i=1;
	for(; i<=plen; i++){
		pstr[i]=cstr[i-1];
	}
}
