char ** history(char ** string,char * s)
{
	int i;
	i=0;
	while(string[i]!=NULL)
	{
		i++;
	}
	if(i<20)
	{
		string[i]=(char *)malloc(100*sizeof(char));
		strcat(string[i],s);
	}
	else
	{
		for(i=1;i<=19;i++)
		{
			strcpy(string[i-1],string[i]);
		}
		strcpy(string[19],s);
	}
	return string;
}