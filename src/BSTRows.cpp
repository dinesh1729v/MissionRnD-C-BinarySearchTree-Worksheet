/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
int max1(int a, int b)
{
	return (a > b ? a : b);
}
int get_height1(struct node *root){
	if (root == NULL)return 0;
	int leftHeight = get_height1(root->left);
	int rightHeight = get_height1(root->right);
	return 1 + max1(leftHeight, rightHeight);
}
int getNoOfNodes(struct node * root)
{
	if (root == NULL)return 0;
	int left = getNoOfNodes(root->left);
	int right = getNoOfNodes(root->right);
	return 1 + left + right;
}
void addToArray(struct node* root, int * arr, int * index, int level)
{
	if (root == NULL)return;
	if (level == 0)
	{
		arr[*index] = root->data;
		*index = *index + 1;
	}
	else
	{
		addToArray(root->right, arr, index, level - 1);
		addToArray(root->left, arr, index, level - 1);
	}
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)return NULL;
	int height = get_height1(root),cnt=getNoOfNodes(root);
	int *arr=(int *)malloc(sizeof(int)*cnt),i,j,index=0,rear=0,front=0;
	for (i = 0; i < height; i++)
	{
		addToArray(root, arr, &index,i);
	}
	return arr;
}
/*

int max1(int a, int b)
{
	return (a > b ? a : b);
}
int get_height1(struct node *root){
	if (root == NULL)return 0;
	int leftHeight = get_height1(root->left);
	int rightHeight = get_height1(root->right);
	return 1 + max1(leftHeight, rightHeight);
}
int getNoOfNodes(struct node * root)
{
	if (root == NULL)return 0;
	int left = getNoOfNodes(root->left);
	int right = getNoOfNodes(root->right);
	return 1 + left + right;
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)return NULL;
	int height = get_height1(root),cnt=getNoOfNodes(root);
	int *arr=(int *)malloc(sizeof(int)*cnt),i,j,index=0,rear=0,front=0;
	struct node **queue = (struct node **)calloc((cnt/2),sizeof(struct node *)),*temp=root;
	for (i = 0; i < cnt; i++)
		queue[i] = (struct node *)calloc(1,sizeof(struct node));
	while (index<cnt)
	{
		arr[index++] = temp->data;
		if (temp->right!=NULL)
		{
			rear++;
			queue[rear] = temp->right;
		}
		if (temp->left != NULL)
		{
			rear++;
			queue[rear] = temp->left;
		}
		temp = queue[++front];
	}	
	return arr;
}

*/