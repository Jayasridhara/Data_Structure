#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
	
};
struct node *insert(struct node *,int);
struct node *getinput(int);
void inorder(struct node *);
int main()
{
	struct node *root;
	root=0;
	root=insert(root,6);
	root=insert(root,5);
	root=insert(root,9);
	root=insert(root,5);
	root=insert(root,4);
	inorder(root);
	return 0;
	

}
struct node *insert(struct node *root,int x)


{
	if(root==0)
	root=getinput(x);
	else if(x<=root->data)
	root->left=insert(root->left,x);
	else
	root->right=insert(root->right,x);
	
return root;	
}
struct node *getinput(int x)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->left=newnode->right=0;
	return newnode;
	
}
void inorder(struct node *root)
{
	if(root==0)
	return ;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}





