#include<stdio.h>

int ucln(int a, int b); 

int main() {
	int k; 
	printf("Cac so co 2 chu so thoa man de bai la: \n"); 
	for(int i = 10 ; i <= 99; i++) {
		k = (i % 10) * 10 + i /10;
		if(ucln(i, k) == 1) {
			printf("%d ", i); 
		} 
	} 
	printf("\n"); 
	return 0; 
} 

int ucln(int a, int b) {
	while(a != b) {
		if(a > b) {
			a = a - b; 
		} 
		else {
			b = b - a; 
		} 
	} 
	if(a == b) {
		return a; 
	} 
}


