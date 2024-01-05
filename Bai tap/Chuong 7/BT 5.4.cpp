#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 

int m, n, p , q, r, op; 
int* A = NULL; 
int* B = NULL;

void importOneMatrix(); 
void importTwoMatrix(); 
void importMatrixAndNumber(); 
void printOneMatrix();
void printTwoMatrix(); 
void addMatrix();
void multipleTwoMatrix();
void multipleMatrixAndNumber();
void transpositionMatrix(); 

int sum(int i, int j); 

int main() {
    
    A = (int *)malloc(m * n * sizeof(int));
    
    B = (int *)malloc(p * q * sizeof(int));
    
	menu: 
	printf("--------------------<<MENU>>--------------\n");
	printf("--- (1): Hien thi ma tran              ---\n");
	printf("--- (2): Cong 2 ma tran                ---\n"); 
	printf("--- (3): Nhan 2 ma tran                ---\n"); 
	printf("--- (4): Tich vo huong 1 so va ma tran ---\n"); 
	printf("--- (5): Tim ma tran chuyen vi         ---\n"); 
	printf("--- (6): Ket thuc chuong trinh         ---\n"); 
	printf("------------------------------------------\n\n"); 
	printf("Nhap vao lua chon cua ban: ");
	scanf("%d", &op);
	system("cls");
	
	switch(op) {
		case 1:
			importOneMatrix();
			printOneMatrix();
			getch(); 
			system("cls"); 
			goto menu; 
		case 2:
			importTwoMatrix();
			printTwoMatrix(); 
			addMatrix();
			getch(); 
			system("cls"); 
			goto menu; 
		case 3:
			importTwoMatrix();
			printTwoMatrix(); 
			multipleTwoMatrix();
			getch(); 
			system("cls"); 
			goto menu; 
		case 4:
			importMatrixAndNumber();
			printOneMatrix(); 
			multipleMatrixAndNumber();
			getch(); 
			system("cls"); 
			goto menu; 
		case 5:
			importOneMatrix();
			printOneMatrix(); 
			transpositionMatrix();
			getch(); 
			system("cls"); 
			goto menu; 
		case 6:
		    printf("Ket thuc chuong trinh!\n");
			break; 
		default: 
		    printf("Yeu cau nhap lai lua chon!\n");
		    getch();
			system("cls"); 
		    goto menu; 
	}  

    return 0; 
}

void importOneMatrix() {
	printf("Nhap vao kich thuoc ma tran A: ");
	scanf("%d %d", &m, &n);
	printf("Nhap vao cac phan tu cua ma tran A: ");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
		    scanf("%d", (A + i * (m + 1) + j));
		} 
	} 
	printf("\n"); 
}

void importTwoMatrix() {
	printf("Nhap vao kich thuoc ma tran A: ");
	scanf("%d %d", &m, &n);
	printf("Nhap vao cac phan tu cua ma tran A: ");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", (A + i * (m + 1) + j)); 
		} 
	}  
	printf("Nhap vao kich thuoc ma tran B: ");
	scanf("%d %d", &p, &q);
	printf("Nhap vao cac phan tu cua ma tran B: ");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < q; j++) {
			scanf("%d", (B + i * (p + 1) + j));
		} 
	} 
}

void importMatrixAndNumber() {
	printf("Nhap vao so r: ");
	scanf("%d", &r); 
	printf("Nhap vao kich thuoc ma tran A: ");
	scanf("%d %d", &m, &n);
	printf("Nhap vao cac phan tu cua ma tran A: ");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", (A + i * (m + 1) + j));
		} 
	} printf("\n"); 
}

void printOneMatrix() {
	printf("Ma tran A:\n");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", *(A + i * (m + 1) + j)); 
		} printf("\n"); 
	} 
	printf("\n");
}

void printTwoMatrix() {
	printf("\nMa tran A:\n");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", *(A + i * (m + 1) + j)); 
		} printf("\n"); 
	}  
	
	printf("\nMa tran B:\n");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < q; j++) {
			printf("%d ", *(B + i * (p + 1) + j)); 
		} printf("\n"); 
	} 
	printf("\n");
} 

void addMatrix() {
	if(m == p && n == q) {
		printf("Tong cua 2 ma tran la:\n"); 
	    for(int i = 0; i < p; i++) {
		    for(int j = 0; j < q; j++) {
			    printf("%d ", *(A + i * (p + 1) + j) + *(B + i * (p + 1) + j)); 
		    } printf("\n"); 
	    } 
	} else {
		printf("Khong the cong 2 ma tran!\n"); 
	}  
}

int sum(int i, int j) {
	int s = 0;
	for(int k = 0; k < n; k++) {
		s += *(A + i * (m + 1) + k) * *(B + k * (p + 1) + j); 
	} 
	return s; 
}

void multipleTwoMatrix() {
	if(n == p) {
		printf("Tich cua 2 ma tran la:\n"); 
		for(int i = 0; i < m; i++) {
		    for(int j = 0; j < q; j++) {
			    printf("%d ", sum(i, j)); 
		    } printf("\n"); 
	    } 
	} else {
		printf("Khong the nhan 2 ma tran!");  
	} 
    printf("\n"); 
}

void multipleMatrixAndNumber() {
	printf("Tich cua ma tran A voi so r la:\n"); 
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", r * *(A + i * (m + 1) + j)); 
		} printf("\n"); 
	} 
	printf("\n"); 
}

void transpositionMatrix() {
	printf("Ma tran chuyen vi cua ma tran A la:\n"); 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", *(A + j * (m + 1) + i)); 
		} printf("\n"); 
	} 
	printf("\n");
}










