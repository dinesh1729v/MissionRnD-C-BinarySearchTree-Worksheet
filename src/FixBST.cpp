/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorder(struct node *root, struct node **arr, int *index)
{
	if (root == NULL)return;
	inorder(root->left, arr, index);
	arr[*index] = root;
	*index += 1;
	inorder(root->right, arr, index);
}
void swap(struct node *node1, struct node *node2)
{
	struct node *temp;
	temp = node1->left;
	node1->left = node2->left;
	node2->left = temp;
	temp = node1->right;
	node1->right = node2->right;
	node2->right = temp;

}
void fix_bst(struct node *root){
	if (root == NULL)return;
	int index = 0, cnt = getNoOfNodes(root), i, flag = 0, pos1, pos2, lr1 = 0, lr2 = 0;
	struct node **arr = (struct node**)malloc(cnt*sizeof(struct node*)), *temp1 = NULL, *temp2 = NULL;
	inorder(root, arr, &index);
	for (i = 0; i < cnt - 1; i++)
	{
		if (arr[i]->data > arr[i + 1]->data)
		{
			if (flag == 0)pos1 = i;
			else pos2 = i + 1;
			flag++;
		}
	}
	if (flag == 1)
		pos2 = pos1 + 1;
	int temp;
	temp = arr[pos1]->data;
	arr[pos1]->data = arr[pos2]->data;
	arr[pos2]->data = temp;
}
	/*for (i = 0; i < cnt; i++)
	{
		if (arr[i]->right == arr[pos1])
		{
			temp1 = arr[i];
			lr1 = 1;
		}
		else if (arr[i]->left == arr[pos1])
		{
			temp1 = arr[i];
			lr1 = 0;
		}
		if (arr[i]->right == arr[pos2])
		{
			temp2 = arr[i];
			lr2 = 1;
		}
		else if (arr[i]->left == arr[pos2])
		{
			temp2 = arr[i];
			lr2 = 0;
		}
	}
	if (flag == 2 && (temp1 == NULL))temp1 = root;
	else if (flag == 2 && (temp2 == NULL))temp2 = root;
	swap(arr[pos1], arr[pos2]);
	if (lr1 == 1)temp1->right = arr[pos2];
	else temp1->left = arr[pos2];
	if (lr2 == 1)temp2->right = arr[pos1];
	else temp2->left = arr[pos1];
}*/
/*
if (flag == 1)pos2 = pos1 + 1;
	if ((pos1 == 0) && (pos2==cnt-1))
	{
		arr[pos1 + 1]->left = arr[pos2];

	}

*/