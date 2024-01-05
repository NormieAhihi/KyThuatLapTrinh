#include<stdio.h>

void cubeByReference(int *Ptr); 

int main() {
	int number = 5;
	
	printf("The original value of number is %d\n", number);
	cubeByReference(&number);
	printf("The new value of number is %d\n", number); 
	 
	return 0; 
} 

void cubeByReference(int *Ptr) {
	*Ptr = *Ptr * *Ptr * *Ptr; 
}
