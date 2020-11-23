void i_o_redirection(char ** str)
{
	int f1,f2,f3,i,in,out;					//in and out are file descriptors
	char **args=NULL,*cmd=NULL,*ifile=NULL,*ofile=NULL;
	cmd=(char *)malloc(1000*sizeof(char));
	args=(char **)malloc(100*sizeof(char));
	ifile=(char *)malloc(1000*sizeof(char));
	ofile=(char *)malloc(1000*sizeof(char));
	strcpy(cmd,str[0]);

	f1=0;		//if input redirection is used
	f2=0;		//if output redirection is used
	f3=0;		//if append is used

	//Either f2==1 or f3==1.Both cannot be 1 simultaneously
	i=0;
	while(str[i]!=NULL)
	{
		if(strcmp(str[i],"<")==0)
		{
			f1=1;
		}
		else if(strcmp(str[i],">")==0)
		{
			f2=1;
		}
		else if(strcmp(str[i],">>")==0)
		{
			f3=1;
		}
		i++;
	}

	if(f3==0)
	{
		if(f1==1 && f2==1)
		{
			i=0;
			while(strcmp(str[i],"<")!=0)
			{
				args[i]=(char *)malloc(1000*sizeof(char));
				strcpy(args[i],str[i]);
				i++;
			}
			i++;
			strcpy(ifile,str[i]);
			i+=2;
			strcpy(ofile,str[i]);
			in=open(ifile,O_RDONLY,00400);
			if(in<0)
			{
				printf("Input file doesn't exists\n");
				exit(1);
			}
			dup2(in,STDIN_FILENO);
			close(in);

			out=open(ofile,O_RDWR | O_CREAT,0644);
			if(out<0)
			{
				printf("File not created\n");
			}
			dup2(out,STDOUT_FILENO);
			close(out);
			if(execvp(cmd,args)==-1)
			{
				printf("Error running the command\n");
			}
		}
		else if(f1==1)
		{
			i=0;
			while(strcmp(str[i],"<")!=0)
			{
				args[i]=(char *)malloc(1000*sizeof(char));
				strcpy(args[i],str[i]);
				i++;
			}
			i++;
			strcpy(ifile,str[i]);
			in=open(ifile,O_RDONLY,00400);
			if(in<0)
			{
				printf("Input file doesn't exists\n");
				exit(1);					//so that we again get the prompt(we terminated the process)
			}
			dup2(in,STDIN_FILENO);
			close(in);
			if(execvp(cmd,args)==-1)
			{
				printf("Error running the command\n");
			}
		}
		else
		{
			i=0;
			while(strcmp(str[i],">")!=0)
			{
				args[i]=(char *)malloc(1000*sizeof(char));
				strcpy(args[i],str[i]);
				i++;
			}
			i++;
			strcpy(ofile,str[i]);
			fopen(ofile,"w");		//clearing the output file each time we write it
			out=open(ofile,O_RDWR | O_CREAT,0644);
			if(out<0)
			{
				printf("File not created\n");
			}
			dup2(out,STDOUT_FILENO);
			close(out);
			if(execvp(cmd,args)==-1)
			{
				printf("Error running the command\n");
			}
		}
	}
	else
	{
		if(f1==1)
		{
			args[i]=(char *)malloc(1000*sizeof(char));
			i=0;
			while(strcmp(str[i],"<")!=0)
			{
				strcpy(args[i],str[i]);
				i++;
			}
			i++;
			strcpy(ifile,str[i]);
			i+=2;
			strcpy(ofile,str[i]);
			in=open(ifile,O_RDONLY);
			if(in<0)
			{
				printf("Input file doesn't exists\n");
				exit(1);
			}
			dup2(in,STDIN_FILENO);
			close(in);

			out=open(ofile,O_RDWR | O_CREAT,0644);
			if(out<0)
			{
				printf("File not created\n");
			}
			lseek(out,0,SEEK_END);
			dup2(out,STDOUT_FILENO);
			close(out);
			if(execvp(cmd,args)==-1)
			{
				printf("Error running the command\n");
			}
		}
		else
		{
			i=0;
			while(strcmp(str[i],">>")!=0)
			{
				args[i]=(char *)malloc(1000*sizeof(char));
				strcpy(args[i],str[i]);
				i++;
			}
			i++;
			strcpy(ofile,str[i]);
			out=open(ofile,O_RDWR | O_CREAT,0644);
			if(out<0)
			{
				printf("File not created\n");
			}
			lseek(out,0,SEEK_END);			//To get to the end of the file so that we can append it and write from the last. 
			dup2(out,STDOUT_FILENO);
			close(out);
			if(execvp(cmd,args)==-1)
			{
				printf("Error running the command\n");
			}
		}
	}
}