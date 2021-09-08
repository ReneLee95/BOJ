#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n,m;
int set = 0;

void track(int r,int c,int d);
int **arr;

int main() {
	
	cin>>n>>m;
	
	int r,c,d;
	
	cin>>r>>c>>d;
	
	arr = (int **)malloc(sizeof(int *) * n);
	
	for(int i = 0; i<n; i++) {
		arr[i] = (int *)malloc(sizeof(int) * m);
		memset(arr[i],0,sizeof(arr[i])/sizeof(int));
	}
	
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cin>>arr[i][j];
		}
	}
	
	track(r,c,d);
	cout<<set<<endl;
	
	cout<<endl;
	
	return 0;
	
}

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void track(int r,int c,int d) {
	
	if(arr[r][c] == 0) {
		arr[r][c] = 2;
		set++;
	}

	for(int i = 0; i<4; i++) {
		d = (d + 3) % 4;
		int px = r + dx[d];
		int py = c + dy[d];
		if((px >= 0 && px < n) && (py >= 0 && py < m) && arr[px][py] == 0) { 
			track(px,py,d);
			return;
		}
	}
	
	if(d == 0) {
		int pre = r;
		r = r + 1;
		if((r >= 0 && r < n) && (c >= 0 && c < m) && arr[r][c] != 1) {
			track(r,c,d);
			return;
		}
		r = pre;
	}
	else if(d == 1) {
		int pre = c;
		c = c - 1;
		if((r >= 0 && r < n) && (c >= 0 && c < m) && arr[r][c] != 1) {
			track(r,c,d);
			return;
		}
		c = pre;
	}
	else if(d == 2) {
		int pre = r;
		r = r - 1;
		if((r >= 0 && r < n) && (c >= 0 && c < m) && arr[r][c] != 1) {
			track(r,c,d);
			r = pre;
			return;
		}
		r = pre;
	}
	else if(d == 3) {
		int pre = c;
		c = c + 1;
		if((r >= 0 && r < n) && (c >= 0 && c < m) && arr[r][c] != 1) {
			track(r,c,d);
			c = pre;
			return;
		}
		c = pre;
	}
	return;
}
