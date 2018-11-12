#include "myas.h"

int what_ins(char *ptr){
	int i=0;
	
	if(ptr[0]=='%'){ //register
		return 1;
	}
	else if(ptr[0]=='$'){ //immediate
		return 2;
	}
	else if(ptr[0]=='-'){ //memory
		return 3;
	}
	else if(ptr[0]=='0'){ //memory with disp.
		return 4;
	}

}

int instr_trans(char *op, char *args, char* mcode)
{
	char i;
	int j=0;
	int a,b;
	char *tok1,*tok2;
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	
	tok1=strtok(args,",");
	while(i!='\0'){
		i=tok1[j];
		j++;
	}
	tok2=strtok(args+j,",");
	a=what_ins(tok1);
	b=what_ins(tok2);
	strcpy(mcode, "AB CD EF");


	
	return 1;	
}
