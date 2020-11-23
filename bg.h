void bg(int * npid, char ** str)
{
	//getting updated array
	int i,k,j;
	pid_t store_pid[10000]={0};
	i=0;
	k=0;
	for(i=0;i<10000;i++)
	{
		if(kill(npid[i],0)==0)
		{
			store_pid[k]=npid[i];
			k++;
		}
	}

	int j_num;
	pid_t pid;
	j_num=atoi(str[1]);
	pid=store_pid[j_num-1];
	if(pid>0)
	{
		if(kill(pid,SIGCONT)==-1)
		{
			printf("Not able to take bg process with job number=%d to fg\n",j_num);
		}
	}
	else
	{
		printf("Error running the command\n");
	}
}