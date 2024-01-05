#include<stdio.h>

int gcd(int a, int b);

int main() {
	int x, y;
	
	printf("Nhap vao tu so va mau so: ");
	scanf("%d %d", &x, &y);
	if(gcd(x, y) == 1) {
		printf("\nPhan so la toi gian"); 
	} else {
		printf("\nPhan so chua toi gian\nPhan so toi gian la: %d/%d\n", x/gcd(x, y), y/gcd(x, y)); 
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

