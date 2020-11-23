void sigtstpHandler(int sig_numb)
{
	signal(SIGTSTP,sigtstpHandler);
	if(flag==0)
	{
		kill(fpid,SIGTSTP);
	}
}