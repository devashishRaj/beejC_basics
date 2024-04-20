#include <stdio.h>

void increment(int *p);

int main(){
    int i = 10;
    // (void *) part is casting the result of &i to a void pointer. 
    // This is necessary because %p expects a pointer to void type.
    //a common practice when you want to work with pointers to memory locations 
    // without specifying a particular data type. 
    // address printed on console will be in hexadecimal format.
    printf("address of  i is %p\n",(void *)&i);
    printf("the value of i is %d\n",i);

    // pointer type
    // a pointer to type int , a pointer to int or int-pointer.
    //That is, it can hold the address of other ints.
    int *p;
    // we use the address-of operator (which happens to be an ampersand: “&”)
    //to find the address of the data.
    p = &i;

    // Dereferencing
    // you can use the original variable through the pointer by dereferencing the pointer.
    // by  indirection operator, asterisk '*'
    *p = 20; // now value of i is 20;
    printf("value of i %d and when dereferencing pointer pointing to i %d\n",i,*p);

    // Passing Pointers as Arguments
    //NOTE:EVERY SINGLE ARGUMENT gets copied into parameters and the function 
    //uses a copy of the argument
    // but by passing pointer(s), the function can dereference its copy of the 
    // pointer to get back to the original variable!
    // it's like address of house on one papere and then copying it onto another 
    // paper both are equally good for finding the house.
    printf("Value of i before increment %d\n",*p);
    // we need to pass the address , we could have used: increment(p); too
    // but what pointer p can be reassigned which is advantage or disadvantage 
    // depending on requirement of the program.
    increment(&i);
    printf("value after increment %d\n",*p);

    // The NULL Pointer
    // pointer doesn’t point to anything.
    int *k = NULL;
    // dereferencing it is undefined behavior, and probably will result in a crash:
    // *k = 11 ; 

    // sizeof pointer 
    // p is type 'int *', so prints size of 'int*'
    printf(" size of int pointer %zu\n", sizeof(p));
}

void increment(int *p){
    *p +=1;
}