// typedef: Making New Types
//you take an existing type and you make an alias for it with typedef.
//typedef are declared file scope (“global”) so all functions can use it.

//typedef and structs
struct animal { 
    char *name;
    int leg_count, speed;
};

// orignal name ,      new name
typedef struct animal animal;

// a common practice for typedef and structs
typedef struct animal2 {
char *name;
int leg_count, speed; } animal2;

// you can also use anonymous structs
typedef struct  {
char *name;
int leg_count, speed; } animal3;

int main(){
    struct animal y ; // this works 
    animal z; // this too
    animal2 xx; // works as above
    animal3 yy;

    //typedef and Other Types
    //it helps you abstract the types to make it easier to change them later.
    typedef float app_float;
    // you can change to double just by : typedef long double app_float;
    app_float f1, f2, f3;

    //typedef and Pointers
    //NOTE:not recommended as it's better to have clear code that we are using 
    //pointers.
    typedef int *intptr;
    int a = 10;
    intptr x = &a; // "intptr" is type "int*"

    //Arrays and typedef
    // not recommeded as it hides the array nature of the variable
    // Make type five_ints an array of 5 ints
    typedef int five_ints[5];
    five_ints xarr = {11, 22, 33, 44, 55};
    
}
