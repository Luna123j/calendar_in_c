#include <stdio.h>

int main (void){
	int month, year;
	
	while(1){
		printf("Please enter a month, year format in mm-yyyy. \n");
		scanf("%d-%d",&month,&year);
		
		if (month > 12 || month <1){
			printf("Invalid month value. \n");
			continue;
		} 
		
		if(year > 4902 || year < 1600){
			printf("Invalid year value. \n");
			continue;
		} 
		
		break;
	}
		

	
	
}

