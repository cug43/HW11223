#include <stdio.h>

void stringReverse(char str[]) {
	// �p�G��e�r�Ť��O�פ�Ŧr���A�~���k
	if (*str != '\0') {
		// ���k�եΨ�ơA�B�z�U�@�Ӧr��
		stringReverse(str + 1);
		// �L�X��e�r��
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
