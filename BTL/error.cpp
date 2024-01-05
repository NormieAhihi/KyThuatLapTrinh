#include"header.h"   
#include"function.h"

// row

double absolute_error_row(double *x, double *x_old) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++) {
    	temp[i] = x[i] - x_old[i];
	}
    res = vector_norm_row(temp);
    return res;
}

double absolute_error_pre_row_single(double *x_fi, int k, double norm_B_row) {
    double res;
    res = vector_norm_row(x_fi)*pow(norm_B_row, k)/(1-norm_B_row);
    return res;
}

double absolute_error_pos_row_single(double *x, double *x_old, double norm_B_row) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++) {
    	temp[i] = x[i] - x_old[i];
	}
    res = vector_norm_row(temp)*norm_B_row/(1-norm_B_row);
    return res;
}

double absolute_error_pre_row_seidel(double *x_fi, int k, double lambda) {
    double res = vector_norm_row(x_fi)*pow(lambda, k)/(1-lambda);
    return res;
}

double absolute_error_pos_row_seidel(double *x, double *x_old, double lambda) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++) {
    	temp[i] = x[i] - x_old[i];
	}
    res = vector_norm_row(temp)*lambda/(1-lambda);
    return res;
}

// column

double absolute_error_col(double *x, double *x_old) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++) {
    	temp[i] = x[i] - x_old[i];
	}
    res = vector_norm_col(temp);
    return res;
}

double absolute_error_pre_col_single(double *x_fi, int k, double frac, double norm_B_col) {
    double res;
    res = frac*vector_norm_col(x_fi)*pow(norm_B_col, k)/(1-norm_B_col);
    return res;
}

double absolute_error_pos_col_single(double *x, double *x_old, double frac, double norm_B_col) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++) {
    	temp[i] = x[i] - x_old[i];
	}
    res = frac*vector_norm_col(temp)*norm_B_col/(1-norm_B_col);
    return res;
}

double absolute_error_pre_col_seidel(double *x_fi, int k, double s, double lambda) {
    double res;
    res = (1-s)*vector_norm_col(x_fi)*pow(lambda, k)/(1-lambda);
    return res;
}

double absolute_error_pos_col_seidel(double *x, double *x_old, double s, double lambda) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++) {
    	temp[i] = x[i] - x_old[i];
	}
    res = (1-s)*vector_norm_col(temp)*lambda/(1-lambda);
    return res;
}





