#include<stdio.h>

int m, n, p , q;
int A[1000][1000];
int B[1000][1000];
void importMatrix(); 
void printMatrix();
void addMatrix();
void multipleMatrix(); 
int sum(int i, int j); 

int main() {
	importMatrix();
	printMatrix();
	addMatrix();
	multipleMatrix(); 

    return 0; 
}

void importMatrix() {
	printf("Nhap vao kich thuoc ma tran A: ");
	scanf("%d %d", &m, &n);
	printf("Nhap vao cac phan tu cua ma tran A: ");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]); 
		} 
	} 
	printf("Nhap vao kich thuoc ma tran B: ");
	scanf("%d %d", &p, &q);
	printf("Nhap vao cac phan tu cua ma tran B: ");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < q; j++) {
			scanf("%d", &B[i][j]); 
		} 
	} 
}

void printMatrix() {
	printf("\nMa tran A:\n");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", A[i][j]); 
		} printf("\n"); 
	} 
	printf("Ma tran B:\n");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < q; j++) {
			printf("%d ", B[i][j]); 
		} printf("\n"); 
	} 
}

void addMatrix() {
	if(m == p && n == q) {
		printf("\nTong cua 2 ma tran la:\n"); 
	    for(int i = 0; i < p; i++) {
		    for(int j = 0; j < q; j++) {
			    printf("%d ", A[i][j] + B[i][j]); 
		    } printf("\n"); 
	    } 
	} else {
		printf("\nKhong the cong 2 ma tran!"); 
	} 
}

int sum(int i, int j) {
	int s = 0;
	for(int k = 0; k < n; k++) {
		s += A[i][k] * B[k][j]; 
	} 
	
	return s; 
}

void multipleMatrix() {
	if(n == p) {
		printf("\nTich cua 2 ma tran la:\n"); 
		for(int i = 0; i < p; i++) {
		    for(int j = 0; j < q; j++) {
			    printf("%d ", sum(i, j)); 
		    } printf("\n"); 
	    } 
	} else {
		printf("\nKhong the nhan 2 ma tran!"); 
	} 
}

