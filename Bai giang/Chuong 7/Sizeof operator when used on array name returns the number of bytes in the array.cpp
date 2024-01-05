#include<stdio.h>

size_t getSize (float *ptr); 

int main() {
	float array[20];
	
	printf("The number of bytes in the array is %d"
	       "\nThe number of bytes returned by getSize is %d\n",
		   sizeof(array), getSize(array)); 

	return 0; 
} 

size_t getSize (float *ptr) {
	return sizeof(ptr); 
}
