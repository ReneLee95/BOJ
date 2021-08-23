#include <stdio.h>
#include <stdlib.h>


bool visit[1001] = { false, };
bool visit2[1001] = { false, };
int N, M, V;

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
	for (int i = 0; i < Tree->count - 1; i++) {
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
	for (i = 0, curStack = Tree->root; i < Tree->count; i++, curStack = curStack->next) {
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

void DFS(int **arr,int V,tree *Tree) {
	if (Tree->count == 0) {
		push(Tree, V);
	}
	visit[V] = true;
	for (int i = 1; i < N + 1; i++) {
		if (arr[V][i] == 1 && !visit[i]) {
			push(Tree, i);
			DFS(arr,i,Tree);
		}
	}
}

void BFS(int **arr, int V, int N, tree* Tree) {
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
	scanf("%d %d %d", &N, &M, &V);
	int NUM = 1001;
	int** arr = (int **)malloc(sizeof(int *) *NUM);

	for (int i = 0; i < NUM; i++) {
		arr[i] = (int*)malloc(sizeof(int) * NUM);
	}

	int num1, num2;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &num1, &num2);
		arr[num1][num2] = arr[num2][num1] = 1;
	}

	DFS(arr,V,Tree);
	stackprint(Tree);
	printf("\n");

	int K = Tree->count;
	for (int i = 0; i < K; i++) {
		Stackpop(Tree);
	}

	BFS(arr, V, N, Tree);

	K = Tree->count;
	for (int i = 0; i < K; i++) {
		Stackpop(Tree);
	}
	
	for (int i = 0; i <NUM; i++) {
		free(arr[i]);
	}
	free(arr);
	
	free(Tree);

	return 0;
}
