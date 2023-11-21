#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���k��ơA�D���Ʋդ����̤j��
int recursiveMaximum(int arr[], int size) {
	// �򥻱��p�G�u���@�Ӥ����ɡA��^�Ӥ���
	if (size == 1) {
		return arr[0];
	}
	else {
		// ���k�եΨ�ơA�D���Ѿl�Ʋժ��̤j��
		int max_of_rest = recursiveMaximum(arr + 1, size - 1);
		// ��^��e�����M�Ѿl�Ʋժ��̤j�Ȥ������j��
		return (arr[0] > max_of_rest) ? arr[0] : max_of_rest;
	}
}

int main() {
	// ��l�ƶüƺؤl
	srand(time(NULL));

	int myArray[6];

	// �ͦ����Ӷüƶ�R�Ʋ�
	for (int i = 0; i < 6; ++i) {
		myArray[i] = rand() % 100; // �ͦ�0��99���ü�
	}

	// ��X���Ӷü�
	printf("Generated Array: ");
	for (int i = 0; i < 6; ++i) {
		printf("%d ", myArray[i]);
	}
	printf("\n");

	// �եλ��k��ƨD���̤j��
	int max_value = recursiveMaximum(myArray, 6);

	// ��X�̤j��
	printf("The maximum value in the array is: %d\n", max_value);

	return 0;
}
