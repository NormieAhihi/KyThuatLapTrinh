#include<stdio.h>

int main() {
	int request, account;
	double balance;
	char name[30];
	FILE *cfPtr;
	 
	if((cfPtr = fopen("client.txt", "r")) == NULL) {
		printf("File could not be opened.\n"); 
	}
	else {
		printf("Enter request\n"
		       "1 - List account with zero balance\n"
			   "2 - List account with credit balance\n"
			   "3 - List account with debit balance\n"
			   "4 - End of run\n? ");
		scanf("%d", &request);
		
		while(request != 4) {
			fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
			switch(request) {
				case 1: 
				    printf("Accounts with zero balances\n");
				    while(!feof(cfPtr)) {
				   	    if(balance == 0) {
				   	    	printf("%-10d%-13s%7.2f\n", account, name, balance); 
						} 
						fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
				    }   
				    break; 
				    
				case 2:
					printf("\nAccounts with credit balances\n");
					while(!feof(cfPtr)) {
				   	    if(balance < 0) {
				   	    	printf("%-10d%-13s%7.2f\n", account, name, balance); 
						} 
						fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
				    }   
				    break; 
				    
				case 3: 
				    printf("\nAccounts with debit balances\n");
					while(!feof(cfPtr)) {
				   	    if(balance > 0) {
				   	    	printf("%-10d%-13s%7.2f\n", account, name, balance); 
						} 
						fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
				    }   
				    break; 
			} 
			
			rewind(cfPtr);
			printf("\n? "); 
			scanf("%d", &request); 
		} 
		printf("End of run.\n");
		fclose(cfPtr); 
	} 
	
	return 0; 
} 





