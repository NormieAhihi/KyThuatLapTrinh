#include"header.h"
#include"function.h"    

int n, k, precision;
double **A, **B, **B_col;
double *b, *d;
double epsilon, frac;

ofstream out;  

int main() {
    out.open("C:\\Users\\Admin\\OneDrive\\Documents\\C-C++\\Ky thuat lap trinh\\BTL\\Output\\Qua trinh 1.txt"); 
    SetConsoleTitle("Giai he phuong trinh dai so tuyen tinh"); 
    string Menu[7] = {
	"| 1. Nhap ma tran A va vecto b.                               |",
    "| 2. Kiem tra tinh cheo troi cua ma tran A.                   |",
    "| 3. Tinh chuan cua ma tran A. Kiem tra su hoi tu.            |",
    "| 4. Tinh nghiem gan dung voi k lan lap.                      |",
    "| 5. Tinh nghiem gan dung voi sai so e.                       |",
    "| 6. Tinh nghiem gan dung X(k) thoa man ||X(k)-X(k-1)|| <= e. |",
    "| 7. Thoat chuong trinh.                                      |" };
    int pointer = 0;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  

    while(true) { 
        system("cls");
        border(63);
        cout << "\t\t\t\t\t     MENU       \t\t\t\n";
        out << "\t\t\t\t\t     MENU       \t\t\t\n";
        border(63);
        for (int i = 0; i < 7; ++i) {
            if (i == pointer) {   
                cout << "\t      =>";
                out << "\t      =>";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                cout << Menu[i] << endl;
                out << Menu[i] << endl; 
            }
            else {
                cout << "\t\t";
                out << "\t\t";
				cout << Menu[i] << endl;  
				out << Menu[i] << endl;   
			}
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        } border(63); 
        while(true) {
            char key;
            key = getch();
            if (key ==  UP) {
                pointer = pointer - 1;
                if (pointer == -1) {
                	pointer = 6;
				}
                break;
            }
            else if (key ==  DOWN) {
                pointer = pointer + 1;
                if (pointer == 7) {
                	pointer = 0;
				}
                break;
            }
            else if (key == ENTER) {
                switch (pointer) {
                    case 0:
                        system("cls");
                        fflush(stdin);
                        submenu_input();
                        break;
                    case 1:
                        system("cls");
                        border(33);
                        cout << "\t\t\t   Ket qua \n";
                        out << "\t\t\t   Ket qua \n"; 
                        border(33);
                        if(row_diag_dom(A)) {
                        	cout << "\t\t Ma tran A cheo troi hang." << endl;
                            out << "\t\t Ma tran A cheo troi hang." << endl; 
						}
                        else {
                        	cout << "\t\t Ma tran A khong cheo troi hang." << endl;
                            out << "\t\t Ma tran A khong cheo troi hang." << endl;
						}
                            
                        if(col_diag_dom(A)) {
                        	cout << "\t\t Ma tran A cheo troi cot." << endl;
                            out << "\t\t Ma tran A cheo troi cot." << endl;
						}
                        else {
                        	cout << "\t\t Ma tran A khong cheo troi cot." << endl;
                            out << "\t\t Ma tran A khong cheo troi cot." << endl; 
						}
    
                        border(33);
                        note();
                        break;
                    case 2:
                        system("cls");
                        border(33);
                        cout << "\t\t\t Ket qua \n";
                        out << "\t\t\t Ket qua \n";
                        border(33);
                        cout << "\t\t Chuan hang ma tran A: " << matrix_norm_row(A) << endl;
                        out << "\t\t Chuan hang ma tran A: " << matrix_norm_row(A) << endl;
                        cout << "\t\t Chuan cot ma tran A: " << matrix_norm_col(A) << endl;
                        out << "\t\t Chuan cot ma tran A: " << matrix_norm_col(A) << endl;
						if(row_diag_dom(A) || col_diag_dom(A)) {
							cout << "\t\t Phuong phap hoi tu." << endl;
                            out << "\t\t Phuong phap hoi tu." << endl; 
						}
                        else {
                        	cout << "\t\t Phuong phap khong hoi tu." << endl;
                            out << "\t\t Phuong phap khong hoi tu." << endl;
						}
                        border(33);
                        note();
                        break;
                    case 3:
                        system("cls");
                        border(40);
                        cout << "\t\t\t Nhap cac tham so \t\t\n";
                        out << "\t\t\t Nhap cac tham so \t\t\n"; 
                        border(40);
                        cout << "\t\t Nhap so lan lap k: ";
                        cin >> k;
                        out << "\t\t Nhap so lan lap k: " << k << endl; 
                        cout << "\t\t Nhap so chu so thap phan trong ket qua: ";
                        cin >> precision;
                        out << "\t\t Nhap so chu so thap phan trong ket qua: " << precision << endl; 
                        Sleep(300); 
                        solve(1);
                        break;
                    case 4:
                        system("cls");
                        border(40);
                        cout << "\t\t\t Nhap cac tham so \t\t\n";
                        out << "\t\t\t Nhap cac tham so \t\t\n"; 
                        border(40);
                        cout << "\t\t Nhap sai so e: ";
                        cin >> epsilon;
                        out << "\t\t Nhap sai so e: " << epsilon << endl; 
                        cout << "\t\t Nhap so chu so thap phan trong ket qua: ";
                        cin >> precision;
                        out << "\t\t Nhap so chu so thap phan trong ket qua: " << precision << endl;  
                        Sleep(300); 
                        solve(2);
                        break;
                    case 5:
                        system("cls");
                        border(40);
                        cout << "\t\t\t Nhap cac tham so \t\t\n";
                        out << "\t\t\t Nhap cac tham so \t\t\n"; 
                        border(40);
                        cout << "\t\t Nhap sai so e: ";
                        cin >> epsilon;
                        out << "\t\t Nhap sai so e: " << epsilon << endl; 
                        cout << "\t\t Nhap so chu so thap phan trong ket qua: ";
                        cin >> precision;
                        out << "\t\t Nhap so chu so thap phan trong ket qua: " << precision << endl;  
                        Sleep(300); 
                        solve(3);
                        break;
                    case 6:
                        system("cls");
                        border(40);
                        cout << "\t\t\t Ket thuc chuong trinh \t\t\n";
                        out << "\t\t\t Ket thuc chuong trinh \t\t\n"; 
                        border(40);
                        exit(0);
                }
                break;
            } 
        }
        Sleep(150);
    }
    out.close();  
    return 0;
} 


