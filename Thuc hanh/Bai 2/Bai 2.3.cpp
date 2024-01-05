#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 100
#define MAX_WORDS 20

void normalizeString(char *str);
void searchPattern(char arr[][100], int n, char* pattern);
int countWords(char *str);

int main() {
    int n;
    char A[MAX_WORDS][MAX_LENGTH];
    char P[MAX_LENGTH];

    printf("Nhap so luong xau: ");
    scanf("%d", &n);
    getchar(); 
    printf("\n"); 

    printf("Nhap cac xau:\n");
    for(int i = 0; i < n; i++) {
        fgets(A[i], sizeof(A[i]), stdin);
    }
    
    printf("\nCac xau trong mang A:\n");
    for(int i = 0; i < n; i++) {
        printf("%s", A[i]);
    }

    printf("\nNhap xau mau P: ");
    fgets(P, sizeof(P), stdin);
    for(int i = 0; i < n; i++) {
    	normalizeString(A[i]);
    }
    normalizeString(P);
    searchPattern(A, n, P);
    
    printf("\nCac xau trong mang A sau khi chuan hoa:\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", A[i]);
    }
    
    printf("\nSo luong tu trong moi xau cua mang la: \n");
	for(int i = 0; i < n; i++) {
        printf("Xau thu %d: %d\n", i + 1, countWords(A[i]));
    }
    
    return 0; 
}

void searchPattern(char arr[][100], int n, char* pattern) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(arr[i], pattern) != NULL) {
            printf("Xau P xuat hien trong xau thu %d cua mang A\n", i + 1);
            printf("Vi tri bat dau xuat hien xau P: %ld\n", strstr(arr[i], pattern) - arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Xau P khong xuat hien trong mang A\n");
    }
}

void normalizeString(char *str) {
    int length = strlen(str);
    
    // Loai bo cac dau cach o dau xau
    while(str[0] == ' ') {
        for(int i = 0; i < length; i++) {
            str[i] = str[i + 1];
        }
        length--;
    }
    
    // Loai bo cac dau cach o giua xau  
    for(int i = 0; i < length - 1; i++) {
        if(str[i] == ' ' && str[i + 1] == ' ') {
            for(int j = i; j < length; j++) {
                str[j] = str[j + 1];
            }
            i--;
            length--;
        }
    }

    // Loai bo cac dau cach o cuoi xau
    while(length > 0 && isspace(str[length - 1])) {
        str[length - 1] = '\0';
        length--;
    }

    int capitalizeNext = 1; // Bien danh dau chu hoa dau tien cua tu ke tiep

    for(int i = 0; i < length; i++) {
        if(isspace(str[i])) {
            capitalizeNext = 1; // Gap dau cach, chuan bi chu hoa cho tu tiep theo
        } else {
            if(capitalizeNext) {
                str[i] = toupper(str[i]); // Chuyen chu cai dau tien cua tu thanh chu hoa
                capitalizeNext = 0;
            } else {
                str[i] = tolower(str[i]); // Chuyen chu cai con lai thành chu thuong
            }
        }
    }
}

int countWords(char *str) {
    int count = 0;
    int i;
    int length = strlen(str);
    int isWord = 0;

    for(i = 0; i < length; i++) {
        if(isalpha(str[i])) {
            if(!isWord) {
                count++;
                isWord = 1;
            }
        } else {
            isWord = 0;
        }
    }

    return count;
} 


    

