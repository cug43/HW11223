#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int results[11] = { 0 };

	for (int i = 0; i < 36000; ++i) 
	{
		int dice1 = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;
		int total = dice1 + dice2;
		results[total - 2]++;
	}

	printf("總點數\t次數\t機率\n");
	for (int i = 0; i < 11; ++i) 
	{
		printf("%d\t%d\t%.4f\n", i + 2, results[i], (float)results[i] / 36000);
	}
	return 0;
}
