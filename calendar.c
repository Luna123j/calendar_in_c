#include <stdio.h>
#include <windows.h>
#include <conio.h>


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


void getCalendar(day,month,year,saved_attributes){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
	int startDay = dayOfweek(1,month,year);
	int i;
	
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


int main (void){

	int day, month, year;
	char monthArr[12][9] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
	int i;
	int ch, ch2;
	
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
	

    do{

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("\n\t\t\t%s\t%d\n",monthArr[month-1],year);
	
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		printf("\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT	\n\n");
	
		SetConsoleTextAttribute(hConsole, saved_attributes);

		getCalendar(day,month,year,saved_attributes);
		
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		printf("\n\n");
		printf("\t\t\x1B Use Left & Right Arrow Switch Month \n");
		printf("\t\t\x1b Use Up & Dowm Arrow Switch Year \n");
		printf("\t\t\x1b Press I For Enter New Date\n");
		printf("\t\t\x1b Press P For Print to File\n");
		printf("\t\t\x1b Press ESC for Exit\n");	
		SetConsoleTextAttribute(hConsole, saved_attributes);
	
	
        if (kbhit) {
            // fetch typed character into ch
            ch = getch();
  
//            if(ch = 0xE0){
//            	ch2 = getch();
            	switch(ch){
            	case 72: 
					printf("UP ARROW KEY PRESSED\n");
      				year++;
      				break;
  				case 80: 
				    printf("DOWN ARROW KEY PRESSED\n");
				    year--;
      				break;
   				case 75: 
				    printf("LEFT ARROW KEY PRESSED\n");
				    month--;
      				break;
   				case 77: 
				    printf("RIGHT ARROW KEY PRESSED\n");
				    month++;
      				break;
				}
//			}
//            	
            printf("You have entered : %d, %d\n", ch,ch2);
        }
    	
	}while(ch!=27);
	
}



