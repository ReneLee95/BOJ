#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b)
{
	return a < b;
}

void swaps(int arr[], int len, int target)
{
	int i = 0;
	int j = 0;
	int temp;
	while (arr[i] != 0)
	{
		if (arr[i] == target)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
		i++;
	}
	for (int i = j + 1; i < len-1; i++)
	{
		for (int i = j + 1; j < len-1; j++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp2;
				temp2 = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = arr[i];
			}
		}
	}
	return;
}
int main(void)
{
	int len;
	long long int target;
	int arr[1001] = { 0, };
	cin >> len;
	cin >> target;
	for (int i = 0; i < len; i++)
	{
		int arrnum;
		cin >> arrnum;
		arr[i] = arrnum;
	}

	sort(arr, arr + len, compare);
	swaps(arr, len, target);

	cout << "--------------------" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}
