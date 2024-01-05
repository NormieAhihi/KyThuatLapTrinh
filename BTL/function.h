#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

extern ofstream out;

extern int precision;
extern int n, k;
extern double **A, **B, **B_col;
extern double *b, *d;
extern double epsilon, frac;

void setcolor(int color);
void note();
void submenu_input();
void submenu_se(int mode);
void border(int w);
void solve(int mode);

void print_matrix(double **temp);
void print_vector(double *temp);
void print_vector1(double *temp);

bool row_diag_dom(double **temp);
bool col_diag_dom(double **temp);

double vector_norm_row(double *temp);
double vector_norm_col(double *temp);
double matrix_norm_row(double **temp);
double matrix_norm_col(double **temp);

double absolute_error_row(double *x, double *x_old);
double absolute_error_pos_row_single(double *x, double *x_old, double norm_B);
double absolute_error_pre_row_single(double *x_fi, int k, double norm_B);
double absolute_error_pos_row_seidel(double *x, double *x_old, double lambda);
double absolute_error_pre_row_seidel(double *x_fi, int k, double lambda);

double absolute_error_col(double *x, double *x_old);
double absolute_error_pos_col_single(double *x, double *x_old, double frac, double norm_B_col);
double absolute_error_pre_col_single(double *x_fi, int k, double frac, double norm_B_col);
double absolute_error_pos_col_seidel(double *x, double *x_old, double s, double lambda);
double absolute_error_pre_col_seidel(double *x_fi, int k, double s, double lambda);

double lambda_row(double **B);
double lambda_col(double **B);
double cal_s(double **B);
void cal_Bd(double **B, double *d, double **A, double *b);
void cal_B_col(double **B_col, double **A, double *b);
double cal_frac(double **A);

void iterative_single(double *x, double *x_old, double **B, double *d);
void iterative_seidel(double *x, double *x_old, double **B, double *d);

void solve_iterative_single_row_eps(double **B, double *d, double epsilon, int type);
void solve_iterative_seidel_row_eps(double **B, double *d, double epsilon, int type);
void solve_iterative_single_col_eps(double **B, double *d, double **B_col, double epsilon, double frac, int type);
void solve_iterative_seidel_col_eps(double **B, double *d, double **B_col, double epsilon, int type);

void solve_iterative_single_row_con(double **B, double *d, double epsilon);
void solve_iterative_seidel_row_con(double **B, double *d, double epsilon);
void solve_iterative_single_col_con(double **B, double *d, double epsilon);
void solve_iterative_seidel_col_con(double **B, double *d, double epsilon);

void solve_iterative_single_row_k(double **B, double *d, int k, int type);
void solve_iterative_seidel_row_k(double **B, double *d, int k, int type);
void solve_iterative_single_col_k(double **B, double *d, double **B_col, double frac, int k, int type);
void solve_iterative_seidel_col_k(double **B, double *d, double **B_col, int k, int type);

#endif // FUNCTION_H_INCLUDED
