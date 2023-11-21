#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 遞歸函數，求取數組中的最大值
int recursiveMaximum(int arr[], int size) {
	// 基本情況：只有一個元素時，返回該元素
	if (size == 1) {
		return arr[0];
	}
	else {
		// 遞歸調用函數，求取剩餘數組的最大值
		int max_of_rest = recursiveMaximum(arr + 1, size - 1);
		// 返回當前元素和剩餘數組的最大值中的較大者
		return (arr[0] > max_of_rest) ? arr[0] : max_of_rest;
	}
}

int main() {
	// 初始化亂數種子
	srand(time(NULL));

	int myArray[6];

	// 生成六個亂數填充數組
	for (int i = 0; i < 6; ++i) {
		myArray[i] = rand() % 100; // 生成0到99的亂數
	}

	// 輸出六個亂數
	printf("Generated Array: ");
	for (int i = 0; i < 6; ++i) {
		printf("%d ", myArray[i]);
	}
	printf("\n");

	// 調用遞歸函數求取最大值
	int max_value = recursiveMaximum(myArray, 6);

	// 輸出最大值
	printf("The maximum value in the array is: %d\n", max_value);

	return 0;
}
