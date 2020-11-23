int cd_command(char ** str,char * Parentdirectory)
{
	int i,pos;
	char *curdirectory=NULL,*temp=NULL;
	curdirectory=(char *)malloc(1000*sizeof(char));
	temp=(char *)malloc(1000*sizeof(char));
	curdirectory=getcwd(curdirectory,1000*sizeof(char));

	if(str[1]==NULL || strcmp(str[1],"~")==0)
	{
		return chdir(Parentdirectory);
	}
	else
	{
		if(strcmp(str[1],"-")==0)
		{
			strcpy(temp,last_working_directory);
			last_working_directory=getcwd(last_working_directory,1000*sizeof(char));
			printf("%s\n",temp);
			return chdir(temp);
		}
		else if(strcmp(Parentdirectory,curdirectory)==0 && strcmp(str[1],"..")==0)
		{
			printf("%s\n",curdirectory);
			return 0;
		}
		else
		{
			return chdir(str[1]);
		}
	}
}
