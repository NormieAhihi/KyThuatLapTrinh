#include<stdio.h>

int gcd(int x, int y);

int main() {
	int x, y;
	
	printf("Nhap vao 2 so tu nhien: ");
	scanf("%d %d", &x, &y); 
	if(gcd(x, y) == 1) {
		printf("\n%d va %d la 2 so nguyen to cung nhau\n", x, y); 
	} else {
		printf("\n%d va %d khong nguyen to cung nhau\n", x, y); 
	} 
	
	return 0; 
} 

int gcd(int a, int b) {
	while(a != b) {
		if(a > b) {
			a = a - b; 
		} else {
			b = b - a; 
		} 
	} 
	
	return a; 
}

