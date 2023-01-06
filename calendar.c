#include <stdio.h>

#define true 1
#define false 0

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

int dayOfweek(int day,int month,int year){
	static int t[] = { 0, 3, 2, 5, 0, 3,
                    5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4
            - year / 100
            + year / 400
            + t[month - 1] + day)
        % 7;
}

int main (void){
	int day, month, year;
	int i;
	while(true){
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
	
	printf("\n\tMON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN	\n");
	
	for(i=0; i<numOfday(month,year); i++){
		
			printf("\t%2d ",i+1);
			
			if((i+1)%7==0){
				printf("\n");
			}
	}
					
}



