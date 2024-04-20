// #include: a way to include other sources in yoursource.
//use angle brackets (< and >) for the system includes, and 
// use double quotes (") for your personal includes.
//also by looking in relative directories using forward slashes and dots
//#include "mydir/myheader.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



#define HELLO "Hello World" 
#define PI 3.14159 
#define EXTRA_EMPTY // this one has no value , replaced with blank..
#define EXTRA_HAPPY // even though empty , still defined

#define MODE_3

//proper way to put the macro together is to wrap the whole thing in additional parentheses
#define SQR(x) ((x)*(x)) 

int main(){
    // macros: an identifier that gets expanded to another piece of code before 
    //the compiler even sees it.
    //after preprocessing line below converts to 
    //printf("%s, %f\n", "Hello, world", 3.14159);
    printf("%s, %f\n", HELLO, PI);
    //Note:that the macros don’t have a specific type,If the resulting C code is
    // invalid, the compiler will puke.

    //Conditional Compilation
    //If Defined, #ifdef and #endif
    #ifdef EXTRA_HAPPY
        printf("I am happy\n");
    #endif
    //If Not Defined, #ifndef
    #ifndef EXTRA_HAPPY2
        printf("I am not happy 2\n");
    #endif

    #ifdef MODE_1
        printf("MODE 1\n");
    //you can also use #elifndef for “else if not defined”.
    #elifdef MODE_2
        printf("MODE 2\n");
    #elifdef MODE_3
        printf("MODE 3\n");
    #else
        printf("There no mode activated\n");
    #endif

    //General Conditional: #if, #elif exits to
   // Losing a Macro: #undef
   #undef MODE_3 // mode3 is undefined now

   //Built-in Macros:are particularly useful to report error conditions in messages 
   //The assert() macro in <assert.h> uses these to call out where in the code 
   //the assertion failed.
   printf("This function %s\nThis file %s\n",__FUNCTION__,__FILE__);
   printf("This line %d\nCompiled on %s %s\n",__LINE__,__DATE__,__TIME__);
   printf("C version %ld\n", __STDC_VERSION__);

    //Macros with Arguments
    // below line expands to: printf("%d\n", (3 + 4) * (3 + 4)); 
    printf("%d\n", SQR(3 + 4));

    // macros with more than one args
    #define RIGHT_TRIANGLE_AREA(w, h) (0.5 * (w) * (h))
    #define RIGHT_TRIANGLE_HYPTOTENUSE(w,h) (sqrt((w*w)+(h*h)))
    // use both with single macro
    #define RIGHT_TRIANGLE(w,h) RIGHT_TRIANGLE_AREA(w, h), RIGHT_TRIANGLE_HYPTOTENUSE(w,h)
    printf("area %f and hyptenuse %f\n",RIGHT_TRIANGLE(3, 4));

    //Macros with Variable Arguments
    //have a variable number of arguments passed to a macro, using ellipses (...)
    //When the macro is expanded, all of the extra arguments will be in a 
    //comma- separated list in the __VA_ARGS__ macro
    #define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__
    printf("%d %f %s %d\n", X(5, 4, 3.14, "Hi!", 12));

    //“stringify” __VA_ARGS__ by putting a # in front of it:
    #define XB(...)#__VA_ARGS__
    printf("%s\n",XB(1,2,3));  // Prints "1, 2, 3"

    //you can turn any argument into a string by preceding it with a # 
    #define STR(x) #x
    printf("Turn to string: %s\n",STR(3.14159));

    //Concatenation  two arguments together with ##
    #define CAT(a,b) a ## b
    printf("CATENATION : %f\n",CAT(3.14,159));

    //Multiline Macros use '\' to extend macro to next line
    //Escapes at the end of every line except the last one to indicate 
    //that the macro continues.
    //The whole thing is wrapped in a do-while(0) loop with squirrley braces,
    // to absorb the trailing ; read comment below
    
    #define PRINT_NUMS_TO_PRODUCT(a,b) do{\
        int product = (a)*(b);\
        for(int i=0; i < product; i++){\
            printf("%d\n",i);\
        }\
    }while(0) // 0 : false so runs exactly once
    PRINT_NUMS_TO_PRODUCT(2, 4);// this one right is the trailing ';'

    //An Assert Macro:a good way to catch conditions that you think shouldn’t happen.
    //NOTE:string literals next to each other are automagically concatenated.
    // to turn on/off assert 
    #define ASSERT_ENABLED 1
    #if ASSERT_ENABLED
    #define MY_ASSCERT(c,m) \
    do{ \
        if(!(c)){ \
            fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
            __LINE__, #c, m); \
            exit(1); \
        }\
    }while(0)
    #else
    #define ASSERT(c, m) // Empty macro if not enabled 
    #endif
    int x = 30;
    MY_ASSCERT(x < 20, "x is not less than 20");

    //The #embed Directive is new in C23, look in documentation
    // The #pragma Directive, look in documentation
}

