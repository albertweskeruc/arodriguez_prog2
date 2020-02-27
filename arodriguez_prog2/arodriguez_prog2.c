#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include "arodriguez_exec.h"
#include "arodriguez_argtok.h"

/*To run type make to compile make file, then ./prog_2 to run executeable*/

int main(){
      int i;

      int inputSize;

      char buff[128];// Character buffer

      char **args;



      write(1, "Welcome to the Student Shell (type 'x' to exit)\n", 48);

      while(1)

	{

	  // Request a line of input

	  write(1, "\nshell -> ", 10);

	  // Read the line

	  inputSize = read(0, buff, 128);

	  // Strip off carriage return

	  buff[inputSize-1] = '\0';


	  //if true, skip the rest of the code and start again for user input
	  if(buff[0] == '\0')
      
	    continue;


	  //check for the lowercase x command to quit
	  if((buff[0] == 'x') && (buff[1] == '\0')){

	      exit(0);
	    }
	  // make the argument vector
	  args = argtok(buff);

	  // execute the command
	 int CmdCheck = executeCmd(args);
	 //invalid command detected
	 if(CmdCheck == -1){
              printf("Command is invalid\n");
          }
	}

      return 0;

    }
