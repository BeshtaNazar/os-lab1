#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

int main(int argc, char *argv[]) {
    int pid = fork();   
    int status;
    char *newArgv[argc];    
    if (pid == 0) {                
        for (int i = 0; i < argc-1; i++)
        {
           newArgv[i] = argv[i+1];                      
        } 
        newArgv [argc-1]=NULL;
        execvp(newArgv[0], newArgv);
        
    } else {
        
        waitpid(pid, &status,0);
        if(status==0)
        {
            printf("Success!\n");
        }
        else
        {
            printf("Failed, exit code = %d\n",status);
        }
        
    }
        
}