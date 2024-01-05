#include<stdio.h>
#include<math.h> 

int ucln(int x, int y); 

int main() {
	int x, y;
	
	printf("Nhap vao 2 so nguyen duong: ");
	scanf("%d %d", &x, &y);
	printf("\nUoc chung lon nhat cua %d va %d la: %d\n", x, y, ucln(x, y)); 
	
	return 0; 
} 

int ucln(int x, int y) {
	if(x == 0) {
		return y; 
	} else {
		if(y == 0) {
			return x; 
		} else {
		if(x > y) {
			return ucln(x % y, y); 
		} else {
			return ucln(x, y % x); 
		} 
	} 
	} 
	
}
