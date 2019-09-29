#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int arr[200001];

map<int,long long> MAP;

int main()
{
	int n,k;
	long long int cnt = 0;
	
	scanf("%d %d",&n,&k);
	
	for(int i = 1; i<=n; i++)
	{
		int temp;
		scanf("%d",&temp);
		arr[i] = arr[i-1] + temp;
	}
	
	for(int i =1; i<=n; i++)
	{
		if(arr[i] == k)
		{
			cnt++;
		}
		cnt +=MAP[arr[i]-k];
		
		MAP[arr[i]]++;
	}
	
	printf("%lld\n",cnt);
	
	return 0;
}
