#include"header.h" 
#include"function.h"

void cal_Bd(double **B, double *d, double **A, double *b) {
    for(int i = 0;i < n;i++) {
    	for(int j = 0;j < n;j++) {
        	if(i == j) {
        		B[i][j] = 0;
			} 
            else {
            	B[i][j] = -A[i][j]/A[i][i];
			} 
		}
	}

    for(int i = 0;i < n;i++) {
    	d[i] = b[i]/A[i][i];
	}
}

void cal_B_col(double **B_col, double **A, double *b) {
    for(int j = 0;j < n;j++) {
    	for(int i = 0;i < n;i++) {
    		 if(i == j) {
    		 	B_col[j][j] = 0;
			 }
            else {
            	B_col[i][j] = -A[i][j]/A[j][j];
			} 
		}
	}
}
