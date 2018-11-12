#include "myas.h"
#include<string.h>
int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");
	char x[30],y[30];
	char *r,*s,*p,*q;
	int i,j;
	for(i=0;i<strlen(args);i++)
	{
		if(args[i]==',')
		 break;
		x[i]=args[i];
	}
	i++;
	for(j=i;j<strlen(args)-i;j++)
	{
		y[j-i]=args[j];
	}
	r=strstr(y,"0x");
	if(r!=NULL)
	 s=strstr(r,"(%");
	p=strstr(x,"0x");
	if(p!=NULL)
	 q=strstr(x,"(%");
	if(x[0]=='('&&(y[0]=='('||r!=NULL||s!=NULL))
		return 0;
	else if(q!=NULL&&(y[0]=='('||r!=NULL||s!=NULL))
		return 0;
	else if(x[0]=='0'&&x[1]=='x'&&(y[0]=='('||r!=NULL||s!=NULL))
		return 0;
	else if(x[0]=='$'&&y[0]=='$')
		return 0;
	/********************************/
    /*  							*/
	/*         syntax check         */
    /*  							*/
	/********************************/
	
	return 1;
}
