#include<stdio.h>

int maximum(int x, int y, int z); 

int main() {
	int number1, number2, number3;
	
	printf("Enter three intergers: ");
	scanf("%d %d %d", &number1, &number2, &number3);
	printf("Maximum is: %d\n", maximum(number1, number2, number3)); 
	
	return 0; 
} 

int maximum(int x, int y, int z) {
	int max = x;
	
	if(y > max) {
		max = y; 
	} 
	if(z > max) {
		max = z; 
	} 
	return max; 
}


