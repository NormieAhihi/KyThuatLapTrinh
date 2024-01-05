#include<stdio.h>

void displayBits(unsigned value); 

int main() {
	unsigned number1 = 960;
	
	printf("The result of left shifting \n");
	displayBits(number1);
	printf("8 bits position using the "); 
	printf("left shift operator << is\n");
	displayBits(number1 << 8);
	 
	printf("The result of right shifting \n");
	displayBits(number1);
	printf("8 bits position using the "); 
	printf("right shift operator >> is\n");
	displayBits(number1 >> 8);
	 
	return 0; 
} 

void displayBits(unsigned value) {
	unsigned c;
	unsigned displayMask = 1 << 31;
	printf("%7u = ", value);
	for(c = 1; c <= 32; c++) {
		putchar(value & displayMask ? '1' : '0');
		value <<= 1;
		
		if(c % 8 == 0) {
			putchar(' '); 
		} 
	} 
	putchar('\n'); 
}












