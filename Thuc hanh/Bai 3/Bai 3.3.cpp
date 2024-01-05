#include <stdio.h>
#include <stdlib.h>

void writeBinaryFile();
void readBinaryFile();
void copyFile(); 

int main() {
    int choice;

    do {
        printf("\n======================= MENU =======================\n");
        printf("| 1. Nhap va ghi cac so thap phan vao tep nhi phan |\n");
        printf("| 2. Doc cac so thap phan tu tep nhi phan          |\n");
        printf("| 3. Sao chep tep                                  |\n");
        printf("| 4. Thoat                                         |\n");
        printf("====================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeBinaryFile();
                break;
            case 2:
                readBinaryFile();
                break;
            case 3:
                copyFile();
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Nhap vao cac so thap phan va ghi vao tep nhi phan
void writeBinaryFile() {
    int n;
    float number;

    FILE *file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }

    printf("Nhap so luong so thap phan: ");
    scanf("%d", &n);

    printf("Nhap cac so thap phan:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &number);
        fwrite(&number, sizeof(float), 1, file);
    }

    fclose(file);
    printf("Ghi thanh cong vao tep nhi phan.\n");
}

void readBinaryFile() {
    FILE *file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }

    float number;

    printf("Cac so thap phan trong tep nhi phan:\n");
    while (fread(&number, sizeof(float), 1, file) == 1) {
        printf("%.2f ", number);
    }

    fclose(file);
}

void copyFile() {
    FILE *sourceFile = fopen("numbers.bin", "rb");
    if (sourceFile == NULL) {
        printf("Khong the mo tep nguon.\n");
        return;
    }

    FILE *destinationFile = fopen("numbers_copy.bin", "wb");
    if (destinationFile == NULL) {
        printf("Khong the mo tep dich.\n");
        fclose(sourceFile);
        return;
    }

    int bufferSize = 1024;
    char buffer[bufferSize];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, bufferSize, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
    printf("Sao chep tep thanh cong.\n");
}


