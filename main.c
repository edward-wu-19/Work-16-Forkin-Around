#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

int main(){

    printf("\nHello, this is a parent speaking.\n\n");

    int f = fork();

    if (f){

        int g = fork();

        if (g){
            int w, status;

            w = wait(&status);

            printf("The child with pid %d finished sleeping first after sleeping for %d seconds.\n\n", w, WEXITSTATUS(status));

            printf("I am a parent and I am done.\n\n");
        }
        else{
            printf("Child 2 pid: %d\n\n", getpid());
        
            srand(time(NULL));
            rand();
            int a = 2 + (rand() % 4);

            sleep(a);

            printf("Child 2: I stopped sleeping for %d seconds!\n\n", a);

            return a;
        }
    }
    else{
        printf("Child 1 pid: %d\n\n", getpid());
        
        srand(time(NULL));
        int a = 2 + (rand() % 4);

        sleep(a);

        printf("Child 1: I stopped sleeping for %d seconds!\n\n", a);

        return a;
    }

    return 0;
}