int ls_command(char ** token,int f1,char * Parentdirectory)
{
	int f=1,i;
	char *curdirectory=NULL;
	curdirectory=(char *)malloc(1000*sizeof(char));
	curdirectory=getcwd(curdirectory,1000*sizeof(char));

	DIR *myDirectory;
	struct dirent *myFile;

	if(f1==1)
	{
		i=1;
		while(token[i]!=NULL)
		{
			printf("%s :\n",token[i]);
			if(strcmp(token[i],"~")==0)
			{
				strcpy(token[i],Parentdirectory);
			}
			myDirectory = opendir(token[i]);
	        if (myDirectory) 
	        {
	            while ((myFile = readdir(myDirectory)))
	            {
	            	if(myFile->d_name[0]!='.')		//All hidden files start with a dot
	            	{
	                	printf("%s\n", myFile->d_name);
	                }
	            }
	        }
	        else
	        {
	        	f=0;
	        }
			i++;
		}
	}
	else
	{
		myDirectory = opendir(curdirectory);
        if (myDirectory) 
        {
            while ((myFile = readdir(myDirectory)))
            {
            	if(myFile->d_name[0]!='.')		//All hidden files start with a dot
            	{
                	printf("%s\n", myFile->d_name);
                }
            }
        }
        else
        {
        	f=0;
        }
	}
	return f;
}
