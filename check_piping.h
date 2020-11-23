int check_piping(char ** str)
{
	int f=0,i;
	i=0;
	while(str[i]!=NULL)
	{
		if(strcmp(str[i],"|")==0)
		{
			f=1;
			break;
		}
		i++;
	}
	return f;
}