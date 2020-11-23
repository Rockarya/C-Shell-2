#include "ls_a_l_command.h"
#include "ls_l_command.h"
#include "ls_a_command.h"
#include "ls_command.h"

int ls(char ** temp,char * Parentdirectory)
{
	int i,f1,f2,f3,f=1;
	f1=0;		// if directory name is given
	f2=0;		//if -l flag is applied
	f3=0; 		// if -a flag is applied

	i=1;
	while(temp[i]!=NULL)
	{
		if(strcmp(temp[i],"-l")==0)
		{
			f2=1;
		}
		if(strcmp(temp[i],"-a")==0)
		{
			f3=1;
		}
		if(strcmp(temp[i],"-l")!=0 && strcmp(temp[i],"-a")!=0 && strcmp(temp[i],"-la")!=0 && strcmp(temp[i],"-al")!=0)
		{
			f1=1;
		}
		if(strcmp(temp[i],"-la")==0 || strcmp(temp[i],"-al")==0)
		{
			f2=1;
			f3=1;
		}
		i++;
	}

	if(f2==1 && f3==1)
	{
		f=ls_a_l_command(temp,f1,Parentdirectory);
	}
	else if(f2==1)
	{
		f=ls_l_command(temp,f1,Parentdirectory);
	}
	else if(f3==1)
	{
		f=ls_a_command(temp,f1,Parentdirectory);
	}
	else
	{
		f=ls_command(temp,f1,Parentdirectory);
	}
	return f;
}
