void jobs(int * npid,char ** nstr)
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

	i=0;
	while(store_pid[i]!=0)
	{
		char *filename=NULL,*buffer=NULL,process_status[1000]={'\0'};
	    filename=(char *)malloc(1000*sizeof(char));
	    buffer=(char *)malloc(1000*sizeof(char));
	    sprintf(filename,"/proc/%d/status",store_pid[i]);
	    
	    FILE *fp;
	    //opening file for reading 
	    fp=fopen(filename,"r");
   		while(fgets(buffer,200,fp)!=NULL)
   		{ 
     		 if(strncmp("State",buffer,5)==0)
     		 {
     			j=5;
     		 	k=0;
     		 	while(j<strlen(buffer))
     		 	{
     		 		process_status[k]=buffer[j];
     		 		k++;
     		 		j++;
     		 	}
     		 }
   		}
		printf("[%d] %s %s [%d]\n",i+1,process_status,nstr[i],store_pid[i]);
		fclose(fp);
   		i++;
   	}
}
	
