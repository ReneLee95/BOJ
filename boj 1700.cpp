#include <iostream>
#include <algorithm>

#define fio ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

int main()
{
	int N = 0, K = 0;
	int cnt = 0;
	cin >> N >> K;

	int arr[101] = { 0, };

	for (int i = 0; i < K; i++)
	{
		int number = 0;
		cin >> number;
		arr[i] = number;
	}

	sort(arr, arr + K);

	for (int i = 2; i < K; i++)
	{
		if (arr[1] < arr[i] &&arr[0] !=arr[i] &&arr[1]!=arr[0])
		{
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			arr[i] = 0;

			int temp2 = arr[0];
			arr[0] = arr[1];
			arr[1] = temp2;

			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
