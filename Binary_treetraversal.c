#include<stdio.h>
#include<stdlib.h>
struct node *create();
void display();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node
{
	int data;
	struct node *left,*right;
}*root;
int main()
{
	root=0;
	root=create();
	display();

	return 0;
	
}
struct node *create()
{
	struct node *newnode;
	int x;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	printf("enter -1 to end node \n");
	scanf("%d",&x);
	if(x==-1)
	return 0;
	newnode->data=x;
	printf("enter leftnode\n");
	newnode->left=create();
	printf("enter rightnode\n");
	newnode->right=create();
	return newnode;
	

	
}
void display()
{ int ch;
printf("1.Inorder\n2.preorder\n3.postorder\n");
	printf("eneter your choice\n");
	scanf("%d",&ch);
		
   do
   {
 
	switch(ch)
	{
		case 1:
			printf("\n Inorder\n");
			inorder(root);
			break;
		case 2:
			printf("\n preorder\n");
			preorder(root);
			break;
		case 3:
			printf("\nPostorder\n");
			postorder(root);
			break;
		case 4:
			printf("Exit\n");
			break;
		
	}
}while(ch!=4)
}

void inorder(struct node *root)
{
	if(root==0)
	return ;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if(root==0)
	return ;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
	if(root==0)
	return ;
	postorder(root->left);

	postorder(root->right);
	printf("%d\t",root->data);
	
}


