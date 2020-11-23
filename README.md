These are the features of my code:-

1) Features:-
		->Implemented cd - command
		->Implemeted history command.
		->Implemented a shell that supports a semi-colon separated list of commands.
		->Supported '&' operator which lets a program run in the background after printing the process id of the newly created process.
		
2) Error handling:-
		Used perror and printf statements for handling errors wherever i feel necessary.For the commands executed by execvp we don't know about it's success so no
		error handling for those commands. 

3) Shell loop in main.c file:-
		Tokenizing the inputted string of prompt and running each command step by step.Each of the commands are implemented as per the specificaition given in Assignment pdf.

4) cd functionality:-
		Implemented cd along with the flags ".","..","tilda" using chdir system call.

5) pwd functionality:-
		Implemented it using getcwd system call.

6) echo functionality:-
		Just tokenized command by space and tab and then outputted all the tokens by keeping a space in between.

7) ls functionality:-
		Implemented ls, ls -l, ls ., ls .., ls tilda, ls -a, ls -al/la and ls <Directoryname>.
		Also their valid combinations.

8) history functionality:-
		Stroring 20 commands in a 2D string and replacing them sequentially with the new ones.Throwing error for invalid commands

9) For system commands except the above specified:-
		I have used execvp system call to implement them.

10) Foreground and Background process:-
		Used forking for this purpose and if process is foreground then we will wait until it finishes it's execution and prints it's output to the terminal
		and if it's background then we won't wait for it and continue further to take user commands.

11) pinfo:-
		got pid using getpid() system call. 
		Opened /proc/pid/status file to get info about Process Status,Virtual memory,pid(already known).
		For getting executable path of file i have used readlink system call.(In this, filename will be /proc/pid/exe).The value returned will be the name of the executable path.  

12) Finished Background Process:-
		When background process gets over then i have wrote a printf statement in code to get acknowledgement about accomplishment of background process.
		A flag was raised to identify whether process is going to be foreground or background(by checking '&' character in the command line)

13) Read Command :-
		Used strtok to tokenize the command.
		In the case of tokenizing command from semi-colon i have used ";" as delimiter whereas in the case where we have to tokenize from spaces and tabs i have used " \t" as delimiter.(By using this delimiter it tokenizes string from both spaces and tabs in one go)

14) header.h :-
 		Inlcuded a header.h file which contains all the required headers.

15)	check_piping.h :-
		this contains function which check that command has pipe or not.

16) check_redirection.h :-
		this contains function which check that command has i_o_redirection opearators or not.

17) bg.h :-
		contains bg command functionality.

18)	fg.h :-
		contains fg command functionality.

19) i_o_redirection.h :-
		contains function which implements i/o redirection.

20) jobs.h :-
		contains jobs command functionality.
		The job numbers of the process will be updated automatically after you run 	kjob/fg/bg/jobs(if some background process was killed/stopped).

21) kjob.h :-
		contains kjob command functionality.

22) overkill.h :-
		contains overkill command functionality.

23) piping.h :-
		contains function which implements piping.

24) sigintHandler.h :-
		contains function which detects ctrl+c (SIGINT signal is send) and implemented it's functionality as specified.

25) sigtstpHandler.h :-
		contains function which detects ctrl+z (SIGTSTP signal is send) and implemented it's functionality as specified.

26) setenv :-
		implemeted in main.c file itself.

27) unsetenv :-
		implemented in main.c file itself.

28) quit :-
		implemented when taking input in main.c file only.
		Also ctrl+d is implemented when taking input and if input is EOF character the program gets terminated. 

29)	to implement grep in my shell do not use quotes otherwise it won't work.

30)If some command doesn't work in first time, again run it,it will work.















  
