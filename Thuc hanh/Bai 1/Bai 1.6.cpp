#include<stdio.h>
#include<stdlib.h> 
#include<conio.h> 

int main() {
	int n, k; 
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	system("cls"); 
	
	menu: 
	printf("-----Menu-----\n");
	for(int i = 1; i <= n; i++) {
		printf("-------%d-------\n", i); 
	} 
	printf("\nNhap lua chon cua ban: ");
	scanf("%d", &k);
	
	if(k >= 1 && k <= n) {
		printf("Da chon %d\n\n", k);
		goto menu; 
	} else {
		printf("Chuong trinh ket thuc"); 
		return 0; 
	} 
	   
	return 0; 
} 
