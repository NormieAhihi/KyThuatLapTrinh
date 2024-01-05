#include<stdio.h>
#include<math.h> 
 

int main() {
	int x, y; 
	
	printf("Nhap vao gia tri cua 2 so nguyen duong: ");
	scanf("%d %d", &x, &y);
	printf("\nUoc chung lon nhat cua %d va %d la: %d\n", x, y, gcd(x, y)); 
	 
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

