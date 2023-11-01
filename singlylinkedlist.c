#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* next;
}*start;

void insert_at_beg(int x)
{
struct node* newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the data :");
scanf("%d",&x);
if(start==NULL)
{
newnode->data=x;
newnode->next=NULL;
start=newnode;
}
else
{
newnode->data=x;
newnode->next=start;
start=newnode;
}
}

void insert_at_end(int x)
{
struct node* ptr;
struct node* newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the data :");
scanf("%d",&x);
newnode->data=x;
newnode->next=NULL;
if(start==NULL)
{ newnode->data=x;
newnode->next=NULL;
start=newnode;
}
else 
{
ptr=start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=newnode;
}
}

void insert_at_specific_position(int x,int pos)
{
struct node* ptr;
ptr=start;
int i=0;
struct node*newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the data :");
scanf("%d",&x);
printf("Enter the position :");
scanf("%d",&pos);
newnode->data=x;
if(start==NULL)
{
start=newnode;
newnode->next=NULL;
}
else
{
while(i<(pos-2))
{
ptr=ptr->next;
i++;
}
newnode->next=ptr->next;
ptr->next=newnode;
}
}

void delete_from_beg()
{
struct node* ptr;
if(start==NULL)
{
printf("\nUNDERFLOW ! ! !");

}
else
{
ptr=start;
start=start->next;
printf("\n%d is deleted...",ptr->data);
free(ptr);
}
}

void delete_from_end()
{
struct node* ptr,*preptr;
if(start==NULL)
{
printf("\nUNDERFLOW ! ! !");

}
else
{
ptr=start;
if(ptr->next==NULL)
{
printf("\n%d is deleted...",ptr->data);
start=NULL;
free(ptr);
}
else
{
while(ptr->next!=NULL)
{
preptr=ptr;
ptr=ptr->next;
}
preptr->next=NULL;
printf("\n%d is deleted...",ptr->data);
free(ptr);
}
}
}

void delete_from_specific_position(int pos)
{
struct node* ptr,* temp;
int i=0;
if(start==NULL)
{
printf("\nUNDERFLOW ! ! !");

}
else
{
printf("\nEnter the position :");
scanf("%d",&pos);
ptr=start;
if(ptr->next==NULL)
{
printf("\n%d is deleted...",ptr->data);
start=NULL;
free(ptr);
}
else
{
while(i<(pos-1))
{
temp=ptr;
ptr=ptr->next;
i++;
}
temp->next=ptr->next;
printf("\n%d is deleted...",ptr->data);
free(ptr);
}
}
}
void display()
{
struct node *ptr=start;
if(ptr==NULL)
{
printf("\nSORRY ! NO ELEMENT ! ! !");
}
else
{
while(ptr!=NULL)
{
printf("%d -> ",ptr->data);
ptr=ptr->next;
}
}
}
void main()
{
start=NULL;

int ch,x,pos;
int z=1;
while(z) 
{
printf("\n\n-----------------------------------------\n");
printf("1. Insert at the begining\n");
printf("2. Insert at the end\n");
printf("3. Insert at a specific position\n");
printf("4. Delete from begining\n");
printf("5. Delete from the end\n");
printf("6. Delete from a specific position\n");
printf("7. Display\n");
printf("8. Exit");
printf("\n-------------------------------------------\n");
printf("ENTER A CHOICE :");
scanf("%d",&ch);
switch(ch)
{
case 1: insert_at_beg(x);
break;
case 2: insert_at_end(x);
break;
case 3: insert_at_specific_position(x,pos);
break;
case 4: delete_from_beg();
break;
case 5: delete_from_end();
break;
case 6: delete_from_specific_position(pos);
break;
case 7: display();
break;
case 8: exit(0);
break;
default : printf("\nOOPS ! WRONG CHOICE !");
break;
}

printf(" \n Do you want to cotinue ? press 1 or 0 ");
scanf("%d",&x);
}
}
