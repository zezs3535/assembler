#include "myas.h"

int what_ins(char *ptr){
	
	if(ptr[0]=='%'){ //register
		return 1;
	}
	else if(ptr[0]=='$'){ //immediate
		return 2;
	}
	else if(ptr[0]=='-'){ //memory with disp.
		return 3;
	}
	else if(ptr[0]=='0'){ //memory
		return 4;
	}

}

int instr_trans(char *op, char *args, char* mcode)
{
	
	int j=0;
	int a,b;
	char c;
	char *tok1,*tok2;
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	
	tok1=strtok(args,",");
	tok2=strtok(NULL,",");
	a=what_ins(tok1);
	b=what_ins(tok2);
	c=tok2[2];
	if(b==1){
		if(a==1){
			strcpy(mcode,"89");
		}
		else if(a==2){
			switch(c){
				case'a':strcpy(mcode,"b8");
					break;
				case'b':strcpy(mcode,"bb");
					break;
				case'c':strcpy(mcode,"b9");
					break;
				case'd':strcpy(mcode,"ba");
					break;
			}
		}
		else if(a==3){
			strcpy(mcode,"8b");
		}
		else if(a==4){
			strcpy(mcode,"a1");
		}
	}
	return 1;	
}
