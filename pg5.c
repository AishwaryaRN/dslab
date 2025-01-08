#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *Left;
struct node *Right;
};
struct node *root=NULL;
struct node *insert(struct node *root,int item)
{
struct node *newnode;
struct node *ptr=root;
struct node *ptr1=NULL;
int flag=0;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=item;
newnode->Left=NULL;
newnode->Right=NULL;
if(root==NULL)
root=newnode;
else if(item<ptr->data)
{
ptr->Left=insert(ptr->Left,item);
return ptr;
}
else if(item>ptr->data)
{
ptr->Right=insert(ptr->Right,item);
return ptr;
}
else
{
flag=1;
printf("ITEM already exist:");
return ptr;
}
}
void inorder(struct node *ptr)
{
if(ptr!=NULL)
{
inorder(ptr->Left);
printf("%d ",ptr->data);
inorder(ptr->Right);
}
}
void preorder(struct node *ptr)
{
if(ptr!=NULL)
{
printf("%d ",ptr->data);
preorder(ptr->Left);
preorder(ptr->Right);
}
}
void postorder(struct node *ptr)
{
if(ptr!=NULL)
{
postorder(ptr->Left);
postorder(ptr->Right);
printf("%d ",ptr->data);
}
}
int main()
{
int a,item;
printf("\n1.Insert \n2.Inorder \n3.Preorder \n4.Postorder \n5.exit \n");
while(1) {
printf("Enter the choice:");
scanf("%d",&a);
switch(a)
{
case 1: printf("Enter the item:");
scanf("%d",&item);
root=insert(root,item);
break;
case 2: printf("Inorder:");
inorder(root);
break;
case 3: printf("Preorder:");
preorder(root);
break;
case 4: printf("Postorder:");
postorder(root);
break;
case 5: exit(0);
default: printf("WRONG CHOICE");
}
}
}



