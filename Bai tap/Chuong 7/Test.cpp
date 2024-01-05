#include <stdio.h>
#include <conio.h>
#include <windows.h> 

void gotoxy(int x, int y);
void drawRectangle(int x, int y, int width, int height);

int main() {
    int screenWidth, screenHeight;
    int width, height;
    int x, y;
    
    printf("Nhap chieu rong cua hinh chu nhat: ");
    scanf("%d", &width);
    
    printf("Nhap chieu cao cua hinh chu nhat: ");
    scanf("%d", &height);
    
    // Lay kich thuoc man hinh
    screenWidth = _getch();
    screenHeight = _getche();
    
    // Tinh toan toa do de ve khung hinh chu nhat o chinh giua man hinh
    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    
    // Ve khung hinh chu nhat
    drawRectangle(x, y, width, height);
    
    return 0;
}

void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

void drawRectangle(int x, int y, int width, int height) {
    int i, j;
    
    // Di chuyen con tro den toa do x, y
    gotoxy(x, y); 
    
    // Ve hang dau tien
    for (i = 0; i < width; i++) {
        printf("*");
    }
    
    // Di chuyen con tro den toa do x, y + height - 1
    gotoxy(x, y + height - 1); 
     
    // Ve hang cuoi cung
    for (i = 0; i < width; i++) {
        printf("*");
    }
}

