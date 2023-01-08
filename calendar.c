#include <stdio.h>
#include <windows.h>
#include <conio.h>


#define true 1
#define false 0


//return number of days for each month
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


//decide which day of week the month start
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


//print calendar in output terminal
void getCalendar(day,month,year,saved_attributes){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int startDay = dayOfweek(1,month,year);
	int i;
	
	for(i=0; i<numOfday(month,year)+startDay; i++){
		
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

//save calender into txt file
void saveFile(day,month,year){
	char fileName[15];
	char monthArr[12][10] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
	FILE *fp;
	
	sprintf(fileName, "%d_%d.txt", month,year);
	
	fp = fopen(fileName, "w+");
    fprintf(fp,"\n\t\t\t%s\t%d\n",monthArr[month-1],year);
    fprintf(fp,"\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT	\n\n");
    
    
    int startDay = dayOfweek(1,month,year);
	int i;
	
	for(i=0; i<numOfday(month,year)+startDay; i++){
		
		if(i<startDay){
			fprintf(fp,"\t ");
		}else{

			fprintf(fp,"\t%2d ",i-startDay+1);
		}
			
		if((i+1)%7==0){
			fprintf(fp,"\n");
		}
		
	}
   fclose(fp);
}



int main (void){

	int day, month, year;
	char monthArr[12][10] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
	int i;
	int ch, ch2;

	//to change terminal text color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

    //Save current text attributes
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    
    
    TOP:
    system("cls"); //clear screen
    
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
		system("cls");

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("\n\t\t\t%s\t%d\n",monthArr[month-1],year);
	
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		printf("\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT	\n\n");
	
		SetConsoleTextAttribute(hConsole, saved_attributes);

		getCalendar(day,month,year,saved_attributes);
		
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		printf("\n\n");
		printf("\t\t* Use Left & Right Arrow Switch Month \n");
		printf("\t\t* Use Up & Dowm Arrow Switch Year \n");
		printf("\t\t* Press I For Enter New Date\n");
		printf("\t\t* Press P For Print to File\n");
		printf("\t\t* Press ESC for Exit\n");	
		SetConsoleTextAttribute(hConsole, saved_attributes);
	
	
        if (kbhit) {
            
            ch = getch(); // fetch typed character into ch

            switch(ch){
            case 72: 
      			year++;
      			break;
  			case 80: 
				year--;
      			break;
   			case 75: 
				month--;
				if (month<1){
					month=12;
				}
      			break;
   			case 77: 
				month++;
				if(month>12){
					month=1;
				}
      			break;
			case 105:
				goto TOP;
				break;
      		case 112:
      			saveFile(day,month,year);
      			break;
			default:
				break;
			}
        }
    	
	}while(ch!=27);
	
}



