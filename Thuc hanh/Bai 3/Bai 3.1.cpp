#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee* next;
} Employee;

Employee* createEmployee(int id, char name[], float salary);
void addEmployee(Employee** head, Employee* newEmployee);
void printEmployeeList(Employee* head);
void deleteEmployee(Employee** head, int id); 
void updateSalary(Employee* head, int id, float newSalary);
float calculateAverageSalary(Employee* head);
Employee* findEmployeeWithHighestSalary(Employee* head);
void freeEmployeeList(Employee** head);

int main() {
    Employee* head = NULL;

    int choice;
    do {
        printf("\n================ MENU ================\n");
        printf("| 1. Them nhan vien                  |\n");
        printf("| 2. In danh sach nhan vien          |\n");
        printf("| 3. Xoa nhan vien                   |\n");
        printf("| 4. Sua luong nhan vien             |\n");
        printf("| 5. Tinh trung binh luong           |\n");
        printf("| 6. Tim nhan vien co luong cao nhat |\n");
        printf("| 7. Thoat                           |\n");
        printf("======================================\n"); 
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, n; 
                char name[50];
                float salary;
                
	            printf("Nhap so luong nhan vien can them: ");
	            scanf("%d", &n);
	            for(int i = 1; i <= n; i++) {
	            	printf("Nhap thong tin cho nhan vien thu %d:\n", i);  
	                printf("Nhap ma so nhan vien: ");
                    scanf("%d", &id);
                    printf("Nhap ho ten nhan vien: ");
                    scanf(" %[^\n]", name);
                    printf("Nhap luong nhan vien: ");
                    scanf("%f", &salary);

                    Employee* newEmployee = createEmployee(id, name, salary);
                    addEmployee(&head, newEmployee);
             	} 
                break;
            }
            case 2: {
                printf("\nDanh sach nhan vien:\n");
                printEmployeeList(head);
                break;
            }
            case 3: {
                int id;
                printf("Nhap ma so nhan vien can xoa: ");
                scanf("%d", &id);
                deleteEmployee(&head, id);
                break;
            }
            case 4: {
                int id;
                float newSalary;
                printf("Nhap ma so nhan vien can sua luong: ");
                scanf("%d", &id);
                printf("Nhap luong moi: ");
                scanf("%f", &newSalary);
                updateSalary(head, id, newSalary);
                break;
            }
            case 5: {
                float averageSalary = calculateAverageSalary(head);
                printf("Trung binh luong cua cac nhan vien: %.2f\n", averageSalary);
                break;
            }
            case 6: {
                Employee* maxSalaryEmployee = findEmployeeWithHighestSalary(head);
                if (maxSalaryEmployee != NULL) {
                    printf("Nhan vien co luong cao nhat:\n");
                    printf("Ma so NV: %d\n", maxSalaryEmployee->id);
                    printf("Ho va ten: %s\n", maxSalaryEmployee->name);
                    printf("Luong: %.2f\n", maxSalaryEmployee->salary);
                }
                break;
            }
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    freeEmployeeList(&head);

    return 0;
}

Employee* createEmployee(int id, char name[], float salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

void addEmployee(Employee** head, Employee* newEmployee) {
	if (*head == NULL) {
        *head = newEmployee;
    } else {
        newEmployee->next = *head;
        *head = newEmployee;
    }
    printf("Them nhan vien thanh cong.\n\n"); 
}

void printEmployeeList(Employee* head) {
    if (head == NULL) {
        printf("Danh sach nhan vien trong.\n");
        return;
    }

    printf("So thu tu  Ma so NV   Ho va ten           Luong\n");
    printf("--------------------------------------------------\n");
    int index = 1;
    Employee* current = head;
    while (current != NULL) {
        printf("%-12d%-12d%-20s%.2f\n", index, current->id, current->name, current->salary);
        current = current->next;
        index++;
    }
}

void deleteEmployee(Employee** head, int id) {
    if (*head == NULL) {
        printf("Danh sach nhan vien trong.\n");
        return;
    }

    Employee* current = *head;
    Employee* prev = NULL;

    // Xoa ban ghi dau danh sach
    if (current != NULL && current->id == id) {
        *head = current->next;
        free(current);
        printf("Xoa nhan vien thanh cong.\n");
        return;
    }

    // Tim ban ghi can xoa
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    // Xoa ban ghi
    if (current == NULL) {
        printf("Không tim thay nhan vien co ma so %d.\n", id);
    } else {
        prev->next = current->next;
        free(current);
        printf("Xoa nhan vien thanh cong.\n");
    }
}

void updateSalary(Employee* head, int id, float newSalary) {
    if (head == NULL) {
        printf("Danh sach nhan vien trong.\n");
        return;
    }

    Employee* current = head;
    while (current != NULL) {
        if (current->id == id) {
            current->salary = newSalary;
            printf("Sua luong thanh cong.\n");
            return;
        }
        current = current->next;
    }

    printf("Khong tim thay nhan vien co ma so %d.\n", id);
}

float calculateAverageSalary(Employee* head) {
    if (head == NULL) {
        printf("Danh sach nhan vien trong.\n");
        return 0.0;
    }

    float sum = 0.0;
    int count = 0;
    Employee* current = head;
    while (current != NULL) {
        sum += current->salary;
        count++;
        current = current->next;
    }

    return sum / count;
}

Employee* findEmployeeWithHighestSalary(Employee* head) {
    if (head == NULL) {
        printf("Danh sach nhan vien trong.\n");
        return NULL;
    }

    Employee* maxSalaryEmployee = head;
    Employee* current = head->next;

    while (current != NULL) {
        if (current->salary > maxSalaryEmployee->salary) {
            maxSalaryEmployee = current;
        }
        current = current->next;
    }

    return maxSalaryEmployee;
}

void freeEmployeeList(Employee** head) {
    Employee* current = *head;
    while (current != NULL) {
        Employee* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

