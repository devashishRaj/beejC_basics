//string in double quotes is type const char *

#include <stdio.h>
#include  <unistd.h>
// not available on mac or llvm maybe
//#include <threads.h>

int main(){
    // escape sequences: These are the backslash character (\) followed
    // by another character.

    //Frequently-used Escapes
    printf("newline \\n single quote \' double \" and backslash \\ \n");

    //Rarely-used Escapes example:Single Line Status Updates
    for(int i= 10; i > 0; i--){

        // ternary operator:print 1 second instead of 1 seconds.)
        // there’s a space after the ... That’s so that we properly overwrite the last .
        // \b to back up over that space so the cursor sits at the exact end of the line
        //try without space between ... and \b
        printf("\rT minus %d second%s... \b",i, i !=1 ?"s":"");
        //most terminals are line buffered ,they don't show anything unless
        // newline character is encountered so force flush
        fflush(stdout);

        // Sleep for 1 second
        usleep(500000);
        // need threads.h and unistd.h
        //thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); 

        //Numeric Escapes

    }
    printf("\rLiftoff! \n");
    //The Question Mark Escape
        //if you’re on some ancient terminal without a pipe symbol (|) on the 
        //keyboard, you can type ??! instead.
        // use escaping when using two '?'
        printf("Doesn't it?\?!\n");

    //numeric escapes: example: bullet is 2022 (hex) in Unicode
    printf("\u2022 Bullet 1\n"); 
    printf("\u2022 Bullet 2\n"); 
    printf("\u2022 Bullet 3\n");

}