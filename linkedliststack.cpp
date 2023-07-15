#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
void peep();
void display();
struct node
{
	int data;
	struct node *next;
}*newnode,*head,*temp;
int top,p;
int main()
{
	int ch;
	top=-1;
	do
	{
	printf("1.Push\n,2.Pop\n,3.Peek\n,4.Peep\n,5.Display\n,6.Exit");
	printf("Enter the choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			peep();
			break;
		case 5:
			display();
			break;
		case 6:
			printf("Exit\n");
		default:
			printf("Invalid number\n");
	}
}while(ch!=6);
return 0;
}
void push()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(top==-1)
	{
		top++;
		head=newnode;
		printf("Element is pushed\n");
	}
	else
	{
		top++;
		temp=head;
		while(temp->next!=0)
		temp=temp->next;
		temp->next=newnode;
     	printf("Element is pushed\n");
	}
}
void pop()
{
		if(top>=0)
	{
	temp=head;
		while(temp->next!=0)
		temp=temp->next;
		temp->next=0;
		top--;
		printf("The poped element is %d\n",temp->data);
		free(temp);
	}	
	else
	printf("The element is underflow\n");
}
void peek()
{
	if(top>=0)
	{
	temp=head;
		while(temp->next!=0)
		temp=temp->next;
		printf("The peek element is %d\n",temp->data);
	}

else
printf("Underflow\n");
}
		
void peep()
{
	temp=head;
	int c;
	c=0;
	printf("Enter the position\n");
	scanf("%d",&p);
	while(c<p-1)
	{
	temp=temp->next;
	c++;
}
	printf("The peep element %d\n",temp->data);
}
void display()
{
	temp=head;
while(temp!=0)
{
	printf("%d\n",temp->data);
	temp=temp->next;
}	
}

