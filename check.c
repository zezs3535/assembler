#include "myas.h"

int is_valid(char *op, char *args)
{
	//if valid return 1, else 0

	int a,b;
	int j=0;
	char *tok1, *tok2;
	tok1=strtok(args,",");
	tok2=strtok(NULL,",");
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
