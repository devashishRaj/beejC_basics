#include <stdio.h>
// for atoi and strtol
#include <stdlib.h>

int main(){
   // Conversions

   //String Conversions
      //Numeric Value to String
      // convert a number to a string, we can use either sprintf() or snprintf
      char s[100];
      float f = 3.14159;
      //Convert "f" to string, storing in "s", writing at most 10 characters
      // including NULL terminator
      snprintf(s, 10,"%f",f);
      printf("String value: %s\n", s);

      //String to Numeric Value
      // we have group(s) of functions, atoi (pronounced a-to-i) family and 
      //the strtol (stir-to-long) family.
      //atoi
      //NOTE:atoi have bad error handling characterstics, bad string will lead to
      // undefined behaviour.
      char *pi = "3.14159";
      float atoi_f;
      atoi_f = atof(pi);
      printf("%f\n",f);

      //strtol
      char *strtol_s = "3490";
      char *badChar;
      // Convert string s, a number in base 10, to an unsigned long int.
      unsigned long ulx = strtoul(strtol_s, &badChar, 10) ;

      //check for error
      if (*badChar == '\0') { 
         printf("Success! %lu\n", ulx);
      }else {
         printf("Partial conversion: %lu\n", ulx); 
         printf("Invalid character: %c\n", *badChar);
      }


   // char Conversions
   /*
      0  1  2  3  4  5  6  7  8  9 
      48 49 50 51 52 53 54 55 56 57

      '5' is 53 and '0' is 48.
   */
   // we can subtract '0' from any digit character to get its numeric value:
   char c = '6';
   int x = c; // x has value 54, the code point for '6' 
   int y = c - '0'; // y has value 6, just like we want

   //we can convert the other way, too, just by adding the value on.
   int xx = 6;
   char cc = xx + '0'; //chasvalue54
   printf("%d\n", cc); // prints 54 
   printf("%c\n", cc); // prints 6 with %c

   //Numeric Conversions
    // Bool
    // If you convert a zero to bool, the result is 0. Otherwise it’s 1.

    //Integer to Integer Conversions
    //If an integer type is converted to unsigned and doesn’t fit in it, 
    //the unsigned result wraps around range of unsigned
    //if integer type is converted to a signed number and doesn’t fit, 
    //the result is implementation-defined

    // Integer and Floating Point Conversions
    //If a floating point type is converted to an integer type, 
    //the fractional part is discarded also if if the number is too large to 
    //fit in the integer, you get undefined behavior.

   // Implicit Conversions
   // if an int can be used to represent a value from char or short 
   //(signed or unsigned), that value is promoted up to int. If it doesn’t fit 
   //in an int, it’s promoted to unsigned int.

   // The Usual Arithmetic Conversions
   /*
      int types become float types if there’s a floating point type anywhere in 
      there, and the compiler makes an effort to make sure mixed integer types 
      don’t overflow.
   */
   // Mixing int and double 4.2 is converted to int
   // 4 is stored in x
   int xi = 3 + 1.2; 
   // Mixing float and int 24 is converted to float 24.0 is stored in y
   float yf = 12 * 2;

   //Explicit Conversions: conversions from type to type that you have to ask 
   //for; the compiler won’t do it for you.

   // Casting
   int x2 = 10;
   long  y2 = (long )x2 + 12;






}