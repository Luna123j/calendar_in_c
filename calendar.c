#include <stdio.h>
#include <windows.h>

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

int dayOfweek(day,month,year){
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
	char monthArr[12][9] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
	int i;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    
    
	while(true){
  		
		printf("Please enter a day, month, year format in dd-mm-yyyy. \n");
		scanf("\t%d-%d-%d",&day,&month,&year);
		
		if(year > 4902 || year < 1600){
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			printf("Invalid year value. \n");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			continue;
		} 	
			
		if (month > 12 || month <1){
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			printf("Invalid month value. \n");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			continue;
		} 
		
		if(day<1 || day > numOfday(month,year)){
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			printf("invalid day value. \n");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			continue;
		}
		
		break;
	}
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("\n\t\t\t%s\t%d\n",monthArr[month-1],year);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT	\n\n");
	
	SetConsoleTextAttribute(hConsole, saved_attributes);

	int startDay = dayOfweek(1,month,year);
	
	for(i=0; i<numOfday(month,year)+6; i++){
		
		if(i<startDay){
			printf("\t ");
		}else{
			if(i-startDay+1 == day){
				printf("\t");
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
				printf("%2d ",i-startDay+1);
				SetConsoleTextAttribute(hConsole, saved_attributes);
			}else{
				printf("\t%2d ",i-startDay+1);
			}

			
		}
			
		if((i+1)%7==0){
			printf("\n");
		}
		
		
	}
	
	
					
}



