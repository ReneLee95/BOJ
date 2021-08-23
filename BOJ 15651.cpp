#include <iostream>

using namespace std;

int n,m;

int arr[8];

void get(int k) {
	if(k == m) {
		for(int i = 0; i<m; i++) {
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	else {
		for(int i = 1; i<=n; i++) {
			arr[k] = i;
			get(k+1);
		}
	}
}

int main() {
	scanf("%d %d",&n,&m);
	get(0);
}
