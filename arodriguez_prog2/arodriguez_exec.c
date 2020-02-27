#include <fcntl.h> //needed to help with the dup
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>   // 
#include <sys/wait.h>   //needed to help with wait methods for the parent
#include <unistd.h>     // needed for fork
#include "arodriguez_exec.h"

int execBackground(char **args){
  
  int i;
  // check for the ampersand at the end of the set of tokens
  i = 0;
  while(args[i] != 0) {
      i++;
    }                       // traverse to the end of the tokens
  if(args[i-1][0] == '&') // check the last token
    {
      free(args[i-1]);
      args[i-1] = NULL;  // remove the ampersand
      return 1; 
    }
  else{
      return 0;
    }
}

int executeCmd(char **args){
  pid_t  ID_tracker;
  int    status;      //tells parent when to wait and stop waiting
  int CheckBackground = execBackground(args);
  ID_tracker = fork();
  
  if (ID_tracker < 0) {
    printf("Child process creation has failed\n");
    return -1;

  }

  //child process created and attempting to run the user inpu command
  else if (ID_tracker == 0) {             

    //execute command with execvp, v = supports array of strings, p = 
    int CommandStatus = execvp(*args, args); // goes through each each char pointer in the array

    if(CommandStatus < 0) {  //checks if command was returned as invalid/error
      return -1; //send error to UI/bash
    }
  }
  //tell parent to wait for child to exit IF the child isnt running in the background
  else if(CheckBackground != 1){      
    do{
      waitpid(ID_tracker, &status, 0); 
    } while (!WIFEXITED(status)); //wait till child exits/finishes 
  }
}
