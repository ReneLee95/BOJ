#include <stdio.h>
#include <stdlib.h>

#define total 100

int sum = 0;
int foundsum = 0;
int cat = 0;

void found(int* arr);
void swap(int* arr, int num1, int num2);
void Quicksort(int* arr, int start, int end);

int main() {
	int* arr = (int*)malloc(sizeof(int) * 9);
	int* cpyarr = (int*)malloc(sizeof(int) * 7);

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	found(arr);
	Quicksort(arr, 0, 8);

	for (int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
}

void found(int* arr) {
	int A, B;
	int index = 0;
	int catsum = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			foundsum = 0;
			catsum = sum;
			foundsum = catsum - (arr[i] + arr[j]);
			if (total == foundsum) {
				cat++;
				arr[i] = 100;
				arr[j] = 101;
				break;
			}
		}
		if (cat != 0) {
			break;
		}
	}

}

void swap(int* arr, int num1, int num2) {
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
}

void Quicksort(int* arr, int start, int end) {
	int pivot = arr[start];
	int left = start + 1;
	int right = end;
	if (start == end) return;
	while (left <= right) {
		while (arr[left] < pivot) {
			left++;
		}
		while (arr[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(arr, left, right);
		}
	}
	if (start < end) {
		swap(arr, start, right);
		Quicksort(arr, start, right - 1);
		Quicksort(arr, right + 1, end);
	}
	return;
}
