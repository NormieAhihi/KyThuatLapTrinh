#include<stdio.h>

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }; 
months operator++(months& m, int);

int main() {
	enum months month;
	
	const char *monthName[] = { "", "January", "February", "March", "April", "May", "June", "July",
	                                "August", "September", "October", "November", "December"}; 
	for(month = JAN; month <= DEC; month++) {
		printf("%2d%11s\n", month, monthName[month]); 
	} 
	
	return 0; 
} 

months operator++(months& m, int){
   m = months(m+1);
   return m; 
}

