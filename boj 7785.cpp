#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

node *root;

void init(int data)
{
	node *newNode = (node *)malloc(sizeof(node));
	root->data = data;
	newNode->left =NULL;
	newNode->right = NULL;
}

node *addchild(node *parent,int data)
{
	if((parent->left !=NULL) &&(parent->right !=NULL))
	{
		cout<<"tree's full"<<endl;
		return 0;
	}
	node *newNode = (node *)malloc(sizeof(node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	
	if(parent->left = NULL)
	{
		parent->left = newNode;
	}
	
	else if(parent->right = NULL)
	{
		parent->right = newNode;
	}
	return newNode;
}

void preOrder(node *r)
{
	cout<<r->data<<endl;
	if(r->left) preOrder(r->left);
	if(r->right) preOrder(r->right);
}

int main()
{
	int treeroot;
	cin>>treeroot;
	init(treeroot);
	
	int firstL =0;
	int firstR =0;
	
	cin>>firstL>>firstR;

	node *L = addchild(root,firstL);
	node *R = addchild(root,firstR);
	
	int k =0;
	
	while(scanf("%d",&k)!=EOF)
	{
		if(k<treeroot)
		{
			addchild(L,k);
		}
		else
		{
			addchild(R,k);
		}
	}
	preOrder(root);
}
