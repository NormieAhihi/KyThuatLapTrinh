#include<stdio.h>

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x = 1; 

int main() {
	int x = 5;
	
	printf("local x in outer scope of main is %d\n", x);
	
	{
		int x = 7;
	    printf("local x in inner scope of main is %d\n", x);
	} 
	
	printf("local x in outer scope of main is %d\n", x);
	
	useLocal();
	useStaticLocal();
	useGlobal(); 
	useLocal();
	useStaticLocal();
	useGlobal(); 
	
	printf("local x in main is %d\n", x); 
	 
	return 0; 
} 

void useLocal(void) {
	int x = 25;
	
	printf("\nlocal x in a is %d after entering a\n", x);
	x++;
	printf("local x in a is %d before enxiting a\n", x);
}

void useStaticLocal(void) {
	static int x = 50;
	
	printf("\nlocal static x in b is %d on entering b\n", x);
	x++;
	printf("local static x in b is %d on enxiting b\n", x);

}

void useGlobal(void) {
	printf("\nglobal x in c is %d on entering c\n", x);
	x *= 10; 
	printf("global x in c is %d on enxiting c\n", x);
}







