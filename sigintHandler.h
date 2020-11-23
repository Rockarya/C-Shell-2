void sigintHandler(int sig_num) 
{ 
	signal(SIGINT,sigintHandler);
	if(flag==0)
	{
		kill(fpid,SIGINT);
	}
} 