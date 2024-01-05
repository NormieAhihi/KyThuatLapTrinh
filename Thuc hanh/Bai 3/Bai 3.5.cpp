#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerator;   
    int denominator; 
} Fraction;

typedef struct Node {
    Fraction data;           
    struct Node* leftChild;  
    struct Node* rightChild;
} Node;

Node* createNode(Fraction data);
Node* insertNode(Node* root, Fraction data);
void displayTree(Node* root); 
int searchFraction(Node* root, Fraction data);

int main() {
    Node* root = NULL;
    int choice, n; 
    
    do {
        printf("\n============= MENU =============\n");
        printf("| 1. Them phan tu vao cay      |\n");
        printf("| 2. Hien thi cay              |\n");
        printf("| 3. Tim kiem phan so tren cay |\n");
        printf("| 4. Thoat                     |\n");
        printf("================================\n");  
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                {
                	printf("Nhap vao so nut cua cay: ");
					scanf("%d", &n);
					printf("Nhap vao cac nut:\n");
					for(int i = 1; i <= n; i++) {
						printf("Nhap vao nut thu %d:\n", i); 
						Fraction newFraction;
                        printf("Nhap tu so: ");
                        scanf("%d", &newFraction.numerator);
                        printf("Nhap mau so: ");
                        scanf("%d", &newFraction.denominator);
                        root = insertNode(root, newFraction);
                        printf("Phan so da duoc them vao cay.\n");
					} 
                    break;
                }
            case 2:
                {
                    printf("Cay tim kiem nhi phan:\n");
                    displayTree(root); 
                    break;
                }
            case 3:
                {
                    Fraction sFraction;
                    printf("Nhap tu so can tim: ");
                    scanf("%d", &sFraction.numerator);
                    printf("Nhap mau so can tim: ");
                    scanf("%d", &sFraction.denominator);
                    
                    if (searchFraction(root, sFraction)) {
                        printf("Phan so da duoc tim thay trong cay.\n");
                    } else {
                        printf("Phan so khong ton tai tren cay.\n");
                    }
                    
                    break;
                }
            case 4:
                {
                    printf("Chuong trinh ket thuc.\n");
                    break;
                }
            default:
                {
                    printf("Lua chon khong hop le. Vui long chon lai.\n");
                    break;
                }
        }
    } while (choice != 0);
    
    return 0;
}

Node* createNode(Fraction data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node* insertNode(Node* root, Fraction data) {
    
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data.numerator * root->data.denominator < root->data.numerator * data.denominator) {
        root->leftChild = insertNode(root->leftChild, data);
    }
    else if (data.numerator * root->data.denominator > root->data.numerator * data.denominator) {
        root->rightChild = insertNode(root->rightChild, data);
    }
    
    return root;
}

void displayTree(Node* root) {
    if (root != NULL) {
        printf("%d/%d ", root->data.numerator, root->data.denominator);
        displayTree(root->leftChild);
        displayTree(root->rightChild);
    }
} 

int searchFraction(Node* root, Fraction data) {
    if (root == NULL || (data.numerator * root->data.denominator == root->data.numerator * data.denominator)) {
        return 1;
    }
    
    if (data.numerator * root->data.denominator < root->data.numerator * data.denominator) {
        return searchFraction(root->leftChild, data);
    }
    else {
        return searchFraction(root->rightChild, data);
    }
}

