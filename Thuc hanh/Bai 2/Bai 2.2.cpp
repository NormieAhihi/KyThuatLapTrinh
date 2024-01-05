#include<stdio.h> 
#include<math.h> 

int a, b, c, d;
int ucln(int a, int b); 
void hienThi(int a, int b);

int main() {
	int e, f, g, h, i, k, l, m; 
	
	printf("Nhap vao tu so va mau so cua phan so thu nhat: ");
	scanf("%d %d", &a, &b);
	printf("Nhap vao tu so va mau so cua phan so thu hai: ");
	scanf("%d %d", &c, &d);
	
	while(b * d == 0) {
		printf("\nYeu cau nhap lai!\n\n");
		printf("Nhap vao tu so va mau so cua phan so thu nhat: ");
	    scanf("%d %d", &a, &b);
	    printf("Nhap vao tu so va mau so cua phan so thu hai: ");
	    scanf("%d %d", &c, &d);
	} 
	
	printf("\nPhan so thu nhat la: "); 
	hienThi(a, b);
	printf("\nPhan so thu hai la: "); 
	hienThi(c, d); 
	
	printf("\n\nTong cua 2 phan so la: "); 
	e = a*d+b*c;
	f = b*d;
	hienThi(e, f); 
	
	printf("\nHieu cua 2 phan so la: ");
	g = a*d-b*c;
	h = b*d;
	hienThi(g, h);
	
	printf("\n\nTich cua 2 phan so la: ");
	i = a*c;
	k = b*d;
	hienThi(i, k);
	
	if(c == 0) {
		printf("\n\nKhong ton tai thuong cua 2 phan so!"); 
	}  
	else {
		printf("\nThuong cua 2 phan so la: ");  
	l = a*d;
	m = b*c;
	hienThi(l, m); 
	} 
	printf("\n"); 
	
	return 0; 
} 

int ucln(int a, int b) {
	if(a * b == 0) {
		if(a == 0) {
			return b; 
		} else {
			return a; 
		} 
	} 
	while(a != b) {
		if(a > b) {
			a = a - b; 
		} 
		else {
			b = b - a; 
		} 
	} 
	return a; 
}

void hienThi(int a, int b) {
	int m = abs(a);
	int n = abs(b); 
	if(a * b >= 0) {
		printf("%d/%d", m/ucln(m, n), n/ucln(m, n)) ; 
	} 
	else {
		printf("-%d/%d", m/ucln(m, n), n/ucln(m, n)); 
	} 
} 









