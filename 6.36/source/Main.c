#include <stdio.h>

void stringReverse(char str[]) {
	// 如果當前字符不是終止空字元，繼續遞歸
	if (*str != '\0') {
		// 遞歸調用函數，處理下一個字符
		stringReverse(str + 1);
		// 印出當前字符
		printf("%c", *str);
	}
}

int main() {
	char myString[] = "How are you!";

	printf("Original String: %s\n", myString);
	printf("Reversed String: ");
	stringReverse(myString);
	printf("\n");

	return 0;
}
