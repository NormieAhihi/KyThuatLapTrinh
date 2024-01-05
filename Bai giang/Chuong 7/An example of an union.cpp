#include<stdio.h>

union number {
	int x;
	double y; 
}; 

int main() {
	union number value;
	value.x = 100;
	
	printf("%s\n%s\n%s%d\n%s%f\n\n",
	       "Put a value in the integer member",
		   "and print both members.",
		   "int:   ", value.x, 
		   "double: \n", value.y); 
	
	value.y = 100.0;
	printf("%s\n%s\n%s%d\n%s%f\n\n",
	       "Put a value in the floating member",
		   "and print both members.",
		   "int:   ", value.x, 
		   "double: \n", value.y); 
	
	return 0; 
} 
