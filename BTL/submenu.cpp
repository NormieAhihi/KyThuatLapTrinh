#include"header.h"   
#include"function.h"

void setcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    return;
}

void note() {
    setcolor(15);
    cout << "\t\tNhan Enter de quay lai.\n";
    cout << "\t\tNhan ESC de thoat chuong trinh.\n";
    
    out << "\t\tNhan Enter de quay lai.\n";
    out << "\t\tNhan ESC de thoat chuong trinh.\n";

    while(1) {
        char key;
        key = getch();
        if(key == ENTER) {
        	return;
		}
        else if(key == ESC) {
        	exit(0);
		} 
    }
}

void border(int w) {
    cout << "\t\t";
    out << "\t\t";
    for(int i = 0;i < w;i++) {
    	cout << '=';
        out << '=';
	}
    cout << endl;
    out << endl;
}

void submenu_se(int mode) {
    string submenu[2] = { "1. Lap don.", "2. Lap Seidel."};
    int choice = 0;

    while(true) {
        system("cls");
        setcolor(15);
        border(36);
        cout << "\t\t\t Chon phuong phap giai \t\t\n";
        out << "\t\t\t Chon phuong phap giai \t\t\n";
        border(36);

        for (int i = 0; i < 2; ++i) {
            if (i == choice) {
                cout << "\t     => ";
                out << "\t     => ";
                setcolor(240);
                cout << submenu[i] << endl;
                out << submenu[i] << endl;
            }
            else {
                cout << "\t\t";
                out << "\t\t";
				cout << submenu[i] << endl;
				out << submenu[i] << endl;
			}
            setcolor(15);
        }
        while(true)
        {
            char key;
            key = getch();
            // print(key);
            if (key == UP) {
                choice = choice - 1;
                if (choice == -1) {
                	choice = 1;
				} 
                break;
            }
            else if (key == DOWN) {
                choice = choice + 1;
                if (choice == 2) {
                	choice = 0;
				} 
                break;
            }
            else if (key == ENTER) {

                setcolor(15);
                border(36);
                cout << "\t\t\t Ket qua \t\t\n";
                out << "\t\t\t Ket qua \t\t\n";
                border(36);
                switch (choice) {

                    case 0:
                        cout << "\n";
                        if(row_diag_dom(A)) {
                        	cout << "\t\tMa tran B:" << endl;
							out << "\t\tMa tran B:" << endl;
							print_matrix(B); 
							cout << "\t\tVecto d:" << endl;
							out << "\t\tVecto d:" << endl;
							print_vector(d);
                        	for(int type = 1;type <= 2;type++) {
                        		 if(mode == 1) {
                                	solve_iterative_single_row_k(B, d, k, type);
								}
                                else if(mode == 2) {
                                	solve_iterative_single_row_eps(B, d, epsilon, type);
								}
                                else if(mode == 3) {
                                    solve_iterative_single_row_con(B, d, epsilon);
                                    cout << endl;
                                    out << endl; 
                                    break;
                                }
                                cout << endl;
                                out << endl; 
							} 
					    }
                        else {
                        	cout << "\t\tMa tran B:" << endl;
							out << "\t\tMa tran B:" << endl;
							print_matrix(B); 
							cout << "\t\tMa tran B_col:" << endl;
							out << "\t\tMa tran B_col:" << endl;
							print_matrix(B_col); 
							cout << "\t\tVecto d:" << endl;
							out << "\t\tVecto d:" << endl;
							print_vector(d);
                        	for(int type = 1;type <= 2;type++) {
                        		if(mode == 1) {
                        		 	solve_iterative_single_col_k(B, d, B_col, frac, k, type);
								}
                                else if(mode == 2) {
                                	solve_iterative_single_col_eps(B, d, B_col, epsilon, frac, type);
								}
                                else if(mode == 3) {
                                    solve_iterative_single_col_con(B, d, epsilon);
                                    cout << endl;
                                    out << endl; 
                                    break;
                                }
							}
						}

                        break;
                    case 1:
                        cout << "\n";
                        out << "\n";
                        if(row_diag_dom(A)) {
                        	cout << "\t\tMa tran B:" << endl;
							out << "\t\tMa tran B:" << endl;
							print_matrix(B); 
							cout << "\t\tVecto d:" << endl;
							out << "\t\tVecto d:" << endl;
							print_vector(d);
                        	for(int type = 1;type <= 2;type++) {
                        		if(mode == 1) {
                        			solve_iterative_seidel_row_k(B, d, k, type);
								}
                                else if(mode == 2) {
                                	solve_iterative_seidel_row_eps(B, d, epsilon, type);
								}
                                else if(mode == 3) {
                                    solve_iterative_seidel_row_con(B, d, epsilon);
                                    cout << endl;
                                    out << endl; 
                                    break;
                                }
                                cout << endl;
                                out << endl; 
							}
						}
                        
                        else {
                        	cout << "\t\tMa tran B:" << endl;
							out << "\t\tMa tran B:" << endl;
							print_matrix(B); 
							cout << "\t\tMa tran B_col:" << endl;
							out << "\t\tMa tran B_col:" << endl;
							print_matrix(B_col); 
							cout << "\t\tVecto d:" << endl;
							out << "\t\tVecto d:" << endl;
							print_vector(d); 
                        	for(int type = 1;type <= 2;type++) {
                                if(mode == 1) {
                                	solve_iterative_seidel_col_k(B, d, B_col, k, type);
								}
                                else if(mode == 2) {
                                	solve_iterative_seidel_col_eps(B, d, B_col, epsilon, type);
								}
                                else if(mode == 3) {
                                    solve_iterative_seidel_col_con(B, d, epsilon);
                                    cout << endl;
                                    out << endl; 
                                    break;
                                }
							}
						}
                            
                        break;
                }
                border(36);  
                setcolor(15);
                cout << "\n\t\tNhan Enter de quay lai.\n";
                cout << "\t\tNhan ESC de thoat chuong trinh.\n";
                out << "\n\t\tNhan Enter de quay lai.\n";
                out << "\t\tNhan ESC de thoat chuong trinh.\n";
                while(1) {
                    //   print(key);
                    key = getch();
                    if(key == ENTER) {
                    	return;
					}
                    else if(key == ESC) {
                    	exit(0);
					}
                }
            }

        }
    }
}

void solve(int mode) {
    if(row_diag_dom(A) || col_diag_dom(A)) {
        B = new double *[n+1];
        B_col = new double *[n+1];
        d = new double [n+1];
        for(int i = 0;i < n;i++) {
            B[i] = new double[n+1];
            B_col[i] = new double[n+1];
        }
        cal_Bd(B, d, A, b);
        cal_B_col(B_col, A, b);
        frac = cal_frac(A);
        submenu_se(mode);
    }
    else {
        border(36);
        cout << "\t\tPhuong phap khong hoi tu." << endl;
        out << "\t\tPhuong phap khong hoi tu." << endl;
        border(36);
        
    }
}

