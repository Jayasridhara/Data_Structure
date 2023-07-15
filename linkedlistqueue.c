#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
	int data;
	struct node *next;
}*newnode,*rear,*front,*temp;
int main()
{
	int ch;
	front=rear=0;
	do
	{
	printf("1.enqueue\n,2.dequeue\n,3.Display\n,4.Exit\n");
	printf("Enter the choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Exit\n");
		default:
			printf("Invalid number\n");
	}
}while(ch!=4);
return 0;
}
void enqueue()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data\n");
scanf("%d",&newnode->data);
newnode->next=0;
if(front==0&&rear==0)
front=rear=newnode;
else
{
	rear->next=newnode;
	rear=newnode;
}
}
void dequeue()
{
	if(front==0&&rear==0)
	printf("Queue is underflow");
	else if(front->next==0)
     	{
		temp=front;
		printf("%d\n",front->data);
	     front=rear=0;
	     free(temp);
		}
			else
			{
				temp=front;
					printf("%d\n",front->data);
				front=front->next;
				free(temp);
			}
	}
	void display()
	{
		if(front==0&&rear==0)
		printf("Queue is underflow\n");
		else
		{
			temp=front;
			while(temp!=0)
			{
				printf("%d\n",temp->data);
				temp=temp->next;
			}
		}
	}
