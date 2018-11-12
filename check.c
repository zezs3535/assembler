#include "myas.h"

int is_valid(char *op, char *args)
{
	//if valid return 1, else 0

	char i;
	int j=0;
	char *tok1, *tok2;
	tok1=strtok(args,",");
	while(i!='\0'){
		i=tok1[j];
		j++;
	}
	tok2=strtok(args+j,",");
	a=what_ins(tok1);
	b=what_ins(tok2);
	if((a==3||a==4)&&(b==3||b==4)){
		return 0;
	}
	if(b==2){
		return 0;
	}
	return 1;
}
