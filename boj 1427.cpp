#include <iostream>
#include <algorithm>
#include <string.h>

char arr[100];

bool compare(char a, char b)
{
	return a > b;
}

using namespace std;

int main(void)
{
	cin>>arr;
	
	sort(arr,arr+strlen(arr),compare);
	
	for(int i =0; i<strlen(arr); i++)
	{
		cout<<arr[i];
	}
	
}
