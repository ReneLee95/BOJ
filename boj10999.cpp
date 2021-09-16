#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int MAX = 1<<21;

class LazyPropagation {
	
	public:
		long long *tree;
		long long *lazy;
		
		LazyPropagation();
		
		void create();
		void update(int start, int end, int sum, int index, int left, int right);
		void update(int start, int end, int sum);
		
		long long query(int start, int end, int index, int left, int right);
		long long query(int start, int end);
		
		void propagation(int index, int left, int right);

};

LazyPropagation::LazyPropagation() {
	
	tree = (long long *)malloc(sizeof(long long) * MAX);
	lazy = (long long *)malloc(sizeof(long long) * MAX);
	
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	
}

void LazyPropagation::create() {
	for(int i = MAX / 2 -1; i>0; i--) {
		tree[i] = tree[i*2] + tree[i*2 + 1];
	}
}

void LazyPropagation::update(int start, int end, int sum, int index, int left, int right) {
	propagation(index ,left ,right);

	if (end < left || right < start) return;
	if (start <= left && right <= end) {
		lazy[index] += sum;
		propagation(index, left, right);
		return;
	}
	int mid = (left + right) / 2;
	update(start, end, sum, (index * 2), left, mid);
	update(start, end, sum, (index * 2 + 1), (mid + 1), right);
	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

void LazyPropagation::update(int start, int end, int sum) { 
	update(start ,end ,sum ,1 ,0 ,(MAX / 2 - 1)); 
}

long long LazyPropagation::query(int start, int end, int index, int left, int right) {
	propagation(index, left, right);

	if (end < left || right < start) return 0;
	if (start <= left && right <= end) return tree[index];
	int mid = (left + right) / 2;
	return query(start ,end ,(index * 2) ,left ,mid) + query(start ,end ,(index * 2 + 1) ,(mid + 1) ,right);
}

long long LazyPropagation::query(int start, int end) { 
	return query(start ,end ,1 ,0 ,(MAX / 2 - 1)); 
}


void LazyPropagation::propagation(int index, int left, int right) {

    if(lazy[index]==0) return;
	if (index < (MAX / 2)) {
		lazy[index * 2] += lazy[index];
		lazy[index * 2 + 1] += lazy[index];
	}
	tree[index] += lazy[index] * (right - left + 1);
	lazy[index] = 0;
}

int main() {
	LazyPropagation LP;
	
	int n, m, k;
	cin>>n>>m>>k;
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &LP.tree[MAX / 2 + i]);
	}
	
	LP.create();

	for (int i = 0; i < m + k; i++) {
		int a, b, c, d;
		cin>>a;
		if (a == 1) {
			cin>>b>>c>>d;
			LP.update(b - 1 ,c - 1 ,d);
		}
		else {
			cin>>b>>c;
			cout<<LP.query(b - 1 ,c - 1)<<'\n';
		}
	}	
	
	return 0;
}
