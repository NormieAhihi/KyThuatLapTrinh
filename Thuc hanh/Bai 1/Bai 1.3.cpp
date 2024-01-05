#include<stdio.h>
#include<math.h> 

int main() {
	int n, dem=0; 
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n); 
	if(n <= 1) {
		printf("\n%d khong la so nguyen to", n); 
	} else {
		for(int i = 1; i <= sqrt(n); i++) {
			if(n % i == 0) {
				dem++; 
			} 
		} 
		if(dem == 1) {
			printf("\n%d la so nguyen to", n); 
		} else {
			printf("\n%d khong la so nguyen to", n); 
		} 
	} 
	
	return 0; 
} 

