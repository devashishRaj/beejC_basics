// arrays are just syntactic sugar in C—they’re actually all pointers and stuff deep down.

#include <stdio.h>

// you can use constant expression to declare array size too.
#define COUNT 11

//Passing Single Dimensional Arrays to Functions
// all three are identical but first one is most common
void times2(int *a, int len);
void times3(int a[], int len) ;
void times4(int a[5], int len);

// passing multidimensional array to functions
// In general, it needs to know all the dimensions except the first one.
// so it can figure out how far in memory to skip for each increment of the first dimension.
void print_2D_array(int a[2][3]) ;
void print_2D_array(int a[][3]);

int main(void){
    float f[4]= {0};
    f[0] = 122;
    f[1]  = 222;
    f[2] = 354;
    f[3]= 576;
    for(int i = 0; i < 4;i++){
        printf("f[%d] is %f\n",i,f[i]);
    }

    printf("length of f is %zu\n",(sizeof(f)/sizeof(f[0])));
    //NOTE:when you “pass” arrays to functions, you’re only passing a pointer to the first element

    // you can also intializse array with inserting element from particular index
    // where remaning elements get's zero value as per data type
    int a[10]={1,2,3,[7]=7,8};
    for(int i = 0; i < 10;i++){
        printf("a[%d] is %d\n",i,a[i]);
    }
     printf("length of a is %zu\n",(sizeof(a)/sizeof(a[0])));

    int c[COUNT];

    //NOTE:C doesn’t stop you from accessing arrays out of bounds. It might not even warn you.
    // this can lead to garabage values or mostly crashing .


    //Multidimensional Arrays
    // These are stored in memory in row-major order, the first index listed 
    //indicates the row, and the second the column.

    int x[2];
    int y[2][3];// two rows and three columns
    int z[4][5][6];
    //you can initialize with explicit indexes:
    // make a 3x3 identity matrix
    int idm[3][3] = {[0][0]=1,[1][1]=1,[2][2]=1};
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%d ",idm[row][col]);
        }
        printf("\n");
    }


    // Arrays and Pointers
    // Generally speaking, when a C programmer talks about a pointer to an array
    // they’re talking about a pointer to the first element of the array.
    int *p;
    p = x; // is same as p = &x[0];
    // to assiging pointer to multidimensional array , you need to provide
    // dimensions expect first one
    int (*pp)[3];
    pp = y;
    int (*ppp)[5][6];
    ppp = z;

    //Passing Single Dimensional Arrays to Functions 
    // as we are passing a pointer to the first element in the array.
    // we can make changes that will be applicable to orignal array
    times2(a, 10);


    // Passing Multidimensional Arrays to Functions
    int xx[2][3] = { 
        {1, 2, 3},
        {4, 5, 6} 
    };
    print_2D_array(xx);
}

void times2(int *a, int len) {
    for (int i = 0; i < len; i++){ 
        a[i] = a[i]*2;
        printf("%d\n", a[i]);
    }
}

void print_2D_array(int a[][3]) {
    printf("\nPrinting 2d array of size [][3]\nß");
    for (int row = 0; row < 2; row++) { 
        for (int col = 0; col < 3; col++){
            printf("%d ", a[row][col]); 
        }
        printf("\n");
    } 
}
