#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void main(){
  pid_t pID = fork(); // creates copy of the parent process - in this case 1 chid process have been created
  if (pID ==0) //code executed by child1 
    {
     char *args[] = {"genrsa","-out","rsaprivatekey2048.pem","2048",NULL };
     execvp("openssl", args);
    }
    else if(pID<0) // Case to handle exception when fork failed to create child process
    {
      printf("Failed to fork") ;
      exit(1);
    }
    else
      {
        // code executed by parent process
		int returnStatus;
		waitpid(pID, &returnStatus, 0); //waits for child process to terminate(in this case child1)	
        pid_t pID1 = fork();
        if (pID1 ==0) //code executed by child2
        {
            char *args1[] = {"genrsa", "-out", "rsaprivatekey1024.pem", "1024", NULL };
            execvp("openssl", args1);
        }
        else //code executed by Parent Process
        {
			int returnStatus1;
			waitpid(pID1, &returnStatus1, 0);
			pid_t pID2=fork();
            if(pID2==0){ //code executed by child3
                char*args2[]={"rsa","-in","rsaprivatekey2048.pem","-out","rsapublickey2048.pem","-outform","PEM","-pubout"};
                execvp("openssl",args2);
            }
            else //code executed by Parent Process
            {
                pid_t pID3=fork();
                if(pID3==0){ //code executed by child4
					char*args3[]={"rsa","-in","rsaprivatekey1024.pem","-out","rsapublickey1024.pem","-outform","PEM","-pubout"};
					execvp("openssl",args3);
				}
            }
        }
    }
}
