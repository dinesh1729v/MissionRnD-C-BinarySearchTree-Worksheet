/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int min(int a, int b)
{
	if (a == -1)return b;
	if (b == -1)return a;
	return (a < b ? a : b);
}

struct node* findParent(struct node* root, struct node *temp){

	if (root == NULL)	return NULL;

	if ((root->left != NULL) && (root->left->data == temp->data))
		return root;
	if ((root->right != NULL) && (root->right->data == temp->data))
		return root;
	if (root->left != NULL)
		return findParent(root->left, temp);
	if (root->right != NULL)
		return findParent(root->right, temp);

	return NULL;
}
int getMinHeight(struct node *root)
{
	if (root == NULL)return -1;
	if (root->left == NULL && root->right == NULL)return 0;
	int leftHeight = getMinHeight(root->left);
	int rightHeight = getMinHeight(root->right);
	return 1 + min(leftHeight, rightHeight);
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int minHeight = getMinHeight(temp);
	if (minHeight==1)
		return minHeight;

	struct node* parent = findParent(root, temp);

	if (parent != NULL){
		int parentDist = get_closest_leaf_distance(root, parent);

		int minDist = min(parentDist, minHeight);

		if (minDist == parentDist)
			return 1 + parentDist;
	}
	return minHeight;
}