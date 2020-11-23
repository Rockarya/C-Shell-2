#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include<signal.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "prompt.h"
#include "read_command.h"
#include "echo_command.h"
#include "pwd_command.h"
#include "execvp_command.h"
#include "history.h"
#include "history_command.h" 
#include "ls.h"
#include "pinfo_command.h"
#include "check_redirection.h"
#include "i_o_redirection.h"
#include "check_piping.h"
#include "piping.h"
#include "jobs.h"
#include "kjob.h"
#include "fg.h"
#include "bg.h"
#include "overkill.h"

pid_t fpid;
int flag=0;
char *last_working_directory=NULL;

#include "cd_command.h"
#include "sigintHandler.h"
#include "sigtstpHandler.h"
