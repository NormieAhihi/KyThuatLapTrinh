#include<stdio.h>

int f(int x, int n);
int s(int n); 

int main() {
	int x, n;
	
	printf("Nhap vao gia tri cua x va n: ");
	scanf("%d %d", &x, &n);
	while(n < 0) {
		printf("Nhap lai gia tri cua n: ");
		scanf("%d", &n); 
	} 
	printf("\nf(%d, %d) = %d\n", x, n, f(x, n)); 
	printf("s(%d) = %d\n", n, s(n)); 
	return 0; 
} 

int f(int x, int n) {
	if(n == 0) {
		return 1; 
	} else {
		return x * f(x, n - 1); 
	} 
}

int s(int n) {
	if(n == 0) {
		return 1; 
	} else {
		return s(n-1) * (2 * n - 1) * (2 * n);  
	} 
}






