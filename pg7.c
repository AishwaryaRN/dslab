#include<stdio.h>
#define MAX 100
int parent[MAX];int rank[MAX];
void makeSet(int n) {
for(int i=0;i<n;i++){
parent[i]=i;
rank[i]=0;
}
}
int find(int x) {
if(parent[x]!=x) {
parent[x]=find(parent[x]);
}
return parent[x];
}
void unionSets(int x,int y) {
int rootX=find(x);
int rootY=find(y);
if(rootX!=rootY) {
if(rank[rootX]>rank[rootY]) {
parent[rootY]=rootX;}
else if(rank[rootX]<rank[rootY]) {
parent[rootX]=rootY;}
else {
parent[rootY]=rootX;
rank[rootX]++; }
printf("Union completed:%d and %d are now in the same set.\n",x,y); }
else {
printf("Elements %d and %d are already in the same set.\n",x,y); }
}
int main() {
int n,choice,x,y;
printf("Enter the number of elements:");
scanf("%d",&n);
makeSet(n);
while(1) {
printf("\n MENU:\n");
printf("1.Find representative of an element\n");
printf("2.Union of two sets\n");
printf("3.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice) {
case 1:printf("Enter element to find its  set representative:\n");
scanf("%d",&x);
if(x>=0 && x<n) {
printf("Representative of %d is:%d\n",x,find(x)); }
else {
printf("Invalid Element.\n"); }
break;
case 2:printf("Enter two elements to perform union:");
scanf("%d%d",&x,&y);
if(x>=0 && x<n && y>=0 && y<n) {
unionSets(x,y);
}
else {
printf("Invalid elements \n");
}
break;
case 3:return 0;
default: printf("Invalid choice.please try again \n");
}
}
}

