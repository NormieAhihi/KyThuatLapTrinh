#include<stdio.h>
#include<math.h>

int main() {
	int n, s=0;
	
	printf("Nhap so nguyen duong n la so chan: ");
	scanf("%d", &n); 
	 
	while(n<0 || n%2 ==1) {
		printf("Yeu cau nhap lai n thoa man dieu kien: ");
		scanf("%d", &n); 
	}
	
	for(int i = 0; i <= n/2; i++) {
		s += pow(-1, i+1) * pow(2*i, 2); 
	} 
	
	printf("\nGia tri cua tong S la: %d\n", s); 
	 
	return 0; 
} 
