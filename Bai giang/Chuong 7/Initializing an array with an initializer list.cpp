#include<stdio.h> 

int main() {
	int n[10] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};
	
	printf("%s%13s\n", "Element", "Value");
	for(int i = 0; i < 10; i++) {
		printf("%4d%15d\n", i, n[i]); 
	} 
	
	return 0; 
} 
