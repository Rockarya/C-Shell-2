#include<stdio.h>
#include "header.h"

int main()
{
	//This is just to get the Parent directory i am in
	char *Parentdirectory=NULL,ch;
	Parentdirectory=(char *)malloc(1000*sizeof(char));
	Parentdirectory=getcwd(Parentdirectory,1000*sizeof(char));

	int i,j,fo,pid=0,itr,foo,pid_num,f;
	pid_t *npid=NULL;
	char **string=NULL,**nstr=NULL;
	string=(char **)malloc(1000*sizeof(char));
	npid=(int *)malloc(10000*sizeof(int));
	last_working_directory=(char *)malloc(1000*sizeof(char));
	nstr=(char **)malloc(1000*sizeof(char));
	for(i=0;i<1000;i++)
	{
		nstr[i]=(char *)malloc(1000*sizeof(char));
	}
 	strcpy(last_working_directory,Parentdirectory);
	pid_num=0;
	while(1)
	{
		type_prompt(Parentdirectory);
		char *buffer=NULL;
		size_t bufsize=1005;			//It’s an unsigned integral type which is used to represent the size of objects in bytes
		buffer=(char *)malloc(bufsize*sizeof(char));
		if(buffer==NULL)
		{
			perror("Unable to allocate buffer\n");
			exit(1);
		}

		i=0;
		while((ch = getchar()) != EOF && i < 1000)
		{
			if(ch=='\n')
			{
				break;
			}
      		buffer[i] = ch;
      		if(i>2 && buffer[0]=='q' && buffer[1]=='u' && buffer[2]=='i' && buffer[3]=='t')
      		{
      			exit(1);
      		}
      		i++;
   		}
   		if(ch!='\n')			//handling ctrl+d using EOF character
   		{
   			exit(1);
   		}
		char **s=NULL;
		s=(char **)malloc(100*sizeof(char));
		for(i=0;i<100;i++)
		{
			s[i]=(char *)malloc(100*sizeof(char));
		}
		s=read_command(buffer);
		
		i=0;
		//implementing built-in commands and system calls
		while(s[i]!=NULL)
		{
			string=history(string,s[i]);				//To get the history of commands
			char *token=NULL,**str=NULL;
			str=(char **)malloc(100*sizeof(char));
			token=(char *)malloc(100*sizeof(char));
			token=strtok(s[i]," \t");		//By writing " \t" delimiter it will tokenize with both space bar and tab

			j=0,flag=0;
			while(token!=NULL)
			{
				str[j]=(char *)malloc(100*sizeof(char));
				strcpy(str[j],token);
				j++;
				token=strtok(NULL," \t");
			}
			str[j]=NULL;
			if(strcmp(str[j-1],"&")==0)
			{
				str[j-1]=NULL;			//if flag==1 then last command is & so equate it to NULL so that it won't be considered as parameter
				flag=1;					//to determine process is foreground or background
			}

			f=fork();			//This is just meant to run foreground and background process
			if(f>0)
			{
				fpid=f+1;
				signal(SIGINT,sigintHandler);		//handling ctrl+c  (Working partially)
				signal(SIGTSTP,sigtstpHandler);		//handling ctrl+z(Not woking)
				if(flag==1)		//if we are running background process then we do not have to wait for it to get finish
				{
					npid[pid_num]=f+1;		//This is done because we are using fork 2 times
					char *nstring=NULL;
					nstring=(char *)malloc(1000*sizeof(char));
					for(itr=0;itr<j-1;itr++)
					{
						strcat(nstring,str[itr]);
					}
					strcpy(nstr[pid_num],nstring);
					pid_num++;
				}
				else
				{
					wait(NULL);		//We have to wait until foreground process completes and returns to us
				}
			}
			else if(f==0)
			{
				if(flag==1)
				{
					foo=fork();
					if(foo==0)
					{
						pid=getpid();
						printf("%s with pid %d created succesfully\n",str[0],pid);			//To get acknowledgement that Background process is created
						if(check_piping(str))			//piping + i_o_redirection if it's there in the command
						{
							piping(str);
						}
						else if(check_redirection(str))			//i/o redirection only
						{
							i_o_redirection(str);
						}
						else
						{
							execvp_command(str);
						}
					}
					else if(foo>0)
					{
						pid=foo;
						wait(NULL);
					}
					else
					{
						perror("No child is created\n");
					}
				}
				else
				{
					if(check_piping(str))			//piping + i_o_redirection if it's there in the command
					{
						piping(str);
					}
					else if(check_redirection(str))			//i/o redirection only
					{
						i_o_redirection(str);
					}
					else
					{
						if(strcmp(str[0],"cd")==0)
						{
							if(cd_command(str,Parentdirectory)!=0)
							{
								printf("cd: Error running the command\n");
							}
						}
						else if(strcmp(str[0],"echo")==0)
						{
							echo_command(str);
						}
						else if(strcmp(str[0],"pwd")==0)			
						{
							pwd_command(Parentdirectory);
						}
						else if(strcmp(str[0],"ls")==0)
						{
							
							if(!ls(str,Parentdirectory))
							{
								printf("%s : Command not found\n",str[0]);
							}
						}
						else if(strcmp(str[0],"pinfo")==0)
						{
							if(!pinfo_command(str))
							{
								printf("File doesn't exists\n");
							}
						}
						else if(strcmp(str[0],"history")==0)
						{
							if(!history_command(string,str))
							{
								printf("Invalid command\n");
							}
						}
						else if(strcmp(str[0],"setenv")==0)			//printenv var      -to get the value of that variable 
						{
							if(str[1]==NULL)
							{	
								perror(str[1]);
							}
							else if(str[2]!=NULL && str[3]==NULL)
							{
								if(setenv(str[1],str[2],1)==-1)
								{
									printf("Invalid Command\n");
								}
							}
							else
							{
								if(str[2]==NULL)
								{
									printf("Too few arguments: Value of %s is set to NULL\n",str[1]);
									char *tempstring=NULL;
									tempstring=(char *)malloc(100*sizeof(char));
									setenv(str[1],tempstring,1);
								}
								else
								{
									printf("Invalid Command: Too many arguments\n");
								}
							}
						}
						else if(strcmp(str[0],"unsetenv")==0)
						{
							if(str[2]!=NULL)
							{
								printf("Invalid Command: Too many arguments\n");
							}
							else if(unsetenv(str[1])==-1)
							{
								printf("Invalid Command: Too few arguments\n");
							}
						}
						else if(strcmp(str[0],"jobs")==0)
						{
							jobs(npid,nstr);
						}
						else if(strcmp(str[0],"kjob")==0)
						{
							kjob(str,npid);
						}
						else if(strcmp(str[0],"fg")==0)
						{
							fg(npid,str);
						}
						else if(strcmp(str[0],"bg")==0)
						{
							bg(npid,str);
						}
						else if(strcmp(str[0],"overkill")==0)
						{
							overkill(npid);	
						}
						else
						{
							fo=fork();
							if(fo==0)
							{
								execvp_command(str);
							}
							else if(fo>0)
							{
								wait(NULL);
							}
							else
							{
								perror("No child is created\n");
							}
						}
					}
				}
				last_working_directory=getcwd(last_working_directory,1000*sizeof(char));
				if(flag==1)
				{
					printf("%s with pid %d exited normally\n",str[0],pid);		//To get the status of the completion of the background process.
					exit(0);													//It will enter here only when it will get complete
				}
			}
			else
			{
				perror("Child not created\n");
			}
			i++;
		}
	}
	return 0;
}
