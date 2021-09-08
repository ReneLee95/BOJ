#include <iostream>

using namespace std;

long long arr[10] = {0, };

void location(int target,int local) {
	while(target != 0) {
		arr[target%10] += local;
		target /= 10;
	}
}

void problem(int first,int last,int local) {
	while(first % 10 != 0 && first <= last) {
		location(first,local);
		first++;
	}
	
	if(first > last) return;
	
	while(last % 10 != 9 && first <= last) {
		location(last,local);
		last--;
	}
	
	
	long long cat = (last / 10 - first / 10 + 1);
	
	for(int i = 0; i<10; i++) {
		arr[i] += cat * local;
	}
	
	problem(first / 10,last / 10,local * 10);
	
}

int main() {
	
	int N;
	
	scanf("%d",&N);
	
	problem(1,N,1);
	
	for(int i = 0; i<10; i++) {
		printf("%d ",arr[i]);
	}
	
	return 0;
	
}
