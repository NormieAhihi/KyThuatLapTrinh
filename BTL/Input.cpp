#include"header.h"  
#include"function.h"

void setting_array() {
    A = new double *[n+1];
    b = new double [n+1];
    for(int i = 0; i < n; i++) {
    	A[i] = new double[n+1];
	}
}

void response_input() {
    cout << "\t\tNhap thanh cong!" << endl;
    out << "\t\tNhap thanh cong!" << endl;
    cout << "\t\tNhap so chu so thap phan trong ket qua: "; 
    cin >> precision;
    cout << endl; 
    out << "\t\tNhap so chu so thap phan trong ket qua: " << precision << endl; 
    cout << "\t\tMa tran A: " << endl;
    out << "\t\tMa tran A: " << endl;
    print_matrix(A); 
    cout << "\t\tVector b: " << endl;
    out << "\t\tVector b: " << endl; 
    print_vector(b);
}

void submenu_input() {
	string submenu[2] = { "1. Nhap tu file.", "2. Nhap tu man hinh."};
    int choice = 0;

    setcolor(15);
    while(true) {
        system("cls");
        string start = "\t\t\t== Chon cach nhap ==\t\t\n";
        border(36);
        cout << start;
        out << start; 
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
                switch (choice) {
                    case 0:
                    {
                        string file_name;
                        border(36);
                        cout << "\t\t";
                        out << "\t\t"; 
                        cout << "Nhap duong dan file: " << endl;
                        out << "Nhap duong dan file: " << endl;
                        cout << "\t\t";
                        out << "\t\t"; 
                        getline(cin, file_name);
                        out << file_name << endl; 
                        fflush(stdin);

                        ifstream my_file(file_name.c_str());

                        if(!my_file.is_open()) {
                            cout << "\t\t";
                            out << "\t\t"; 
                            cout << "Khong mo duoc file." << endl;
                            out << "Khong mo duoc file." << endl; 
                            setcolor(15);
                            border(36);
                            note();
                            return;
                        }

                        my_file >> n;

                        setting_array();

                        for(int i = 0;i < n;i++) {
                        	for(int j = 0;j < n;j++) {
                        		my_file >> A[i][j];
							}
						}
							
                        for(int i = 0;i < n;i++) {
                        	my_file >> b[i];
						}

                        border(36);
                        response_input();

                        my_file.close();

                        border(36);
                        fflush(stdin);
                        break;
                    }
                    case 1:
                    {
                        cout << "\t\tNhap co ma tran, vector: ";
                        cin >> n;
                        out << "\t\tNhap co ma tran, vector: " << n;
                        fflush(stdin);

                        setting_array();

                        cout << "\t\tNhap ma tran A: \n";
                        for(int i = 0;i < n;i++) {
                        	cout << "\t\t";
                            out << "\t\t";
                            for(int j = 0;j < n;j++) {
                            	cin >> A[i][j];
                                out << A[i][j];
							}
						}
                        cout << "\t\tNhap vector b: \n";
                        out << "\t\tNhap vector b: \n"; 

                        for(int i = 0;i < n;i++) {
                        	cout << "\t\t";
                            out << "\t\t";
                            cin >> b[i];
                            out << b[i]; 
						}
                            
                        border(36);
                        response_input();
                        border(36);
                        break;
                    }
                }
                setcolor(15);
                cout << "\n\t\tNhan Enter de quay lai.\n";
                cout << "\t\tNhan ESC de thoat chuong trinh.\n";
                out << "\n\t\tNhan Enter de quay lai.\n";
                out << "\t\tNhan ESC de thoat chuong trinh.\n";
                while(true) {
                    char key_in;
                    key_in = getch();
                    if(key_in == ENTER) {
                    	return;
					}
                    else if(key_in == ESC) {
                    	exit(0);
					}
                } 
            }

        }
    }
}


