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

	struct node *root = NULL;
	int nums[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++){
		root = add_node_spec(root, nums[i]);
	}

	int h = get_height(root);
	int ls = get_left_subtree_sum(root);
	int rs = get_right_subtree_sum(root);
	int ans[3] = { 10, 0, 54 };

	int actualans[3] = { h, ls, rs };
	for (int i = 0; i < 3; i++)
		printf("%d  %d\n", actualans[i], ans[i]);
	//Use it for testing ,Creating BST etc
	getchar();
	return 0;
}
