#include<stdio.h>
#include<stdlib.h>
void inbeg();
void inend();
void inpos();
void display();
void delbeg();
void delend();
void delpos();
void search();
void sort();
void reverse();
struct node
{
	int data;
	struct node *next,*pre;
}*newnode,*temp,*head,*tail,*temp2,*i,*j,*c;
int main()
{
	int n,ch,ch1;
	head=0;
	n=1;
	while(n)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		newnode->pre=0;
		if(head==0)
		head=tail=newnode;
		else
		{
			tail->next=newnode;
			newnode->pre=tail;
			tail=newnode;
		}
		printf("Do you want to continue...(y-1)   (n-0)\n ");
		scanf("%d",&n);
		
	}
	
	
	do
	{
		printf("1-Insertion\n2-Deletion\n3-Searching\n4-Display\n5-sort\n6-reverse\n7-Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					
					printf("1-Insert at beg\n2-Insert at end\n3-Insert at pos\n4-Exit\n");
					printf("Enter your choice\n");
					scanf("%d",&ch1);
					switch(ch1)
					{
						case 1:
							inbeg();
							break;
						case 2:
							inend();
							break;
						case 3:
							inpos();
							break;
						case 4:
							printf("Exit");
							break;
					}
				break;
				case 2:
					printf("1-Del at beg\n2-Del at end\n3-Del at pos\n4-Exit\n");
					printf("Enter your choice\n");
					scanf("%d",&ch1);
					switch(ch1)
					{
						case 1:
							delbeg();
							break;
						case 2:
							delend();
							break;
						case 3:
							delpos();
							break;
						case 4:
							printf("Exit");
							break;
					}
				break;
				case 3:
					search();
					break;
				case 4:
					display();
					break;
				case 5:
					sort();
					break;
				case 6:
					reverse();
					break;
				case 7:
					printf("Exit\n");
					break;
				default:
					printf("Invalid\n");
		}
		
		
	}while(ch!=7);
	return 0;
}

void inbeg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	newnode->pre=0;
	head->pre=newnode;
	newnode->next=head;
	head=newnode;
}

void inend()
{
	newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		newnode->pre=0;
		newnode->pre=tail;
		tail->next=newnode;
		tail=newnode;
		
}

void inpos()
{
	int p,c;
	newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		newnode->pre=0;
		printf("Enter pos\n");
		scanf("%d",&p);
		temp=head;
		c=1;
		while(c<p-1)
		{
			temp=temp->next;
			c++;
			
		}
		temp2=temp->next;
		temp->next=newnode;
		newnode->pre=temp;
		newnode->next=temp2;
		temp2->pre=newnode;
		
}



void delbeg()
{
	temp=head;
	head=head->next;
	head->pre=0;
	free(temp);
}

void delend()
{
	temp=tail;
	tail->pre->next=0;
	tail=tail->pre;
	free(temp);
}
void delpos()
{
	int p,c;
	printf("Enter pos\n");
	scanf("%d",&p);
	c=1;
	temp=head;
	while(c<p)
	{
		temp=temp->next;
		c++;
		}	
	temp->pre->next=temp->next;
	temp->next->pre=temp->pre;
	free(temp);
}


void search()
{
	int s,f;
	printf("Enter search ele\n");
	scanf("%d",&s);
	f=0;
	temp=head;
	while(temp!=0)
	{
		if(temp->data==s)
		{
			f=1;
			break;
		}
		temp=temp->next;
	}
	if(f==1)
	printf("Element is found\n");
	else
	printf("Element is not found\n");
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
void reverse()
{
temp=head;
while(temp!=0)
{
	c=temp->next;
	temp->next=temp->pre;
	temp->pre=c;
	temp=temp->pre;
	}	
	c=head;
	head=tail;
	tail=c;
}
void sort()
{
	int c;
	for(i=head;i->next!=0;i=i->next)
	for(j=i->next;j!=0;j=j->next)
	if(i->data>j->data)
	{
		c=i->data;
		i->data=j->data;
		j->data=c;
	}
}
