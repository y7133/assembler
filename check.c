#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");
	char x[30]={"\0"},y[30]={"\0"};
	int i,j,n=0;
	//char *r={"\0"},*p={"\0"},*q={"\0"},*s={"\0"};
	for(i=0;i<strlen(args);i++)
	{
		if(args[i]==',')
		 break;
		x[i]=args[i];
	}
	i++;
	for(j=i;j<strlen(args);j++)
	{
		y[j-i]=args[j];
	}
	
	if((x[0]=='('&&y[0]=='(')||(x[0]=='('&&y[0]=='0')||(x[0]=='('&&y[0]=='-'&&y[strlen(y)-1]==')'))
		n++;
	else if((x[0]=='-'&&x[strlen(x)-1]==')'&&y[0]=='(')||(x[0]=='-'&&x[strlen(x)-1]==')'&&y[0]=='0')||(x[0]=='-'&&x[strlen(x)-1]==')'&&y[0]=='-'&&y[strlen(y)-1]==')'))
		n++;
	else if((x[0]=='0'&&x[1]=='x'&&y[0]=='(')||(x[0]=='0'&&x[1]=='x'&&y[0]=='0')||(x[0]=='0'&&x[1]=='x'&&y[0]=='-'&&y[strlen(y)-1]==')'))
		n++;
	else if(x[0]=='$'&&y[0]=='$')
		n++;
	/********************************/
    /*  							*/
	/*         syntax check         */
    /*  							*/
	/********************************/
	if(n>0)
	  return 0;
	else
	return 1;
}
