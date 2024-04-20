// strings aren’t actually strings in C. That’s right! They’re pointers
// string literals in C, are sequences of characters in double quotes (").
// like: "Hello, world!\n" 
//or "When asked if this string had quotes in it, she replied, \"It does.\""
// '\' is escape sequence to tell compiler ignore the preceding char...

#include <stdio.h>
// to use strlen and strcpy
#include <string.h>


// user-defined strlen function 
int my_strlen(char *s);
int main(){

    // In C, a “string” is defined by two basic characteristics:
    // - A pointer to the first character in the string.
    // - A zero-valued byte (or NUL character3) somewhere in memory after the 
    //  pointer that indicates the end of the string. 
    // A NUL character can be written in C code as \0
    // When you include a string in double quotes in your code, 
    // the NUL character is automatically, implicitly included.


    //pointer to first char in string , this is a string literal
    char *s = "Hello World\n"; // Actually "Hello World\0\n" behind the scenes
    // we can with %s
    printf("%s",s);

    // string variables as arrays, NOTE: this is not a string literal
    char sArr[] = "Hello";
    for(int i= 0; i < 5; i++){
        // use can even use s[i] here 
        printf("%c",sArr[i]);
    }
    printf("\n");
    //or just use %s
    printf("or just use %%s for %s\n",sArr);

    // mutate string
    // you can mutate string literal delcared as pointer to first char
    // s[3] = "i"; // undefined behaviour
    // but you can mutate string declared as an array
    sArr[3]='i';

    // Getting String Length
    printf("The string is %zu bytes long.\n", strlen(s));
    printf("Length of string is : %d \n", my_strlen(s));


    //Copying a String
    char *t;
    t = sArr;// this makes copy of the pointer not the string
    t[3]='l';
    printf("%s\n", sArr);

    // using strcpy
    //NOTE:There’s a safer function called strncpy()
    char tArr[100];
    strcpy(tArr,sArr);
    printf("%s\n", tArr);


}

int my_strlen(char *s){
    int count = 0;
    while (s[count]!= '\0') {
        count++;
    }
    return count;
}