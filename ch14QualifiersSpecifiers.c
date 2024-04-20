// Qualifiers and Specifier
#include <stdio.h>

void counter(void);

int main(){

    // Type Qualifiers

    //const : can’t change a const value.
    // you wil also see use of const in passing parameter list of functions.
    const int x = 2;
    //x = 4; // error, can't assign to a constant

    //const and Pointers

    // a pointer to a pointer to char 
    // p++ increments the pointer p itself , thus moving to next 'pointer' to char
    // (*p)++ , increments char pointer to which p was pointing , moving to next char
    char *xx = {"Hello"};
    char **p  = &xx;
    p++; // allowed
    (*p)++; // allowed

    //a constant pointer to a pointer to a character. 
    char **const p1 = &xx;
    // p1++;  error: cannot increment p1 as it's a const
    (*p)++; // ok , the value p1 is pointing is not const

    // a pointer to a constant pointer to a character.
    char *const *p2 = &xx;
    p2++; // ok, move to next const pointer to char
    // (*p2)++; // error, can change value of const pointer to char

    //a constant pointer to a constant pointer to a character.
    char *const *const p3 = &xx;
    // p3++; // error
    // (*p3)++; // error


    // const Correctness
    const int x1 = 20; 
    //int *p4 = &x; //it is discarding the “const-ness” of the expression on the right.

    //restrict:restrict is a hint to the compiler that a particular piece of 
    //memory will only be accessed by one pointer and never another.

    //volatile:ells the compiler that a value might change behind its back and 
    //should be looked up every time instead taking value it stored in register.
    // like hardware base timer.
    //thing this points at might change at any time for reasons outside this program code
    //volatile int *p;

    //Storage-Class Specifiers

    //auto:that this object has automatic storage duration. That is, it exists 
    //in the scope in which it is defined, and is automatically deallocated 
    //when the scope is exited.

    //static: 

    //static in Block Scope
    //its value will persist between calls.
    //static block scope variables are initialized to 0 by default.
    counter(); // 1 time
    counter(); // 2 time 
    counter(); // 3 time 


    //static in File Scope: that this variable isn’t visible outside of this 
    //particular source file. Kinda like “global”, but only in this file.

    //extern:  gives us a way to refer to objects in other source files.
    /*
        lets say in a file foo.c you have a var : int boo = 10
        then if in this file , at file scope you declare 
        extern int a; then any where boo is used in this file will use boo from 
        foo.c
        if you declare in some other scope than file scope that will work too

    */

    //register:to hint to the compiler that this variable is frequently-used, 
    // and should be made as fast as possible to access. 
    // The compiler is under no obligation to agree to it.
    // but there's downside
    // You can’t take the address of a register or dereference it as the value 


    //_Thread_local:his is a way to make sure that each thread gets its 
    // own copy of the variable, preventing race condition .
   
}

void counter(void){
    static int count = 1;
    printf("This has been called %d time(s)\n", count);
    count++;
}