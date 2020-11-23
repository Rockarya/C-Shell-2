void echo_command(char** str)
{
	int i=1;
	while(str[i]!=NULL)
	{
		printf("%s ",str[i]);
		i++;
	}
	printf("\n");
}