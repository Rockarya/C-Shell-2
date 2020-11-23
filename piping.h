void piping(char ** str)
{
    int numPipes,i,j,k,f;
    //Joining strings to make commands to be used in piping
    char ***args=NULL;
    args=(char ***)malloc(100*sizeof(char));
    i=0;
    j=0;
    k=0;
    args[j]=(char **)malloc(100*sizeof(char));
    while(str[i]!=NULL)
    {
        if(strcmp(str[i],"|")==0)
        {
            j++;
            args[j]=(char **)malloc(100*sizeof(char));
            k=0;
        }
        else
        {
            args[j][k]=(char *)malloc(100*sizeof(char));
            strcpy(args[j][k],str[i]);
            k++;
        }
        i++;
    }
    numPipes=j+1;
    int pipefds[2*numPipes];        //There will be numPipes number of pipes,2 is multiplied because there is read and write end.

    for(i=0;i<(numPipes);i++)
    {
        if(pipe(pipefds+i*2)<0)
        {
            perror("Couldn't pipe\n");
        }
    }

    j=0;
    k=0;
    while(args[k]!=NULL)
    {
        f=fork();
        if(f==0)
        {
            //if it is not the last command
            if(args[k+1]!=NULL)
            {
                if(dup2(pipefds[j+1],1)<0)              //STDOUT_FILENO = 1
                {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            //if it's not the first command
            if(k!=0)
            {
                if(dup2(pipefds[j-2],0)<0)              //STDOIN_FILENO = 0
                {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            for(i=0;i<2*numPipes;i++)
            {
                close(pipefds[i]);
            }

            if(check_redirection(args[k]))
            {
                i_o_redirection(args[k]);       //if i_o_redirection is there in the command
            }
            else
            {
                if(execvp(args[k][0],args[k]) == -1)
                {
                    perror(args[k][0]);
                    exit(EXIT_FAILURE);
                }
            }
        }
        else if(f<0)
        {
            printf("Child not created\n");
        }
        k++;
        j+=2;
    }

    for(i=0;i<2*numPipes;i++)
    {
        close(pipefds[i]);
    }
    for(i=0;i<numPipes+1;i++)
    {
        wait(NULL);
    }
}