#include "myas.h"
#include<string.h>

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax
        char x[30],y[30],z[30];
	char *s;
	int i,n,j;
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");
        for( i=0;i<strlen(args);i++)
 	{
 	    if(args[i]==',')
		break;
  	    x[i]=args[i];
 	}
	++i;
        for(j=i;j<strlen(args)-i;j++)
	{
		y[j-i]=args[j];
	}
	char *r=strstr(x,"0x");
	if(r!=NULL)
		s=strstr(r,"(%");	
        if(x[0]=='%'&&y[0]=='%')
         {
		strcpy(mcode, "1000 10001");
	 }
	else if((x[0]=='('&&y[0]=='%')||(x[0]=='%'&&y[0]=='('))
	{
	 	strcpy(mcode, "1000 1011");
	}
	else if(s!=NULL&&y[0]=='%')
	{
		strcpy(mcode, "1000 1011");
	}
	else if(x[0]=='0'&&x[1]=='x'&&strcmp(y,"%eax")==0)
	{
		strcpy(mcode, "1010 0001");
	}
	else if(strcmp(x,"%eax")==0&&y[1]=='x'&&y[0]=='0')
	{
		strcpy(mcode, "1010 0011");
	}
	else if(x[0]=='$'&&y[0]=='%')
	{
		if(strcmp(y,"%eax")==0)
		  strcpy(mcode, "1011 1000");
		else if(strcmp(y,"%ecx")==0)
		  strcpy(mcode, "1011 1001");
		else if(strcmp(y,"%edx")==0)
		 strcpy(mcode, "1011 1010");
		else if(strcmp(y,"%ebx")==0)
		 strcpy(mcode, "1011 1011");
		else if(strcmp(y,"%esp")==0)
		 strcpy(mcode, "1011 1100");
		else if(strcmp(y,"%ebp")==0)
		 strcpy(mcode, "1011 1101");
		else if(strcmp(y,"%esi")==0)
		 strcpy(mcode, "1011 1110");
		else if(strcmp(y,"%edi")==0)
		 strcpy(mcode, "1011 1111");
		else
		 strcpy(mcode,"error");
	}
	/********************************/
    /*  							*/
	/*    generate machine code     */
    /*  							*/
	/********************************/
	
	return 1;	
}
