#include"header.h"   
#include"function.h"

void print_matrix(double **temp) {
    cout << fixed;
    out << fixed;
    for(int i = 0;i < n;i++) {
        cout << "\t\t";
        out << "\t\t";
        for(int j = 0;j < n;j++) {
        	cout << setw(precision + 5) << setprecision(precision) << temp[i][j] << ' ';
            out << setw(precision + 5) << setprecision(precision) << temp[i][j] << ' ';
		}
        cout << endl;
        out << endl;
    }
}

void print_vector(double *temp) {
    cout << fixed;
    out << fixed;
    for(int i = 0;i < n;i++) {
    	cout << "\t\t" << setw(precision + 5) << setprecision(precision) << temp[i] << "\n";
        out << "\t\t" << setw(precision + 5) << setprecision(precision) << temp[i] << "\n";
	}
} 

void print_vector1(double *temp) {
    for(int i = 0;i < n;i++) {
    	cout << setprecision(precision) << temp[i] << "   ";
        out << setprecision(precision) << temp[i] << "   ";
	}
	cout << endl; 
	out << endl; 
} 
