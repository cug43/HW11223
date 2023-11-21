#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �G���d�䪺���j���
int binarySearchRecursive(int arr[], int start, int end, int key) {
	if (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] > key)
			return binarySearchRecursive(arr, start, mid - 1, key);

		return binarySearchRecursive(arr, mid + 1, end, key);
	}

	return -1;
}

int main() {
	srand(time(NULL));

	// �ŧi�@���}�C�x�s�U�I�ƥX�{������
	int results[11] = { 0 };

	// �������Y������l 36000 ��
	for (int i = 0; i < 36000; ++i) {
		// ����������l���I��
		int dice1 = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;

		// �p���`�I��
		int total = dice1 + dice2;

		// �֭p�U�I�ƥX�{������
		results[total - 2]++;

		// �ϥΤG���d���ƨӺt��
		int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		int n = sizeof(arr) / sizeof(arr[0]);

		// �P�_7�I�X�{�����ƬO�_�����`���Y���ƪ��������@
		int result = binarySearchRecursive(arr, 0, n - 1, total);
		if (result != -1) {
			results[5]++; // 7�I�X�{���ƥ[�@
		}
	}

	// �C�L���G
	printf("�`�I��\t����\t���v\n");
	for (int i = 0; i < 11; ++i) {
		printf("%d\t%d\t%.4f\n", i + 2, results[i], (float)results[i] / 36000);
	}

	// �P�_7�I�X�{�����ƬO�_�����`���Y���ƪ��������@
	float expected_probability = 1.0 / 6.0;
	float actual_probability = (float)results[5] / 36000;

	printf("\n���7�I�X�{�����v: %.4f\n", actual_probability);
	printf("�w�����v: %.4f\n", expected_probability);

	return 0;
}
