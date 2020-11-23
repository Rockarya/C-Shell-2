//IMPORTANT:- If jobs shows only previous procesess then again run the command.If u get correct process on some command then press 1 time enter afterwards and run
//keep doing it,and do not create a killed process again in the shell.:-Not working
void kjob(char ** str,int * npid)
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

	int val,jnum;
	pid_t pid;
	jnum=atoi(str[1]);
	val=atoi(str[2]);
	pid=store_pid[jnum-1];
	if(pid>0)
	{
		if(kill(pid,val)==0)
		{
			if(kill(pid,val)==-1)
			{
				printf("Error running the command\n");
			}
		}
		else
		{
			printf("Error running the command\n");
		}
	}
	else
	{
		printf("Error running the command\n");
	}
}