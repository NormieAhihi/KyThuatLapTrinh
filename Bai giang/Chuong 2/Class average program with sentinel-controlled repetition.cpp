#include<stdio.h>

int main() {
	int counter = 0;
	int grade;
	int total = 0;
	
	float average; 
	  
	printf("Enter grade, -1 to end: ");
	scanf("%d", &grade);
	
	while(grade != -1) {
		total += grade;
		counter++; 
		printf("Enter grade, -1 to end: ");
	    scanf("%d", &grade);
	} 
	 
	if(counter != 0) {
		average = (float) total / counter;
		printf("Class average is %.2f\n", average); 
	} else {
		printf("No grade were entered\n"); 
	} 
	 
	return 0; 
}

