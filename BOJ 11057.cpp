#include <iostream>

using namespace std;

int arr[1001][10] = { 0, };
int n;

int dp(int k) {
	if (n == k) {
		int cal = 0;
		for (int i = 0; i < 10; i++) {
			cal = (cal + arr[k - 1][i]) % 10007;
		}
		return cal;
	}
	else {
		for (int i = 1; i < 10; i++) {
			for (int j = i; j <10; j++) {
				arr[k][i] += (arr[k - 1][j])%10007;
			}
		}
		for (int i = 0; i < 10; i++) {
			arr[k][0] += arr[k - 1][i] % 10007;
		}
		arr[k][0] %= 10007;
		return dp(k + 1);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < 10; i++) {
		arr[0][i] = 1;
	}
	cout << dp(1)<<endl;
}
