// manual memory allocation
// local variables(automatic vars): are automatically allocated and deallocated
// when they come into scope and leave scope.

//You can tell C explicitly to allocate for you a certain number of bytes 
//that you can use as you please
//NOTE:If you manually allocated it, you have to manually free it when you’re done with it.

//Allocating and Deallocating, malloc() and free()
#include <stdio.h>
// malloc and free ...
#include <stdlib.h>
// for memset
#include <string.h>
int main(){
    //malloc() function accepts a number of bytes to allocate, and returns a 
    //void pointer to that block of newly-allocated memory.
    //Since it’s a void*, you can assign it into whatever pointer type you want
    int *x;
    if ((x = malloc(sizeof(int) * 10)) == NULL) {
    printf("Error allocating 10 ints\n");
    }   

    // Allocating Space for an Array
    //there’s no initialization done on the newly-allocated memory—it’s 
    //full of garbage. Clear it with memset() or use calloc()

    // Allocate space for 10 ints with calloc(), initialized to 0:
    int *p = calloc(10, sizeof(int));

    // Allocate space for 10 ints with malloc(), initialized to 0:
    int *q = malloc(10 * sizeof(int));
    memset(q, 0, 10 * sizeof(int)); // set to 0 


    //Changing Allocated Size with realloc()
    float *f = malloc(sizeof(float)*20);
    for(int i = 0; i < 20;i++){
        // 20.0 to get result in float
        f[i] = i/20.0;
    }
    float *new_f ;
    if ((new_f = realloc(p, sizeof(p)*40)) == NULL) {
        printf("Error reallocing\n"); 
        return 1;
    }else {
        f = new_f;
    }
    for (int i = 20; i < 40; i++){
        f[i] = 1.0 + (i - 20) / 20.0;
    }
    // Print all values 0.0-2.0 in the 40 elements:
    for (int i = 0; i < 40; i++){
        printf("%f\n", f[i]);
    }
    free(f);

    /*
        Realloc use case:
        Reading in Lines of Arbitrary Length
        - Use of realloc() to grow a buffer as we read in more data.
        - Use of realloc() to shrink the buffer after we’ve completed the read.
    */

    //realloc() with NULL
    // they both are quivalent
    char *n = malloc(3490);
    char *n2 = realloc(NULL, 3490);
    // usecase 
    int *l = NULL; int length = 0;
    int done = 0;
    while (!done) {
        // Allocate 10 more ints:
        length += 10;
        l = realloc(l, (sizeof (*l))* length);
        // Do work unitll done condition trigger
        done = 1;
    }

    //Aligned Allocations
    //if you use malloc(), calloc(), or realloc(), C will give you a chunk of 
    //memory that’s well-aligned for any value at all, even structs. 
    // but in embedded programming there be times that you know that some data 
    //can be aligned at a smaller boundary, or must be aligned at a large
    // Allocate 256 bytes aligned on a 64-byte boundary 
    char *allign_p = aligned_alloc(64, 256); // 256 == 64 * 4

    //NOTE:when creating struct place widest to smallest
}