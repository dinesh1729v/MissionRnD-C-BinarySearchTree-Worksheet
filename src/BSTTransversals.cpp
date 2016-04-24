/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorderWrapper(struct node *root, int* arr, int *index)
{
	if (root == NULL)return;
	inorderWrapper(root->left, arr, index);
	arr[*index] = root->data;
	*index+=1;
	inorderWrapper(root->right, arr, index);
}
void preorderWrapper(struct node *root, int* arr, int *index)
{
	if (root == NULL)return;
	arr[*index] = root->data;
	*index+=1;
	preorderWrapper(root->left, arr, index);
	preorderWrapper(root->right, arr, index);
}
void postorderWrapper(struct node* root, int *arr, int *index)
{
	if (root == NULL)return;
	postorderWrapper(root->left, arr, index);
	postorderWrapper(root->right, arr, index);
	arr[*index] = root->data;
	*index+=1;
}
void inorder(struct node *root, int *arr){
	if (root == NULL||arr==NULL)return;
	int index = 0;
	inorderWrapper(root,arr,&index);
}
void preorder(struct node *root, int *arr){
	if (root == NULL||arr==NULL)return;
	int index=0;
	preorderWrapper(root, arr, &index);
}
void postorder(struct node *root, int *arr){
	if (root == NULL||arr==NULL)return;
	int index=0;
	postorderWrapper(root, arr, &index);
}

