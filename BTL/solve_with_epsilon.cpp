#include"header.h"   
#include"function.h"

string statement_eps[2] = {"\t\tSai so tuyet doi tien nghiem: ", "\t\tSai so tuyet doi hau nghiem: "};

void solve_iterative_single_row_eps(double **B, double *d, double epsilon, int type) {
    double *x, *x_old, *x_fi;
    double norm_B_row, error;
    int k = 0;

    // Cap phat bo nho cho x, x_old, x_fi
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    // Dat nghiem ban dau x = 0
    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}

    norm_B_row = matrix_norm_row(B);
    if(type == 1) {
    	cout << "\t\tDanh gia sai so tien nghiem:" << endl; 
	    out << "\t\tDanh gia sai so tien nghiem:" << endl; 
	} 
	if(type == 2) {
    	cout << "\t\tDanh gia sai so hau nghiem:" << endl; 
	    out << "\t\tDanh gia sai so hau nghiem:" << endl; 
	} 
	cout << "\t\tChuan hang cua ma tran B: " << norm_B_row <<  endl; 
	out << "\t\tChuan hang cua ma tran B: " << norm_B_row <<  endl; 
      
    // Thuc hien lap
    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    	out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
		print_vector1(x);
        k = k + 1;

        iterative_single(x, x_old, B, d);  

        // Luu sai so lan lap dau
        if(k == 1) {
        	for(int i = 0;i < n;i++) {
        		x_fi[i] = x[i];
			}
		}

        // Xac dinh sai so  
        if(type == 1) {
        	error = absolute_error_pre_row_single(x_fi, k, norm_B_row); // Sai so tuyet doi tien nghiem
		}
        if(type == 2) {
        	error = absolute_error_pos_row_single(x, x_old, norm_B_row); // Sai so tuyet doi hau nghiem
		}
        // Dieu kien dung
        if(error < epsilon) {
        	break;
		}
    }
    cout << "\t\tLan lap thu " << k << ": x[" <<  k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" <<  k << "]= ";
	print_vector1(x);
 
    cout << "\t\tSo lan lap: " << k << endl;
    cout << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiem cua he phuong trinh: \n";
    
    out << "\t\tSo lan lap: " << k << endl;
    out << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    out << "\t\tNghiem cua he phuong trinh: \n";
    
    print_vector(x);
}

void solve_iterative_seidel_row_eps(double **B, double *d, double epsilon, int type) {
    double *x, *x_old, *x_fi;
    double lambda, error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}

    lambda = lambda_row(B);
    if(type == 1) {
    	cout << "\t\tDanh gia sai so tien nghiem:" << endl; 
	    out << "\t\tDanh gia sai so tien nghiem:" << endl; 
	} 
	if(type == 2) {
    	cout << "\t\tDanh gia sai so hau nghiem:" << endl; 
	    out << "\t\tDanh gia sai so hau nghiem:" << endl; 
	}  
	cout << "\t\tHe so co: lambda = " << lambda << endl; 
	out << "\t\tHe so co: lambda = " << lambda << endl; 
    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    	out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
		print_vector1(x);
        k = k + 1;

        iterative_seidel(x, x_old, B, d);   

        if(k == 1) {
        	for(int i = 0;i < n;i++) {
        		x_fi[i] = x[i];
			}
		}
		
        if(type == 1) {
        	error = absolute_error_pre_row_seidel(x_fi, k, lambda); // Sai so tuyet doi tien nghiem
		}
        if(type == 2) {
        	error = absolute_error_pos_row_seidel(x, x_old, lambda); // Sai so tuyet doi hau nghiem
		}

        if(error < epsilon) {
        	break;
		}
    }
    cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	print_vector1(x);
	
    cout << "\t\tSo lan lap: " << k << endl;
    cout << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiem cua he phuong trinh: \n";
    
    out << "\t\tSo lan lap: " << k << endl;
    out << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    out << "\t\tNghiem cua he phuong trinh: \n";
    
    print_vector(x);
}

void solve_iterative_single_col_eps(double **B, double *d, double **B_col, double epsilon, double frac, int type) {
    double *x, *x_old, *x_fi;
    double norm_B_col, error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}

    norm_B_col = matrix_norm_col(B_col);
    if(type == 1) {
    	cout << "\t\tDanh gia sai so tien nghiem:" << endl; 
	    out << "\t\tDanh gia sai so tien nghiem:" << endl; 
	} 
	if(type == 2) {
    	cout << "\t\tDanh gia sai so hau nghiem:" << endl; 
	    out << "\t\tDanh gia sai so hau nghiem:" << endl; 
	} 
	cout << "\t\tChuan cot cua ma tran B: " << norm_B_col <<  endl; 
	out << "\t\tChuan cot cua ma tran B: " << norm_B_col <<  endl;
    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" <<  k << "]= ";
    	out << "\t\tLan lap thu " << k << ": x[" <<  k << "]= ";
		print_vector1(x);
        k = k + 1;

        iterative_single(x, x_old, B, d);  

        if(k == 1) {
        	for(int i = 0;i < n;i++) {
        		x_fi[i] = x[i];
			}
		}

        if(type == 1) {
        	error = absolute_error_pre_col_single(x_fi, k, frac, norm_B_col); // Sai so tuyet doi tien nghiem
		}
        if(type == 2) {
        	error = absolute_error_pos_col_single(x, x_old, frac, norm_B_col); // Sai so tuyet doi hau nghiem
		}

        if(error < epsilon) {
        	break;
		}
    }
    cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	print_vector1(x);
    
    cout << "\t\tSo lan lap: " << k << endl;
    cout << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiem cua he phuong trnh: \n";
    
    out << "\t\tSo lan lap: " << k << endl;
    out << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    out << "\t\tNghiem cua he phuong trnh: \n";
    
    print_vector(x);
}

void solve_iterative_seidel_col_eps(double **B, double *d, double **B_col, double epsilon, int type) {
    double *x, *x_old, *x_fi;
    double lambda, s, error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}

    lambda = lambda_col(B_col);
    s = cal_s(B_col);
    if(type == 1) {
    	cout << "\t\tDanh gia sai so tien nghiem:" << endl; 
	    out << "\t\tDanh gia sai so tien nghiem:" << endl; 
	} 
	if(type == 2) {
    	cout << "\t\tDanh gia sai so hau nghiem:" << endl; 
	    out << "\t\tDanh gia sai so hau nghiem:" << endl; 
	} 
	cout << "\t\tHe so co: lambda = " << lambda << endl; 
	out << "\t\tHe so co: lambda = " << lambda << endl;
	cout << "\t\tTham so s: s = " << s << endl; 
	out << "\t\tTham so s: s = " << s << endl;  
    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
        out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    	print_vector1(x);
    
        k = k + 1;

        iterative_seidel(x, x_old, B, d);

        if(k == 1) {
        	for(int i = 0;i < n;i++) {
        		x_fi[i] = x[i];
			}
		}
			
        if(type == 1) {
        	error = absolute_error_pre_col_seidel(x_fi, k, s, lambda); // Sai so tuyet doi tien nghiem
		}
        if(type == 2) {
        	error = absolute_error_pos_col_seidel(x, x_old, s, lambda); // Sai so tuyet doi hau nghiem
		}
		
        if(error < epsilon) {
        	break;	
		}
        
    }
    cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	print_vector1(x);
    
    cout << "\t\tSo lan lap: " << k << endl;
    cout << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiem cua he phuong trinh: \n";
    
    out << "\t\tSo lan lap: " << k << endl;
    out << fixed << statement_eps[type-1] << setprecision(precision) << error << endl;
    out << "\t\tNghiem cua he phuong trinh: \n";
    
    print_vector(x);
}
