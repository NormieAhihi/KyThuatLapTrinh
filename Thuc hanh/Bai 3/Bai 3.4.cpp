#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    float salary;
};

void writeToFile(struct Person person);
void readFromFile();
void findHighestSalary();
void calculateAverageSalary();
void updateRecord(int k); 

int main() {
    int choice, n, k;
    struct Person person;

    do {
    	printf("\n================================================= MENU ================================================\n"); 
        printf("| 1. Nhap du lieu cho moi nguoi                                                                       |\n");
        printf("| 2. Tim nguoi co luong cao nhat                                                                      |\n");
        printf("| 3. Tinh trung binh cong luong va hien thi danh sach nguoi co luong lon hon hoac bang trung binh cong|\n");
        printf("| 4. Sua noi dung ban ghi thu k                                                                       |\n");
        printf("| 5. Thoat                                                                                            |\n");
        printf("=======================================================================================================\n"); 
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong nguoi: ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    printf("Nhap thong tin nguoi thu %d:\n", i + 1);
                    printf("Ho ten: ");
                    scanf(" %[^\n]", person.name);  
                    printf("Tuoi: ");
                    scanf("%d", &person.age);
                    printf("Luong: ");
                    scanf("%f", &person.salary);

                    writeToFile(person);
                }

                printf("Da nhap xong cho %d nguoi.\n", n);
                printf("\nDanh sach sau khi nhap:\n"); 
                readFromFile();
                break;
            case 2:
                findHighestSalary();
                break;
            case 3:
                calculateAverageSalary();
                break;
            case 4:
                printf("Nhap so thu tu ban ghi can sua: ");
                scanf("%d", &k);
                updateRecord(k);
                printf("\nDanh sach sau khi sua:\n");
                readFromFile();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}

void writeToFile(struct Person person) {
    FILE *file = fopen("data.bin", "ab");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    fwrite(&person, sizeof(struct Person), 1, file);
    fclose(file);
}

void readFromFile() {
    FILE *file = fopen("data.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct Person person;
    printf("Ho ten                Tuoi           Luong\n");
    printf("---------------------------------------------\n");
    while (fread(&person, sizeof(struct Person), 1, file) == 1) {
        printf("%-22s%-15d%.2f\n", person.name, person.age, person.salary);
    }
    printf("---------------------------------------------\n");
    fclose(file);
}

void findHighestSalary() {
    FILE *file = fopen("data.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct Person person;
    float maxSalary = 0;
    char maxName[50];

    while (fread(&person, sizeof(struct Person), 1, file) == 1) {
        if (person.salary > maxSalary) {
            maxSalary = person.salary;
            strcpy(maxName, person.name);
        }
    }

    fclose(file);

    if (maxSalary > 0) {
        printf("Nguoi co luong cao nhat:\n");
        printf("Ho ten: %s\n", maxName);
        printf("Luong: %.2f\n", maxSalary);
    } else {
        printf("Khong co du lieu.\n");
    }
}

void calculateAverageSalary() {
    FILE *file = fopen("data.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct Person person;
    float totalSalary = 0;
    int count = 0;

    while (fread(&person, sizeof(struct Person), 1, file) == 1) {
        totalSalary += person.salary;
        count++;
    }

    fclose(file);

    if (count > 0) {
        float averageSalary = totalSalary / count;
        printf("Trung binh cong luong: %.2f\n", averageSalary);
        printf("Nhung nguoi co luong lon hon hoac bang %.2f:\n", averageSalary);

        file = fopen("data.bin", "rb");
        if (file == NULL) {
            printf("Khong the mo file.\n");
            return;
        }

        printf("Ho ten                Tuoi           Luong\n");
        printf("---------------------------------------------\n");
        while (fread(&person, sizeof(struct Person), 1, file) == 1) {
            if (person.salary >= averageSalary) {
                printf("%-22s%-15d%.2f\n", person.name, person.age, person.salary);
                //printf("Ho ten: %s\n", person.name);
                //printf("Luong: %.2f\n", person.salary);
                //printf("---------------------\n");
            }
        }
        printf("---------------------------------------------\n");

        fclose(file);
    } else {
        printf("Khong co du lieu.\n");
    }
}

void updateRecord(int k) {
    FILE *file = fopen("data.bin", "r+b");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct Person person;
    fseek(file, (k - 1) * sizeof(struct Person), SEEK_SET);
    if (fread(&person, sizeof(struct Person), 1, file) != 1) {
        printf("Khong tim thay ban ghi thu %d.\n", k);
        fclose(file);
        return;
    }

    printf("Nhap ten moi: ");
    scanf(" %[^\n]", person.name);
    printf("Nhap tuoi moi: ");
    scanf("%d", &person.age);
    printf("Nhap luong moi: ");
    scanf("%f", &person.salary);

    fseek(file, (k - 1) * sizeof(struct Person), SEEK_SET);
    fwrite(&person, sizeof(struct Person), 1, file);

    fclose(file);
    printf("Da cap nhat ban ghi thu %d.\n", k);
}


