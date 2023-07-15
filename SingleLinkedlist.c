#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*newnode,*head,*temp,*temp2,*i,*j;
int ch,d,p,f,v,c,s;
void inbeg();
void inend();
void inpos();
void delbeg();
void delend();
void delpos();
void search();
void sort();
void display();
main()
{
int n=1,m;
head=0;
while(n)
{
	newnode=(struct node*)malloc (sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0)
		head=newnode;
	else
	temp->next=newnode;
	temp=newnode;
	printf("Do you wish to continue[1,0]:\n");
	scanf("%d",&n);
	
	}
do
{
	printf("1.Insert--->1\n2.delete--->2\n3.search--->3\n,4.sort--->4\n5.display---->5\n");
	printf("enter your choice\n");
	
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			{
				printf("******Insertion*******\n");
				printf("1.Insertionbeginning---1\n2.InsertionEnd-----2\n3.Insertionposition----3\n");
				printf("enter m\n");
				scanf("%d",&m);
				switch(m)
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
				}
				break;
				
			}
		case 2:
			{
				printf("*******Deletion*******\n");
				printf("1.deletionbeginning----1\n2.DeletionEnd----2\n3.Deletionposition\n");
				printf("enter your choice\n");
				
				scanf("%d",&m);
				switch(m)
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
					
				}
				break;
				
			}
		case 3:
			printf("*****Search*****");
			search();
			break;
		case 4:
			printf("*****Sort****");
			sort();
			break;
		case 5:
			printf("*****Display*****");
			display();
			break;
		case 6:
			printf("******Exit******\n");
			break;
				
	}
}while(ch!=5);
return 0;
}
void inbeg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
	temp=head;
	while(temp!=0){
		printf("%d\n",temp->data);
		temp=temp->next;
		
	}
}
void inend()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	temp=head;
	while(temp->next!=0)
	temp=temp->next;
	
	temp->next=newnode;
	temp=head;
	while(temp!=0)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
		
	}
}

void inpos()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	d=1;
	printf("enter position\n");
	scanf("%d",&p);
	temp=head;
	while(d<p-1)
	{
		temp=temp->next;
		d++;
		
	}
	newnode->next=temp->next;
	temp->next=newnode;
	temp=head;
	while(temp!=0)
	{
		printf("%d",temp->data);
		temp=temp->next;
		
	}
	
	
}
void delbeg()
{
	temp=head;
	head=temp->next;
	free(temp);
	temp=head;
	while(temp!=0)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
void delend()
{
	temp=head;
	while(temp->next->next!=0)
	temp=temp->next;
	temp->next=0;
	free(temp->next);
	temp=head;
	while(temp!=0)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	
}	
void delpos()
{
	d=1;
	printf("enter position:\n");
	scanf("%d",&p);
	temp=head;
	while(d<p-1)
	{
		temp=temp->next;
		d++;
		
	}
	temp2=temp->next;
	temp->next=temp->next->next;
	free(temp2);
	temp=head;
	while(temp!=0)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
		
	}
}
void search()
{
	printf("enter ele:\n");
	scanf("%d",&v);
	temp=head;
	while(temp!=0)
	{
		f=0;
		if(temp->data==v)
		{
			f=1;
			break;
			
		}
		temp=temp->next;
		
	}
	if(f==1)
	printf("%d is found\n",v);
	else
	printf("%d is not found\n",v);
	
}
void sort()
{
	for(i=head;i->next!=0;i=i->next)
	for(j=i->next;j!=0;j=j->next)
	
		if(i->data>j->data)
		{
		
		c=i->data;
		i->data=j->data;
		j->data=c;
     	}
    temp=head;
    while(temp!=0)
    {
    	printf("%d\t",temp->data);
    	temp=temp->next;
    	
	}
	
}
void display()
{
 temp=head;
    while(temp!=0)
    {
    	printf("\t%d\t",temp->data);
    	temp=temp->next;
    	
	}	
}
	

