#include <stdio.h>


int numOfday(month,year){
	switch(month){
	case 1:
		return (31);
		break;
	case 2:
		if(year%4 == 0 || year%400 == 0 || year%100 == 0){
			return (29);
			break;
		}else{
			return (28);
					break;
		}
	case 3:
		return (31);
		break;
	case 4:
		return (30);
		break;
	case 5:
		return (31);
		break;
	case 6:
		return (30);
		break;
	case 7:
		return (31);
		break;
	case 8:
		return (31);
		break;
	case 9:
		return (30);
		break;
	case 10:
		return (31);
		break;
	case 11:
		return (30);
		break;
	case 12:
		return (31);
		break;
	}
}

int main (void){
	int day, month, year;
	
	while(1){
		printf("Please enter a day, month, year format in dd-mm-yyyy. \n");
		scanf("%d-%d-%d",&day,&month,&year);
		
		if(year > 4902 || year < 1600){
			printf("Invalid year value. \n");
			continue;
		} 	
			
		if (month > 12 || month <1){
			printf("Invalid month value. \n");
			continue;
		} 
		

		
		if(day<1 || day > numOfday(month,year)){
			printf("invalid day value. \n");
			continue;
		}
		
		break;
	}
	
	
				
}

