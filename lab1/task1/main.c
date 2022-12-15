#include "stdio.h"
#include "unistd.h"

int main (int argc, char *argv [])
{
    int pid = fork();
    if (pid == 0)
    {     
        pid=fork();
        if(pid==0)
        {
            printf ("child process, pid3 %d\n",getpid());
            sleep(100);                       
        } 
        else
        {
            printf ("child process, pid2 %d\n",getpid());   
            sleep(100);        
            
        }          
    }
    else
    {
        pid=fork();
        if(pid==0)
        {
            pid=fork();
            if(pid==0)
            {
                printf ("child process, pid5 %d\n",getpid());
                sleep(100);  
                              
            }
            else
            {
                pid=fork();
                if(pid==0)
                {
                    printf ("child process, pid6 %d\n",getpid());
                    sleep(100);   
                                    
                }
                else
                {
                    printf ("child process, pid4 %d\n",getpid());
                    sleep(100);  
                                      
                }
            }
        }
        else
        {
            pid=fork();
            if(pid==0)
            {
                printf ("child process, pid7 %d\n",getpid());
                sleep(100);   
                             
            }
            else
            {
                printf ("parent process, pid1 %d\n",getpid());
                sleep(100);    
                           
            }
        }
    }
    return 0;
}