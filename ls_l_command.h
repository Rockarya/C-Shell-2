int ls_l_command(char ** token,int f1,char * Parentdirectory)
{
	int f=1,i;
	char *curdirectory=NULL;
	curdirectory=(char *)malloc(1000*sizeof(char));
	curdirectory=getcwd(curdirectory,1000*sizeof(char));

	DIR *myDirectory;
	struct dirent *myFile;

	if(f1==1)
	{
		i=1;
		while(token[i]!=NULL)
		{
			if(strcmp(token[i],"-l")!=0)
			{
				printf("%s :\n",token[i]);
				if(strcmp(token[i],"~")==0)
				{
					strcpy(token[i],Parentdirectory);
				}
				struct stat sfile;
				myDirectory = opendir(token[i]);
		        if(myDirectory) 
		        {
		            while ((myFile = readdir(myDirectory)))
		            {
		            	if(myFile->d_name[0]!='.')		//All hidden files start with a dot
		            	{
			            	stat(myFile->d_name,&sfile);
			            	printf((sfile.st_mode & S_IFDIR)? "d":"-");		//directory or file
			            	//user permissions
			            	printf((sfile.st_mode & S_IRUSR)? "r":"-");
						  	printf((sfile.st_mode & S_IWUSR)? "w":"-");
						  	printf((sfile.st_mode & S_IXUSR)? "x":"-");
						  	//group permissions
						  	printf((sfile.st_mode & S_IRGRP)? "r":"-");
						  	printf((sfile.st_mode & S_IWGRP)? "w":"-");
						  	printf((sfile.st_mode & S_IXGRP)? "x":"-");
							//other permissions
						  	printf((sfile.st_mode & S_IROTH)? "r":"-");
						  	printf((sfile.st_mode & S_IWOTH)? "w":"-");
						  	printf((sfile.st_mode & S_IXOTH)? "x":"-");
						  	//printing owner name of file
						  	struct passwd *pws;
						  	pws=getpwuid(sfile.st_uid);
						  	printf(" %s",pws->pw_name);
						  	//printing grp name of file
						  	struct group *grp;
						  	grp=getgrgid(sfile.st_gid);
						  	printf(" %s",grp->gr_name);
						  	//size of file
						  	printf(" %ld",sfile.st_size);
						  	//recent time file was modified
						  	time_t t = sfile.st_mtime;
							struct tm lt;
							localtime_r(&t, &lt);
							char buf[200]; 
							strftime(buf, sizeof(buf), "    %b  %d  %H:%M",&lt);
							printf("%s    ", buf);
							//printing file name
							printf("%s\n",myFile->d_name);
						}
		            }
		        }
		        else
		        {
		        	f=0;
		        }
		    }
	        i++;
	    }
	}
	else
	{
		struct stat sfile;
		myDirectory = opendir(curdirectory);
        if(myDirectory) 
        {
            while ((myFile = readdir(myDirectory)))
            {
            	if(myFile->d_name[0]!='.')		//All hidden files start with a dot
            	{
	            	stat(myFile->d_name,&sfile);
	            	printf((sfile.st_mode & S_IFDIR)? "d":"-");		//directory or file
	            	//user permissions
	            	printf((sfile.st_mode & S_IRUSR)? "r":"-");
				  	printf((sfile.st_mode & S_IWUSR)? "w":"-");
				  	printf((sfile.st_mode & S_IXUSR)? "x":"-");
				  	//group permissions
				  	printf((sfile.st_mode & S_IRGRP)? "r":"-");
				  	printf((sfile.st_mode & S_IWGRP)? "w":"-");
				  	printf((sfile.st_mode & S_IXGRP)? "x":"-");
					//other permissions
				  	printf((sfile.st_mode & S_IROTH)? "r":"-");
				  	printf((sfile.st_mode & S_IWOTH)? "w":"-");
				  	printf((sfile.st_mode & S_IXOTH)? "x":"-");
				  	//printing owner name of file
				  	struct passwd *pws;
				  	pws=getpwuid(sfile.st_uid);
				  	printf(" %s",pws->pw_name);
				  	//printing grp name of file
				  	struct group *grp;
				  	grp=getgrgid(sfile.st_gid);
				  	printf(" %s",grp->gr_name);
				  	//size of file
				  	printf(" %ld",sfile.st_size);
				  	//recent time file was modified
				  	time_t t = sfile.st_mtime;
					struct tm lt;
					localtime_r(&t, &lt);
					char buf[200]; 
					strftime(buf, sizeof(buf), "    %b  %d  %H:%M",&lt);
					printf("%s    ", buf);
					//printing file name
					printf("%s\n",myFile->d_name);
				}
            }
        }
        else
        {
        	f=0;
        }	
	}
	return f;
}
