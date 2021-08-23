#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <cstring>

using namespace std;

typedef struct node {
	int vertex;
	int distance;
}node;

vector<node> v[100001];
int* depth = (int*)malloc(sizeof(int) * 100001);
int visit[100001] = { 0, };

int maxresult = 0;
int maxvalue = 0;

void search(vector<node>* v,int start,int length) {
	
	if (maxvalue < length) {
		maxvalue = length;
		maxresult = start;
	}
	visit[start] = 1;
	depth[start] = maxresult;
	for (int i = 0; i < v[start].size(); i++) {
		if (visit[v[start][i].vertex] != 1) {
			search(v, v[start][i].vertex, length + v[start][i].distance);
		}
	}
	visit[start] = 0;

}

int main() {
	int k,init,a,b;
	node node;
	vector<int> vervec;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &init);
		vervec.push_back(init);
		while (1) {
			scanf("%d",& a);
			if (a == -1) break;
			else {
				scanf("%d", &b);
				node.vertex = a;
				node.distance = b;
				v[init].push_back(node);
			}
		}
	}
	search(v, 1, 0);
	memset(visit, 0, sizeof(visit));
	search(v, maxresult, 0);

	printf("%d\n", maxvalue);

	return 0;
}
