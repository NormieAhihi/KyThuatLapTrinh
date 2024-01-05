#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

struct Node* createNode(float x);
void insertNode(struct Node** head, struct Node* newNode);
void printList(struct Node* head);
float findMax(struct Node* head);
float findMin(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, n; 
    float value;

    while (1) {
        printf("=========== MENU ==========\n");
        printf("| 1. Them phan tu         |\n");
        printf("| 2. In danh sach         |\n");
        printf("| 3. Tim phan tu lon nhat |\n");
        printf("| 4. Tim phan tu nho nhat |\n");
        printf("| 5. Thoat                |\n");
        printf("===========================\n"); 
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	printf("Nhap vao so luong phan tu: ");
				scanf("%d", &n);
				printf("Nhap vao cac phan tu: ");
				for(int i = 1; i <= n; i++) {
                    scanf("%f", &value);
                    insertNode(&head, createNode(value));
				} 
                break;
            case 2:
                printList(head);
                break;
            case 3:
                if (head == NULL) {
                    printf("Danh sach rong.\n");
                } else {
                    printf("Phan tu lon nhat: %.2f\n", findMax(head));
                }
                break;
            case 4:
                if (head == NULL) {
                    printf("Danh sach rong.\n");
                } else {
                    printf("Phan tu nho nhat: %.2f\n", findMin(head));
                }
                break;
            case 5:
                printf("Cam on da su dung chuong trinh!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }

    return 0;
}

struct Node* createNode(float x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, struct Node* newNode) {
    struct Node* current;
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        // Tim vi tri thich hop de chen nut moi
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    printf("Danh sach: ");
    while (current != NULL) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

float findMax(struct Node* head) {
    float max = head->data;
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

float findMin(struct Node* head) {
    float min = head->data;
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

