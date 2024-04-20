// to have constant integer values by name: enum

#include <stdio.h>

int main(){

    // enums are automatically numbered unless you override them.
    enum resource {
        SHEEP, // Value is 0 
        WHEAT, // Value is 1 
        WOOD, // Value is 2 
        BRICK, // Value is 3 
        ORE // Value is 4
    } s = WOOD , P = WHEAT;
    printf("%d %d\n", SHEEP, BRICK); // 0 3

    // you can force particular values
    enum { 
        X=2,
        Y=18,
        Z=-2, 
    };

    enum {
        A, // 0, default starting value
        B, //1
        C=4, // 4, manually set
        D, //5
        E, //6
        F=3, // 3, manually set 
        G, //4
        H ,//5
    };

    // enum: they’re a type, analogous to how a struct is a type.
    // r is like S and P
    enum resource r = BRICK;
    if (r == BRICK) {
        printf("I'll trade you a brick for two sheep.\n");
    }


}