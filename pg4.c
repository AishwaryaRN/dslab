#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node* right;
struct node* left;
};
struct node*root=NULL;
void append()
{
struct node* temp;
temp=(struct node*) malloc(sizeof(struct node));
printf("Enter node data:");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;
}
else
{
struct node *p=root;
while(p->right!=NULL)
{
p=p->right;
}
p->right=temp;
temp->left=p;
}
}
void atbegin()
{
struct node*temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter node data:");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;
}
else
{
temp->right=root;
root->left=temp;
root=temp;
}
}
void deleteEnd()
{
struct node* temp,temp2;
temp=root;
while(temp->right!=NULL)
{
temp=temp->right;
}
temp2=temp->left;
temp2->right=NULL;
free(temp);
}
void delete()
{
struct node* temp;
int pos;
printf("Enter the position to delete:");
scanf("%d",&pos);
while(pos>1)
{
temp=temp->right;
pos--;
}
struct node* temp2;
temp2=temp->right;
temp2->right=temp->right;
temp->right->left=temp2;
free(temp);
temp=NULL;
}
void deletebegin()
{
struct node*temp=root;
root=root->right;
free(temp);
temp=NULL;
root->left=NULL;
}

