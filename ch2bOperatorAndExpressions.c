#include <stdio.h>

int main(void){
    int i = 0;
    i = i + 3; // Addition (+) and assignment (=) operators, add 3 to i i = i - 8; // Subtraction, subtract 8 from i
    i = i * 9; // Multiplication
    i=i/2; //Division
    i = i % 5; // Modulo (division remainder)

    i+=3; //Sameas"i=i+3",add3toi i-=8; //Sameas"i=i-8"
    i*=9; //Sameas"i=i*9"
    i/=2; //Sameas"i=i/2"
    i%=5; //Sameas"i=i%5"

    // ternary operator
    // If x > 10, add 17 to y. Otherwise add 37 to y.
    int x = 4;
    int y = 9;
    y += (x > 10? 17: 37);   
    // another example
    printf("The %d is %s\n",x , x %2 == 0 ? "even": "odd");

    //NOTE:
    //With pre-increment and pre-decrement, the value of the variable is 
    //incremented or decremented before the expression is evaluated. Then the 
    //expression is evaluated with the new value.     

    //post-increment and post-decrement, the value of the expression is first 
    //computed with the value as-is, and then the value is incremented or 
    //decremented after the value of the expression has been determined.
    
    i = 10;
    int j = 5 + i++; // Compute 5 + i, _then_ increment i
    printf("%d, %d\n", i, j); // Prints 11, 15  

    i = 10;
    j = 5 + ++i; // Increment i, _then_ compute 5 + i
    printf("%d, %d\n", i, j); // Prints 11, 16

    //  comma operator
    int z = (1, 2, 3);
    printf("z is %d\n", z); // Prints 3, because 3 is rightmost in the comma list

    //Conditional Operators
    // we can the bool value evaluated in in conditonal statements...
    // a == b , True if a is equivalent to b
    // a!= b
    // a < b
    // a > b
    // a >= b
    // a <= b

    // Boolean Operators
    // && is and 
    // || is OR
    // ! is not
    // both comparisons need to be true for printf to execute
    if (x < 10 && y > 20) printf("Doing something!\n");
    if (!(x < 12)) printf("x is not less than 12\n");
    if (x >= 12) printf("x is not less than 12\n");
    if (x < 10 || y > 1) printf("using || operator,only one comparison need to be true\n");

    // The sizeof Operator, returns value of type size_t(unsigned int)
    // sizeof is a compile-time operation
    // tells you the size (in bytes) that a particular variable or data type uses in memory.
    int d = 999;
    // %zu is the format specifier for type size_t
    // // If you need to print out negative size_t values, use %zd
    printf("%zu size of d\n", sizeof d);  
    printf("%zd size of 2-7\n", sizeof(2 - 7));
    // Remember: it’s the size in bytes of the type of the expression, not the size of the expression itself. 
    printf("%zu size of 3.14\n", sizeof 3.14); 
    printf("%zu size of int\n", sizeof(int)); 
    printf("%zu size of char\n", sizeof(char)); // Prints 1 on all systems

}