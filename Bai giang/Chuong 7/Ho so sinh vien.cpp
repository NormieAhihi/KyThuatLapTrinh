#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct hoso {
	char ten[30];
	char que[50];
	long dt; 
} sinhvien[150];

typedef struct hoso Hoso;
Hoso *ph;

void Nhaphoso(Hoso *psv, int *ts);
void Inhoso(Hoso ph[], int n);
void Timkiem(Hoso ph[], int n);

int main() {
	int n;
	system("cls");
	ph = sinhvien;
	Nhaphoso(ph, &n);
	system("cls");
	Inhoso(ph, n);
	getch();
	system("cls"); 
	Timkiem(ph, n);
	getch();
	
	return 0; 
} 

void Nhaphoso(Hoso *psv, int *ts) {
	int i, n;
	printf("Vao tong so sinh vien: ");
	scanf("%d", &n);
	fflush(stdin);
	for(i = 0; i < n; i++) {
		printf("Sinh vien thu : %d\n", i+1); 
		printf("Vao ten: "); 
		gets(psv[i].ten);
		fflush(stdin); 
		printf("Vao que quan: "); 
		gets(psv[i].que);
		fflush(stdin); 
		printf("Vao so dien thoai: "); 
		scanf("%ld", &psv[i].dt);
		fflush(stdin); 
		printf("\n"); 
	} 
	*ts = n; 
}

void Inhoso(Hoso ph[], int n) {
	int i;
	printf("%4c%20s%15s\n", 'i', "Ten sinh vien", "Dien thoai");
	for(i = 0; i < n; i++) {
		printf("%4d%15s%17ld\n", i+1, ph[i].ten, ph[i].dt); 
	} 
}

void Timkiem(Hoso ph[], int n) {
	int i = 0;
	char tensv[30];
	printf("Vao ten sinh vien can tim: ");
	scanf("%s", tensv);
	while(i < n) {
		if(strcmp(ph[i].ten, tensv) == 0) {
			break; 
		} i++; 
	} 
	if(i < n) {
		printf("Tim thay sinh vien: %s\n", ph[i].ten);
		printf("Que quan cua sinh vien: %s\n", ph[i].que);
		printf("So dien thoai cua sinh vien: %lu", ph[i].dt);
	} else {
		printf("Khong tim thay sinh vien: %s", tensv); 
	} 
}












