#include<stdio.h>

void f(const int *xPtr); 

int main() {
	int y;
	
	f(&y);  
	 
	return 0; 
} 

void f(const int *xPtr) {
	*xPtr = 100; 
}
