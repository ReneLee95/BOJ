#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int M = N;
	int count = 0;

	while (M != 0) {
		M = M / 10;
		count++;
	}
	int count2 = count * 9;
	int num;
	int num2;
	int result = 0;
	for (int i = N - count2; i <= N; i++) {
		num2 = i;
		num = i;
		while (num != 0) {
			num2 = num2 + (num % 10);
			num = num / 10;
		}

		if (num2 == N) {
			result = i;
		}
		if (result != 0) {
			break;
		}
	}
	printf("%d\n", result);

	return 0;
}
