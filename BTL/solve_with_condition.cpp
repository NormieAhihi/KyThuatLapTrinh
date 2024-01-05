#include"header.h"   
#include"function.h"

void solve_iterative_single_row_con(double **B, double *d, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;

    // Cap phat bo nho cho x, x_old
    x = new double[n+1];
    x_old = new double[n+1];

    // Dat nghiem ban dau x = 0
    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}
    cout << "\t\tDanh gia sai so:" << endl; 
	out << "\t\tDanh gia sai so:" << endl; 
    // Thuc hien lap
    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    	out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
		print_vector1(x); 
        k = k + 1;

        iterative_single(x, x_old, B, d);  

        // Dieu kien dung
        error = absolute_error_row(x, x_old);
        if(error < epsilon) {
        	break;
		}
    }
    cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	print_vector1(x); 
    
    cout << "\t\tSo lan lap: " << k << endl;
    out << "\t\tSo lan lap: " << k << endl;
    cout << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_row(x, x_old) << endl;
    out << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_row(x, x_old) << endl;
    cout << "\t\tNghiem cua he phuong trinh: \n";
    out << "\t\tNghiem cua he phuong trinh: \n"; 
    print_vector(x);
}

void solve_iterative_seidel_row_con(double **B, double *d, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];

    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}
	cout << "\t\tDanh gia sai so:" << endl; 
	out << "\t\tDanh gia sai so:" << endl; 

    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    	out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
		print_vector1(x); 
        k = k + 1;

        iterative_seidel(x, x_old, B, d);  

        error = absolute_error_row(x, x_old);
        if(error < epsilon) {
        	break;
		}
    }
    cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	print_vector1(x); 
    
    cout << "\t\tSo lan lap: " << k << endl;
    out << "\t\tSo lan lap: " << k << endl;
    cout << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_row(x, x_old) << endl;
    out << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_row(x, x_old) << endl; 
    cout << "\t\tNghiem cua he phuong trinh: \n";
    out << "\t\tNghiem cua he phuong trinh: \n"; 
    print_vector(x);
}

void solve_iterative_single_col_con(double **B, double *d, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];

    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}

    cout << "\t\tDanh gia sai so:" << endl; 
	out << "\t\tDanh gia sai so:" << endl;
    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
        out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	    print_vector1(x);
        k = k + 1;

        iterative_single(x, x_old, B, d);  

        error = absolute_error_col(x, x_old);
        if(error < epsilon) {
        	break;
		}
    }
    cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	print_vector1(x);
    
    cout << "\t\tSo lan lap: " << k << endl;
    out << "\t\tSo lan lap: " << k << endl; 
    cout << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_col(x, x_old) << endl;
    out << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_col(x, x_old) << endl; 
    cout << "\t\tNghiem cua he phuong trinh: \n";
    out << "\t\tNghiem cua he phuong trinh: \n"; 
    print_vector(x);
}

void solve_iterative_seidel_col_con(double **B, double *d, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];

    for(int i = 0;i < n;i++) {
    	x[i] = 0;
	}

    while(true) {
    	cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
        out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    	print_vector1(x);
        k = k + 1;

        iterative_seidel(x, x_old, B, d);   

        error = absolute_error_col(x, x_old);
        if(error < epsilon) {
        	break;
		}
    }
    cout << "\t\tDanh gia sai so:" << endl; 
	out << "\t\tDanh gia sai so:" << endl;
    cout << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
    out << "\t\tLan lap thu " << k << ": x[" << k << "]= ";
	print_vector1(x);
    
    cout << "\t\tSo lan lap: " << k << endl;
    cout << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_col(x, x_old) << endl;
    cout << "\t\tNghiem cua he phuong trinh: \n";
    
    out << "\t\tSo lan lap: " << k << endl;
    out << fixed << setprecision(precision) << "\t\tSai so tuyet doi: " << absolute_error_col(x, x_old) << endl;
    out << "\t\tNghiem cua he phuong trinh: \n";
    
	print_vector(x);
}


