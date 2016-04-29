/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return newNode(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

int main(){

	//Use it for testing ,Creating BST etc
	struct node *root = NULL;
	int nums[20] = { 50, 25, 75, 15, 35, 90, 5, 17, 45, 120, 1, 2, 19, 39, 49, 100 };

	for (int i = 0; i < 16; i++){
		root = add_node_spec(root, nums[i]);
	}
	struct node *swaplist[2];
	int originaldata[2];
	swaplist[0] = root->left->left->right->right;
	swaplist[1] = root;
	originaldata[0] = swaplist[0]->data;
	originaldata[1] = swaplist[1]->data;

	swap_nodes(swaplist[0], swaplist[1]);

	fix_bst(root);
	getchar();
	return 0;
}
