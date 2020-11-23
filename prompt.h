#include<sys/utsname.h>

void type_prompt(char Parentdirectory[])
{
	struct utsname u;
	uname(&u);
	printf("<%s@%s:~",u.nodename,u.sysname);		//display prompt

	// Function to print Current Directory. 
    char *Currentdirectory;
	Currentdirectory=(char *)malloc(100000*sizeof(char));
	Currentdirectory=getcwd(Currentdirectory,100000*sizeof(char));
	long long int i,length;
	length=strlen(Parentdirectory);
	for(i=length;i<strlen(Currentdirectory);i++)
	{
		printf("%c",Currentdirectory[i]);
	}
	printf(">");
}
