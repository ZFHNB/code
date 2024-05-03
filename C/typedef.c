#include <stdio.h>
#include <stdlib.h>

typedef struct Date{
	int year;
	int month;
	int day;
}DATE, *PDATE;

int main()
{
	PDATE date = NULL;
	
	date = (PDATE)malloc(sizeof(DATE));
	if(date == NULL)
	{
		printf("ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		exit(1);
	}
	
	date->year = 2024;
	date->month = 3;
	date->day = 7;
	
	printf("%d.%d.%d",date->year, date->month, date->day);
	
	free(date);
	
	return 0;
}
