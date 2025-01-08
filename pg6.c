#include<stdio.h>
#define MAX_SIZE 8
void displayset(int set) {
printf("{");
for(int i=0;i<MAX_SIZE;i++) {
if(set &(1<<i)) {
printf("%d",i);
}
}
printf("}-Bitstring:");
for(int i= MAX_SIZE-1;i>=0;i--) {
printf("%d",(set>>i)&1);
}
printf("\n");
} 
int createSet(int n) {
int set=0,element;
printf("Enter %d elements:",n);
for(int i=0;i<n;i++) {
scanf("%d",&element);
if(element>=0 && element<MAX_SIZE) {
set|=(1<<element);
} else {
printf("Element %d out of range! Please enter elements between 0 and %d \n",element,MAX_SIZE-1);
i--;
}
} 
return set;
}
int unionSet(int SetA, int SetB) {
return SetA|SetB;
}
int intersectionSet(int SetA, int SetB) {
return SetA&SetB;
}
int differenceSet(int SetA, int SetB) {
return SetA&~SetB;
}
int main() {
int nA,nB;
printf("Enter the number of elements in Set A:");
scanf("%d",&nA);
int SetA=createSet(nA);
printf("Enter the number of elements in Set B:");
scanf("%d",&nB);
int SetB=createSet(nB);
printf("Set A:");
displayset(SetA);
printf("Set B:");
displayset(SetB);
int union_result=unionSet(SetA,SetB);
printf("Union of A and B:");
displayset(union_result);
int intersection_result=intersectionSet(SetA,SetB);
printf("Intersection of A and B:");
displayset(intersection_result);
int difference_result=differenceSet(SetA,SetB);
printf("Difference of A and B(A-B):");
displayset(difference_result);
return 0;
}


