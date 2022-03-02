#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Calculator{
	public:
		int result = 0;
		vector<int> v;
		int *arr;
		void cal(int N,int L);
		int sum(int K);
		void print(int a,int b);
		~Calculator();
};

int Calculator::sum(int K) {
	return (K *(K+1))/2;
}

void Calculator::print(int a,int b) {
	for(int i = 0; i<b; i++) {
		cout<<a+i<<" ";
	}
	result = 1;
	return;
}

void Calculator::cal(int N,int L) {
	
	for(int i = L; i<=100; i++) {
		int t = sum(i-1);
		if(((N-t)%i == 0) && (((N-t)/i) >= 0)) {
			int a = (N-t)/i;
			print(a,i);
			break;
		}
	}
	if(result != 1) cout<<"-1";
	return;
}

Calculator::~Calculator() {
	if(result != 1) {
		cout<<"-1"<<endl;
	}
}

int main() {
	Calculator *C = (Calculator *)malloc(sizeof(Calculator));
	int N,L;
	cin>>N>>L;
	C->cal(N,L);
	
	free(C);
	return 0;
}
