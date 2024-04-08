#include <stdlib.h>
#include <time.h>

void generateRandomArray(int *array, int length, int maxValue) {
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    array[i] = rand() % maxValue;
  }
}

int main() {
  	int maxTime = 5000;
  	int maxSize = 110;
  	int maxValue = 200;
  
  	while (maxTime--) {
  		int array[maxSize];
  		
  		int length = sizeof(array) / sizeof(array[0]);
  	}

  return 0;
}
