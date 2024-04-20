#include <stdio.h>
#include <stdbool.h>

int main(void){
	// i is unintialised right now , thus it might hold 0 or any garbage value 
	// that was already stored at memory address given to i
	int i; // holds signed integer : 3 , -2...
	// it's better to initialise variables before usign them 
	i = 2;
	float f; // holds signed floating points : 3.12 , -435.23432
	f = 3.12;
	char *s = "Hello World!";
	// prints get two argument first is what to print and how to print
	// second part is what values to print:
	// %s is format specifier telling to print string, %d for int and %f for float
	// the order of format specifer in first args and  order of values mentioned
	// should match for giving output in right format.
	printf("%s i = %d and f = %f!\n",s,i,f);
	// boolean types in C : 0 is false and non-zero(1 ,99,-999) are true
	int x = 1;
	if (x){printf("x is true\n");}
	// via stdbool.h , you get access to namely a bool type and true and false values
	// under the hood these still int values for used to look nice in codebase
	bool y = true;
	if (y){
		printf("Y is true\n");
	}
}


