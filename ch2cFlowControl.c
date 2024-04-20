#include <stdio.h>
#include <stdlib.h>

int main(void){
    int x = 10 ;
    // single line if statement
    if (x == 10) printf("x is 10\n");
    // prefered style
    if (x== 10) {
        // can add multiple statements here
        printf("x is 10\n");
    }

    // The if-else statement
    int i = 10;
    if (i == 10){
        printf("i is 10!\n");
    }else if (i == 20) {
        printf("i is decidedly not 10.\n");
        printf("Which irritates me a little, frankly.\n");
    }else if (i == 99) {
        printf("i is 99! My favorite\n");
    }else{
        printf("i is some crazy number I've never heard of.\n");
    }

    // The while statement
    // not-uncommon use of while is for infinite loops where you repeat while true:
    int ii = 0;
    while (ii < 10) {
    printf("ii is now %d!\n", ii); ii++;
    }
    printf("All done!\n");

    // The do-while statement
    // if the loop condition is false on the first pass, do-while will execute once
    int dw = 10;
    do {
        //this is executed once
        printf("do-while: i is %d\n", i); i++;
    } while (dw < 10);

    // determinstic use case 
    int r;
    do{
        r = rand() % 100;// get a random number between 0 and 99
        printf("%d\n",r);
    }while(r != 37);

    // The for statement
    // for (initialize things; loop if this is true; do this after each loop)
    // Note:that the loop will not execute even a single time if the loop condition starts off false.
    for (i = 0; i < 10; i++) {
         printf("i is %d\n", i);
    }

    // You can use the comma operator to do multiple things in each clause of the for loop!
    int a,b;
    for( a= 0, b = 10; a < 10 && b > 0;b--,a++){
            printf("a ia %d and b is %d\n",a,b);
    }

    // The switch Statement
    int goat_count = 2;
    switch (goat_count) { 
        case 0:
            printf("You have no goats.\n"); 
            // without break fall through will occur executing statments of
            // next case too...
            // ProTip: ALWAYS put a comment in the code where you intend to fall through
            break;
        case 1:
            printf("You have a singular goat.\n"); 
            break;
        case 2:
            printf("You have a brace of goats.\n"); 
            break;
        default:
            printf("You have a bona fide plethora of goats!\n"); 
            break;
        }
}