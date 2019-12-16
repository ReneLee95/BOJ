#include <iostream>
#include <algorithm>

#define fio ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

int main()
{
	int N;
	cin>>N;
	int arr[1001];
	
	for(int i =0; i<N; i++)
	{
		int k;
		cin>>k;
		arr[i] = k;
	}
	sort(arr,arr+N);
	
	int cnt = 0;
	
	for(int i =0; i<N; i++)
	{
		if(arr[i] > cnt+1)
		{
			break;
		}
		cnt +=arr[i];
	}
	
	cout<<cnt+1<<endl;
}
