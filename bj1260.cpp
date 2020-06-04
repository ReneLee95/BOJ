#include <stdio.h>
#include <stdlib.h>

int arr[1001][1001] = {0, };
bool visit[1001] = {false, };
bool visit2[1001] = {false, };

typedef struct stack {
	int data;
	struct stack* next;
	struct stack* prev;
}stack;

typedef struct tree {
	struct stack* root;
	int count;
}tree;

tree* init() {
	tree* Tree = (tree*)malloc(sizeof(tree));
	if (Tree == NULL) {
		printf("err\n");
	}
	else {
		Tree->root = NULL;
		Tree->count = 0;
		return Tree;
	}
}

void push(tree* Tree, int data) {
	stack* newStack = (stack*)malloc(sizeof(stack));
	stack* preStack = Tree->root;
	newStack->data = data;
	if (Tree->count == 0) {
		newStack->next = newStack;
		newStack->prev = newStack;
		Tree->root = newStack;
	}
	else {
		for (int i = 0; i < Tree->count - 1; i++) {
			preStack = preStack->next;
		}
		newStack->next = preStack->next;
		preStack->next = newStack;
		newStack->prev = preStack;
		newStack->next->prev = newStack;
	}
	Tree->count++;
}

void Stackpop(tree* Tree) {
	stack* deleteStack = Tree->root;
	for (int i = 0; i < Tree->count-1; i++) {
		deleteStack = deleteStack->next;
	}
	deleteStack->prev->next = Tree->root;
	Tree->root->prev = deleteStack->prev;
	free(deleteStack);
	Tree->count--;
}

void Queuepop(tree* Tree) {
	stack* deleteQueue = Tree->root;
	Tree->root = Tree->root->next;
	deleteQueue->prev->next = deleteQueue->next;
	deleteQueue->next->prev = deleteQueue->prev;
	free(deleteQueue);
	Tree->count--;
}

void stackprint(tree* Tree) {
	stack* curStack;
	int i;
	for (i = 0, curStack = Tree->root->prev; i < Tree->count; i++, curStack = curStack->prev) {
		printf("%d ", curStack->data);
	}
	//return curStack->data;
}

int catStack(tree* Tree) {
	stack* curStack = Tree->root;
	return curStack->prev->data;
}

int catQueue(tree* Tree) {
	stack* curStack = Tree->root;
	return curStack->data;
}

void DFS(int (*arr)[1001], bool visit[], int V,int N, tree* Tree) {
	if (Tree->count != 0) {
		Stackpop(Tree);
	}
	else {
		visit[V] = 1;
		printf("%d ", V);
		push(Tree, V);
	}

	if (Tree->count == 0) return;

	for (int i = 1; i <= N+1; i++) {
		if (arr[V][i] == 1 && !visit[i] ) {
			visit[i] = true;
			push(Tree, i);
			V = catStack(Tree);
			printf("%d ", i);
			DFS(arr, visit, V, N, Tree);
		}
	}

}

void BFS(int (*arr)[1001], bool visit2[], int V, int N, tree* Tree) {
	visit2[V] = 1;
	push(Tree, V);
	while (Tree->count != 0) {
		V = catQueue(Tree);
		printf("%d ", V);
		for (int i = 1; i <= N; i++) {
			if (arr[V][i] == 1 && !visit2[i]) {
				visit2[i] = true;
				push(Tree, i);
			}
		}
		Queuepop(Tree);
	}
}

int main() {

	tree* Tree = init();
	
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	N = N + 1;

	int num1,num2;

	for(int i = 0; i<M; i++) {
		scanf("%d %d",&num1,&num2);
		arr[num1][num2] = arr[num2][num1] = 1;
	}

	int inserNum = 0;
	
	DFS(arr, visit, V, N, Tree);
	printf("\n");
	
	for(int i = 0; i<Tree->count; i++) {
		Stackpop(Tree);
	}
	
	BFS(arr, visit2, V, N, Tree);

	return 0;
}
