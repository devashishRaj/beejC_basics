#include <stdio.h>

// this is a functoin prototype used to tell compiler about function
// it's parameter and return type
int foo(void);
int plus_1(int n);
void increment(int n);

//in the case of a function prototype
// void foo(); // leaving parameter list empty,indicates to the compiler that 
//there is no additional information about the parameters to the function. 
//It effectively turns off all that type checking.

// void foo(void); both are not the same. here compiler is told that function 
//has no parameter


// int is main return type and void tells us that this main does not take any argument
int main(void){
    int i = foo();
    printf("i is %d \n", i);
    // we don't hace explicitly have added return statement in main as, main's 
    // return is sent to OS whether program ran succesfully or encountered some error.
    // you can add return 0 for succefull execution but it's not necessary.

    // when we pass arguments to a functions this arguments are copied into parameters
    // this parameters acts as a local variable inside function and once function
    // exits they are destroyed.

    // pass by value ,thus a copy is i is made as 'n' and incremented, leaving i
    // unmodified.
    increment(i);
    printf("I is %d\n",i);
    // pass by value but copy is assigned back to i
    i = plus_1(i);
    printf("I is %d\n",i);
}

int foo(void){
    return 3423;
}

int plus_1(int n){
    return n+1;
}

void increment(int n){
    n +=1;
}

//NOTE:Always use void to indicate that a function takes no parameters.


