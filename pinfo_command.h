int pinfo_command(char ** token)
{
	int pid,i,k,f=1;
	i=1;
	if(token[i]==NULL)
	{
		pid=getpid();
	}
	else
	{
		sscanf(token[i],"%d",&pid);
	}
    char *filename=NULL,*executable_path=NULL,*buffer=NULL;
    filename=(char *)malloc(50*sizeof(char));
    executable_path=(char *)malloc(50*sizeof(char));
    buffer=(char *)malloc(1000*sizeof(char));
    sprintf(filename,"/proc/%d/status",pid);
    sprintf(executable_path,"/proc/%d/exe",pid);
    
    FILE *fp;
    char process_status[100]={'\0'},virtual_memory[100]={'\0'};
    /* opening file for reading */
    fp=fopen(filename,"r");
   	if(fp==NULL)
   	{
      	f=0;
   	}
   	else
   	{
   		while(fgets(buffer,200,fp)!=NULL)
   		{
     		 if(strncmp("VmSize",buffer,6)==0)
     		 {
     		 	i=6;
     		 	k=0;
     		 	while(i<strlen(buffer))
     		 	{
     		 		virtual_memory[k]=buffer[i];
     		 		k++;
     		 		i++;
     		 	}
     		 }
     		 if(strncmp("State",buffer,5)==0)
     		 {
     			i=5;
     		 	k=0;
     		 	while(i<strlen(buffer))
     		 	{
     		 		process_status[k]=buffer[i];
     		 		k++;
     		 		i++;
     		 	}
     		 }
   		}
   		/*To get the Executable path*/
   		ssize_t len=readlink(executable_path,buffer,sizeof(buffer));
   		buffer[len]='\0';

   		printf("pid -- %d\n",pid);
   		printf("Process Status -- %s\n",process_status);
   		printf("memory -- %s\n",virtual_memory);
   		printf("Executable Path -- %s\n",buffer);
   		fclose(fp);
   	}
   return f;
}
