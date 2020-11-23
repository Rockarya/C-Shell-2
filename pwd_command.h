void pwd_command(char * Parentdirectory)
{
	char *Currentdirectory;
	Currentdirectory=(char *)malloc(1000*sizeof(char));
	Currentdirectory=getcwd(Currentdirectory,1000*sizeof(char));
	printf("%s\n",Currentdirectory);
}
