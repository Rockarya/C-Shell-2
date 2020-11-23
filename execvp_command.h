void execvp_command(char ** token)
{
	char *cmd=NULL;
	cmd=(char *)malloc(1000*sizeof(char));
	strcpy(cmd,token[0]);
	execvp(cmd,token);
}
