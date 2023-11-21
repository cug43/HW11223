#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// だ琩т患癹ㄧ计
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

	// 蝴皚纗翴计瞷Ω计
	int results[11] = { 0 };

	// 家览щ耏ㄢ聋浑 36000 Ω
	for (int i = 0; i < 36000; ++i) {
		// 家览ㄢ聋浑翴计
		int dice1 = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;

		// 璸衡羆翴计
		int total = dice1 + dice2;

		// 仓璸翴计瞷Ω计
		results[total - 2]++;

		// ㄏノだ琩тㄧ计ㄓ簍ボ
		int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		int n = sizeof(arr) / sizeof(arr[0]);

		// 耞7翴瞷Ω计琌钡羆щ耏Ω计せだぇ
		int result = binarySearchRecursive(arr, 0, n - 1, total);
		if (result != -1) {
			results[5]++; // 7翴瞷Ω计
		}
	}

	// 挡狦
	printf("羆翴计\tΩ计\t诀瞯\n");
	for (int i = 0; i < 11; ++i) {
		printf("%d\t%d\t%.4f\n", i + 2, results[i], (float)results[i] / 36000);
	}

	// 耞7翴瞷Ω计琌钡羆щ耏Ω计せだぇ
	float expected_probability = 1.0 / 6.0;
	float actual_probability = (float)results[5] / 36000;

	printf("\n龟悔7翴瞷诀瞯: %.4f\n", actual_probability);
	printf("箇戳诀瞯: %.4f\n", expected_probability);

	return 0;
}
