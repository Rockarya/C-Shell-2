void overkill(int * npid)
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

	for(i=0;store_pid[i]!=0;i++)
	{
		kill(store_pid[i],9);
	}
}