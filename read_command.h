char **read_command(char str[])
{
	char *token=NULL;
	int k=0,i,p,j;

   	/* get the first token */
    token = strtok(str,";");
	char **s=NULL;
	s=(char **)malloc(100*sizeof(char));
	while( token != NULL ) 
	{
		s[k]=(char*)malloc(1000);
		char string[10000]={"\0"};
		strcpy(string,token);
		i=0;
		j=strlen(string)-1;
	  	while(string[i]==32 || string[i]==9 || string[i]==10)		//to check for spacebar/tab/new line
	  	{
	  		i++;
	  	}
	  	while(string[j]==32 || string[j]==9 || string[j]==10)
	  	{
	  		j--;
	  	}
	  	for(p=i;p<=j;p++)
	  	{
	  		s[k][p-i]=string[p];
	  	}
	  	if(j<i)
	  	{
	  		s[k]=NULL;
	  	}
		k++;
	  	token = strtok(NULL,";");
	}
	s[k]=NULL;		
 	return s;
}
