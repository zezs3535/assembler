#include "myas.h"

int is_valid(char *op, char *args)
{
	//if valid return 1, else 0
	int i=0;
	char c=0;
	int a=0,b=0;
	int j=0;
	char *tok1, *tok2;
	tok1=strtok(args,",");
	do{
		c=tok1[i];
		i++;
	}while(c!='\0');
	tok2=strtok(args+i,",");
	a=what_ins(tok1);
	b=what_ins(tok2);
	if((a==3||a==4)&&(b==3||b==4)){ //mem to mem
		return 0;
	}
	if(b==2){ //dest!=immediate
		return 0;
	}
	return 1;
}
