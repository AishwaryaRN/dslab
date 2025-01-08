#include<stdio.h> 
#include<stdlib.h>
void merge_array(int arr1[],int arr2[], int res[], int n1,int n2)
{
int i=0, j=0, k=0;
while(i<n1 && j<n2)
{
if(arr1[i]<arr2[j])
{
res[k]=arr1[i];
i++,k++;
}
else
{
res[k++]=arr2[j++];
}
}
while (i<n1) 
{
res[k++]=arr1[i++];
}
while (j<n2)
 {
res[k++]=arr2[j++];
}
}

int main()
{
int n1,n2,i,j;

printf(" enter the first array:");
scanf("%d",&n1);
int *arr1= (int*)malloc(n1*sizeof(int));
printf("the first array is:");
for(i=0;i<n1;i++)
{
scanf("%d",&arr1[i]);
}
int*arr2= (int*)malloc(n2*sizeof(int));
printf(" enter the second array:");
scanf("%d",&n2);
printf("the second array is:");
for(j=0;j<n1;j++)
{
scanf("%d",&arr2[j]);
}
int*res= (int*)malloc(n1+n2*sizeof(int));
merge_array(arr1,arr2,res,n1,n2);
printf("Merge sorted array is:");
for(i=0;i<n1+n2;i++)
{
printf("%d",res[i]);
}
free(arr1);
free(arr2);
free(res);
return 0;
}

