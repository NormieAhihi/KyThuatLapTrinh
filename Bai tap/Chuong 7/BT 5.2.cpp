// Print reverse string 
#include<stdio.h>
#include<string.h> 

int main() {
	char s[1000];
	
	printf("Nhap vao xau ki tu: ");
	gets(s); 
	printf("Xau dao nguoc la: "); 
	for(int i = strlen(s) - 1; i >= 0; i--) {
		printf("%c", s[i]); 
	} 
	printf("\n"); 
	
	return 0; 
} 

// Create reverse string 
//#include<stdio.h>
//#include<string.h> 

//int main() {
//	char s[1000], rev[1000];
	
//	printf("Nhap vao xau ki tu: ");
//	gets(s); 
//	for(int i = strlen(s) - 1; i >= 0; i--) {
//		rev[i] = s[strlen(s)-1-i]; 
//	} 
//	return 0; 
//} 

// Transform to reverse string  









