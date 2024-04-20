#include <float.h>
#include <stdio.h>
#include <limits.h>

int main(){
    // Signed and Unsigned Integers
    //IMPORTANT:unsigned integer types that can only hold positive numbers.
    int a; // signed
    signed sa; // signed , you can also do signed int sa;
    unsigned ua; // unsigned, unsigned int ua; will work too

    //char is just a small int, namely an integer that uses 
    //just a single byte of space
    char c; // Could be signed or unsigned 
    signed char sc; // Definitely signed
    unsigned char uc; // Definitely unsigned
    //your character set is based on ASCII5 for at least the first 128 characters.
    char ca = 10; 
    char cb = 20; 
    char bB = 'B';
    printf("%d\n", ca + cb); // 30!
    printf("%d\n",ca+bB);

    //More Integer Types: short, long, long long
    /*
        //NOTE:The header file <limits.h> defines macros that hold the minimum 
        and maximum integer values; rely on that to be sure, and never hardcode 
        or assume these values.
    */
    // these a signed by default
    short sx;
    long lx;
    long long llx;
    printf("CHAR_MIN %d CHAR_MAX %D\nSCHAR_MIN %d SCHAR_MAX %d\n",
    CHAR_MIN,CHAR_MAX,SCHAR_MIN,SCHAR_MAX);
    //there’s no minimum macro for the unsigned variants—they’re just 0.
    printf("unsigned long long range is %llu \n",ULLONG_MAX);

    //More Float: double and long double
    //FLT_DIG tells you how many significant digits you can rely on when working
    //with float numbers, while FLT_DECIMAL_DIG tells you how many digits are 
    //needed to accurately represent any float value without loss of precision.
    printf("Number of decimal digits of precision in float: %d\n", FLT_DIG);
    printf("Number of decimal digits of precision in double: %d\n", DBL_DIG);
    printf("Number of decimal digits of precision in long double: %d\n", LDBL_DIG);
    printf("Number of decimal digits required to represent a float: %d\n", FLT_DECIMAL_DIG);

    //Constant Numeric Types
    int hex_a = 0x1A2B; // Hexadecimal
    int hex_b = 0x1a2b; // Case doesn't matter for hex digits
    int ocatal_a = 012;
    printf("%o\n", a); // Print an octal number, "12"

    // don't be stupid and do these kind padding for representation
    int x = 11111; // Decimal 11111
    int y = 00111; // Decimal 73 (Octal 111) 
    int z = 01111; // Decimal 585 (Octal 1111)

    //A Note on Binary
    int Binary_x = 0b101010; 
    // Binary 101010 
    //There’s no printf() format specifier for printing a binary number. 
    //You have to do it a character at a time with bitwise operators
    printf("%d\n", x); // Prints 42 decimal

    //Integer Constants
    //force a constant integer to be a certain type by appending a suffix to it 
    //that indicates the type
    int i = 1234; 
    long int li = 1234L; 
    long long int lli = 1234LL;
    unsigned int ui = 1234U; 
    unsigned long int uli = 1234UL; 
    unsigned long long int ulli = 1234ULL;
    //C will generally do is choose the smallest type from int up that can hold the value.
    int what_type= 1234;
    // similarly you have flaoting point constants.
    float f = 3.14f; double df = 3.14; long double ldf = 3.14L;

    //Scientific Notation
    //Writing numbers in the form 𝑠 × 𝑏𝑒 is called scientific notation
    // 1.2345 × 10−3 = 0.0012345 : 1.2345e-3
    printf("%e\n", 123456.0); // Prints 1.234560e+05
    // You can apply the F or L suffixes to E-notation constants
    //1.2345e10L or 1.2345e10F

}

