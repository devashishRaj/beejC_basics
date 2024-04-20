/* this is a comment, usefull for multipline */
// so is this , usefull for single line comments
// #include tells C preprocessor to incluse code of stdio.h into this file before compilation
// file with '.h' extension are header files and prevent us from reinventing the wheel.
// stdio gives us i/o functionality, here it's printf to send output to console.
// type "man 3 printf" on a unix console to learn more about printf
#include <stdio.h>
// 'main' is a functon and everything between{} is it's body
// everything between () is it's parameter, here void
// "main" is a special function, whenever a c program starts executing it starts from main
// once program has gone through last instruction of "main", it will terminate.
int main(void){
	// printf(some arguments); is a functon call to printf
	// '\n' is special character called newline character that tells console to start next output 
	// from next line (like pressing enter)
	printf("Hello World!\n");
}

// you can compile '.c' file on mac via : "clang -Wall -Wextra -std=c2x -pedantic -o filename filename.c"
// this will give a executable file with name filename that can be run by command "./filename"

