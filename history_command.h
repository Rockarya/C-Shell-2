int history_command(char ** string,char ** str)
{
	int f=1,i,k,num;
	if(str[1]==NULL)
	{
		num=0;
		while(string[num]!=NULL)
		{
			num++;
		}
		if(num<=10)
		{
			for(i=0;i<num && i<10;i++)
			{
				printf("%s\n",string[i]);
			}
		}
		else
		{
			for(i=num-10;i<num;i++)
			{
				printf("%s\n",string[i]);
			}
		}
	}
	else
	{
		if(str[2]!=NULL)
		{
			f=0;				//error handling part
		}
		else
		{
			num=atoi(str[1]);		//converting an string to an integer
			if(num>20)
			{
				f=0;
			}
			else
			{
				k=0;
				while(string[k]!=NULL)
				{
					k++;
				}
				if(num>k)
				{
					f=0;
				}
				else
				{
					for(i=k-num;i<k;i++)
					{
						printf("%s\n",string[i]);
					}
				}
			}
		}
	}
	return f;
}
