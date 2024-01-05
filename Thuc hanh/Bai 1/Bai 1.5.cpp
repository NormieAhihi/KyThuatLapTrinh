#include<stdio.h>
#include<stdlib.h>

bool isPrime(int n);

int main() {
    int n, count = 0; 
    int *primeArray = (int *)malloc(n * sizeof(int)); 
    
    printf("Nhap vao gia tri cua n: ");
    scanf("%d", &n);

    if (primeArray == NULL) {
        printf("Khong the cap phat bo nho!");
        return 1;
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primeArray[count] = i;
            count++;
        }
    }

    printf("\nCac so nguyen to nho hon hoac bang %d la:\n", n);
    for (int i = 0; i < count; i++) {
        printf("%d ", *(primeArray + i));
    }
    printf("\n"); 
    
    free(primeArray);

    return 0;
}

bool isPrime(int n) {
    if(n < 2) {
    	return false;
	}
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
        	return false;
		}
    }
}



