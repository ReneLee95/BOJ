#include <iostream>
#include <algorithm>

using namespace std;

bool compare (int a, int b)
{
	return a > b;
} 

int arr1[50];
int arr2[50];

int main(void)
{
	int a;
	cin>>a;
	for (int i = 0; i<a; i++)
	{
		int b;
		cin>>b;
		arr1[i] = b;
	}
	
	for(int i =0; i<a; i++)
	{
		int c;
		cin>>c;
		arr2[i] = c;
	}
	sort(arr1,arr1+a,compare);
	sort(arr2,arr2+a);
	
	int S = 0;
	for(int i =0; i<a; i++)
	{
		S +=(arr1[i] * arr2[i]);
	}
	
	cout << S<<endl;
}
