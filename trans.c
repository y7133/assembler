#include "myas.h"
int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax
        char x[30]={"\0"},y[30]={"\0"},z[30]={"\0"};
	char *s=(char*)malloc(sizeof(char)*30);
	int i,n,j;
	/*if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}*/
	strcpy(mcode, "AB CD EF");
        for( i=0;i<strlen(args);i++)
 	{
 	    if(args[i]==',')
		break;
  	    x[i]=args[i];
 	}
	++i;
	//printf("%c  ",args[i]);
        for(j=i;j<strlen(args);j++)
	{
		y[j-i]=args[j];
	}
	//printf("%c  ",y[j]);
	//printf("x:%s i:%d  y:%s\n",x,i,y);
	if(!is_valid(op,args)){
		printf("Error:%s %s is not valid\n",op,args);
		return 0;
	}
	char *r=strstr(x,"0x");
	if(r!=NULL)
		s=strstr(r,"(%");	
        if(x[0]=='%'&&y[0]=='%')
         {
		strcpy(mcode, "89");
	 }
	else if((x[0]=='('&&y[0]=='%')||(x[0]=='%'&&y[0]=='('))
	{
	 	strcpy(mcode, "8b");
	}
	else if(r!=NULL&&x[0]=='0'&&y[0]=='%')
	{
		strcpy(mcode, "8b");
	}
	else if(s!=NULL&&y[0]=='%')
	{
		strcpy(mcode,"8b");
	}
	else if(x[0]=='0'&&x[1]=='x'&&strcmp(y,"%eax")==0)
	{
		strcpy(mcode, "a1");
	}
	else if(strcmp(x,"%eax")==0&&y[1]=='x'&&y[0]=='0')
	{
		strcpy(mcode, "a3");
	}
	else if(x[0]=='$'&&y[0]=='%')
	{
		if(strcmp(y,"%eax")==0)
		  strcpy(mcode, "b8");
		else if(strcmp(y,"%ecx")==0)
		  strcpy(mcode, "b9");
		else if(strcmp(y,"%edx")==0)
		 strcpy(mcode, "ba");
		else if(strcmp(y,"%ebx")==0)
		 strcpy(mcode, "bb");
		else if(strcmp(y,"%esp")==0)
		 strcpy(mcode, "bc");
		else if(strcmp(y,"%ebp")==0)
		 strcpy(mcode, "bd");
		else if(strcmp(y,"%esi")==0)
		 strcpy(mcode, "be");
		else if(strcmp(y,"%edi")==0)
		 strcpy(mcode, "bf");
		
	}
	/********************************/
    /*  							*/
	/*    generate machine code     */
    /*  							*/
	/********************************/
	
	return 1;	
}
