//Scope is all about what variables are visible in what contexts.
#include <stdio.h> 
int main(void){
    int a = 12; // Local to outer block, but visible in inner block
    if (a==12){
        int b = 99; // Local to inner block, not visible in outer block
        printf("%d %d\n", a, b); // OK: "12 99"
        // a variable named the same thing at an inner scope as one at an outer 
        //scope, the one at the inner scope takes precedence as long as you’re 
        //running in the inner scope. 
        int a = 14;
        printf("%d %d\n", a, b); // "14 99"
    }
    printf("%d\n", a); // OK, we're still in a's scope
    // printf("%d\n", b); // ILLEGAL, out of b's scope
    //printf("%d\n", j); // // ILLEGAL--can't use j before it's defined
    int j = 5;

    // prints 999 five times:
    for (int i = 0; i < 5; i++) {
       int i = 999; // Hides the i in the for-loop scope 
       printf("%d\n", i);
    }
}