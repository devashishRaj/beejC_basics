// struct,  a user-definable type that holds multiple pieces of data, 
//potentially of different types.

//think of a struct as a class with only data members, and no methods.

#include <stdio.h>


// we are making a new type ,'struct car' not just car
struct car{
    char *name;
    float price;
    int speed;
};
//NOTE:when creating struct place widest to smallest

void set_price(struct car *c , float car_price);

int main(){
    // initialize car
    //any missing field designators are initialized to zero, in this case speed
    struct car saturn = {.speed=175, .name="Saturn SL/2"};
    printf("Name: %s\n", saturn.name); 
    printf("Price: %f\n", saturn.price); // should be zero!!!
    printf("Top Speed: %d km\n", saturn.speed);

    /*
        Passing struct to functions
        - Pass the struct.
        - Pass a pointer to the struct.
            - You need the function to be able to make changes to the struct that was passed in
            - The struct is somewhat large and it’s more expensive to copy

    */
    set_price(&saturn, 799.90);
    printf("Price %f\n",saturn.price);

    // Copying and Returning structs
    struct car awa;
    awa = saturn;
}

void set_price(struct car *c , float car_price){
    // arrow operator helps refer to fields in pointers to structs
    c->price = car_price;
    //when accessing fields
    //If you have a struct, use dot (.).
    // If you have a pointer to a struct, use arrow (->).
}