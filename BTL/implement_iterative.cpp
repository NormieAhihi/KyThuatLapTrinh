#include"header.h"   
#include"function.h"

void iterative_single(double *x, double *x_old, double **B, double *d) {
    double res;
    for(int j = 0;j < n;j++) {
    	x_old[j] = x[j];
	}
    for(int i = 0;i < n;i++) {
        res = 0.0;
        for(int j = 0;j < n;j++) {
        	res = res + B[i][j]*x_old[j];
		}
        x[i] = res + d[i];
    }
}

void iterative_seidel(double *x, double *x_old, double **B, double *d) {
    double res;
    for(int j = 0;j < n;j++) {
    	x_old[j] = x[j];
	}
    for(int i = 0;i < n;i++) {
        res = 0.0;
        for(int j = 0;j < n;j++) {
        	res = res + B[i][j]*x[j];
		}
        x[i] = res + d[i];  
    }
}
