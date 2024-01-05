#include<stdio.h>
#include<stdlib.h> 

void solve(); 

int main() {
	int a, b, c, d, e, f;
	
	printf("Nhap vao gia tri cua a, b, c: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("Nhap vao gia tri cua d, e, f: ");
	scanf("%d %d %d", &d, &e, &f);
	system("cls"); 
	
	printf("\nHe phuong trinh: \n");
	printf("%dx + %dy = %d\n", a, b, c);
	printf("%dx + %dy = %d\n", d, e, f);
	system("cls"); 
	 
	solve(); 
	 
	return 0; 
} 

void solve() {
	int a, b, c, d, e, f; 
	int detA = a * e - b * d;
	int detA1 = c * e - b * f;
	int detA2 = a * f - c * d;
	
	if(detA != 0) {
		printf("He phuong trinh co nghiem duy nhat: \n");
		printf("x = %d\n", detA1 / detA);
		printf("y = %d", detA2 / detA);
	} else {
		if(d == 0) {
			if(a == 0) {
				if(c == f) {
					printf("He phuong trinh co vo so nghiem (x, c)"); 
				} else {
					printf("He phuong trinh vo nghiem"); 
				} 
			} else {
				if(f == 0) {
					printf("He phuong trinh co vo so nghiem (x, y)"); 
				} else {
					printf("He phuong trinh vo nghiem"); 
				} 
			} 
		} else {
			if(a * f == c * d) {
				printf("He phuong trinh co vo so nghiem (x, y)"); 
			} else {
				printf("He phuong trinh vo nghiem"); 
			} 
		} 
	} 
}






