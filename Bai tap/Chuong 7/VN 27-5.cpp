#include<stdio.h>
#include<windows.h>
#include<stdlib.h> 
#include<conio.h> 

using namespace std; 

#define FOCUS 240  
#define NORMAL 15
void printMenu(int focus, int n);

int main() {
	int n, focus = 0; 
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	system("cls"); 
	
	printMenu(0, n); 
	do {  
        int ch = getch(); 
        if (ch == 0 || ch == 224) {
            char c = getch();
            switch(c) {
                case 72:
                  if(focus == 0) {
                     focus = n - 1;
                  } else {
                     focus--;
                  }
                  break;
            
                case 80:
                  if(focus == n - 1) {
                     focus = 0;
                  } else {
                     focus++;
                  }     
                  break;   
            }
        } else if (ch == 13) {
            	printf("\n");
                exit(EXIT_SUCCESS);  
        }
        
		system("cls");    
        printMenu(focus, n);
        } while(true); 

	return 0; 
} 

void printMenu(int focus, int n) { 
    int count = 0; 
 
    HANDLE hConsole; 
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
    printf("--------------------\n"); 
    for (int i = 0; i < n; i++) {
        if (i == focus) {
          SetConsoleTextAttribute(hConsole, FOCUS);
        } else {
          SetConsoleTextAttribute(hConsole, NORMAL); 
        }
        printf("|    Lua chon %d    | \n", i + 1);  
    }
    printf("--------------------"); 
    SetConsoleTextAttribute(hConsole, NORMAL);
}


