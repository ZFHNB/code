#include <stdio.h>
#include <time.h>

int main() {
	enum Week {sun, mon, tue, wed, thu, fri, sat};
	struct tm *p;
	time_t t;

	time(&t);
	p = localtime(&t);

	int today = p->tm_wday;

	switch (today) {
		case mon:
		case tue:
		case wed:
		case thu:
		case fri:
			printf("¸É»î T_T\n");
			break;
		case sat:
		case sun:
			printf("·Å¼Ù ^_^\n");
			break;
		default:
			printf("Error! \n");
	}
	return 0;
}
