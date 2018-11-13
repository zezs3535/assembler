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
	else{
		return 0;
	}
}

int instr_trans(char *op, char *args, char* mcode)
{
	int i=0;	
	int a=0,b=0;
	char c=0;
	char *arg1,*arg2;
	char *tmp=(char*)malloc(sizeof(char)*20);

	strcpy(tmp,args);
	// check syntax 
	if(!is_valid(op, args)){
		strcpy(mcode,"error");
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	arg1=strtok(tmp,",");
	do{
		c=arg1[i];
		i++;
	}while(c!='\0');
	arg2=strtok(tmp+i,",");
	a=what_ins(arg1);
	b=what_ins(arg2);
	c=arg2[2];
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
				default:
					return 0;
			}
		}
		else if(a==3){
			strcpy(mcode,"8b");
		}
		else if(a==4){
			strcpy(mcode,"a1");
		}
		
		
	}
	else
		return 0;
	return 1;	
}
