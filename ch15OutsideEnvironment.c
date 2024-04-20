#include <stdio.h>
#include <stdlib.h>

// if you are on unix like system
//environ is an array of strings terminated with a NULL pointer.
//Each string is in the form "key=value" and needs split then parsing
extern char **environ;

// you can also write: int main(int argc, char *argv[])
int main(int argc , char **argv){
    // the zeroth argument is the name of the executable, itself
    // fun trivia about argv is that after the last string is a pointer to NULL.
    // argv[argc] == NULL

    // Cute trick to get the compiler to stop warning about the 
    // unused variable argc: here we are using it tho
    //(void)argc; 
    if (argc != 3){
        printf("Usage : multiply X Y\n pass two numbers as args to executable\n");
        return EXIT_FAILURE; // Indicate to shell that it didn't work
    }
    printf("%d\n",atoi(argv[1])*atoi(argv[2]));
    //if execution reaches the end of main() without finding are turn, it 
    //automatically does a return 0 .
    //a positive non-zero number means failure
    
    //Environment Variables
    // used && i < 3 to keep output small here
    for(int i = 0; environ[i]!= NULL && i < 3; i++){
        printf("%s\n",environ[i]);
    }

    /*
        on unix you can use this, works like environ but less portable
        int main(int argc, char **argv, char **env){
            for (int i = 0; env[i] != NULL; i++) { 
                printf("%s\n", env[i]);
            }
        }
    */

    // to get particular environment variable
    // Unix-like: look at documentation for putenv(), setenv(), and unsetenv()
    char *env_val = getenv("CXX");
    // Check to make sure it exists
    if (env_val == NULL) {
        printf("Cannot find the CXX environment variable\n"); 
        return EXIT_FAILURE;
    }
    printf("Value: %s\n", env_val);

}