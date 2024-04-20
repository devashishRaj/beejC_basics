#include <stdio.h>
// for memcpy
#include <string.h>


int my_strlen(char *s);
int main(){
   // Pointer Arithmetic
   //adding one to the pointer moves to the next item of that type 
   //directly after it in memory.
   /*
        say that a number 3490 was stored at address (“index”) 
        23,237,489,202. If we have an int pointer to that 3490, that value of 
        that pointer is 23,237,489,202. 
        And now let’s say we have another number, 4096, stored right after the 
        3490 at address 23,237,489,210 
        (8 higher than the 3490 because each int in this example is 8 bytes long).
        If we add 1 to that pointer, it actually jumps ahead sizeof(int) bytes 
        to the next int. It knows to jump that far ahead because it’s an int 
        pointer. If it were a float pointer, it’d jump sizeof(float) bytes 
        ahead to get to the next float!
   */
   int a[6] = {11, 22, 33, 44, 55,999};
   int *p = &a[0];
   printf("%d\n",*p);
   printf("%d\n",*(p+1)) ;
   for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d\n", *(p + i)); // Same as p[i]!
   }

   // Changing Pointers
   // 999 is used as end of array 
    while (*p != 999) { 
        printf("%d\n", *p); 
        p++;
    }
    // Subtracting Pointers
    //we can also subtract two pointers to find the difference between them, e.g. 
    //we can calculate how many ints there are between two int*s.
    //  you can only use pointer subtraction between two pointers that point to the same array!
    printf("length of string is : %d\n", my_strlen("Hello, world!"));

    // Array/Pointer Equivalence
    //a[b] == *(a + b)

    char s[] = "Hello There";
    char *t = "wombats";
    printf("%d\n", my_strlen(s)); // Works! 
    printf("%d\n", my_strlen(t)); // Works, too!
    

    //void Pointers
    // it’s useful to have a pointer to a thing that you don’t know the type of.
    //this is the built-in function
    //void *memcpy(void *s1, void *s2, size_t n);
    char tt[100];
    // we can pass any type , struct is not recommended as it only does shallow copy
    memcpy(tt, s, 13);
    printf("t[] contains : %s\n", tt); 

    /*
        Limits of using void pointers 
        you cannot do operations that rely on knowing the sizeof the type of
        data pointed to, like :
        1. You cannot do pointer arithmetic on a void*. 
        2. You cannot dereference a void*. 
        3. You cannot use the arrow operator on a void*: dereference. 
        4. You cannot use array notation on a void* : dereference, 
    */
    // you can do this 
    char aa = 'X'; // A single char
    void *p2 = &aa; // p points to the 'X'
    char *q = p2; // q also points to the 'X'
    //printf("%c\n", *p2); // ERROR--cannot dereference void*! 
    printf("%c\n", *q); // Prints "X"

}
// you can even use: int my_strlen(char []s)..
int my_strlen(char*s){
    char *p = s;
    while (*p != '\0'){
        p++;
    }
    return p-s;
}