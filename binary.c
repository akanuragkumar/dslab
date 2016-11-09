#include<stdio.h>
#include<stdlib.h>
int c=0;
int binarysearch(int *,int,int);
int binarysearch(int *a,int m,int n)
{
 
    int l,u,mid;
l=0,u=n-1;
    while(l<=u)
        {
         mid=(l+u)/2;
         if(m==a[mid])
            {
             c=1;
             break;
         }
         else if(m<a[mid])
            {
             u=mid-1;
         }
         else
             l=mid+1;
    }
    return mid;
}
int main()
{
 
    int *a,i,n,m,pos;
 
    printf("Enter the size of an array: ");
    scanf("%d",&n);
        a=(int*)malloc(n*sizeof(int));
 
    printf("Enter the elements in ascending order: ");
    for(i=0;i<n;i++)
        {
         scanf("%d",(a+i));
    }
 
    printf("Enter the number to be search: ");
    scanf("%d",&m);
        pos=binarysearch(a,m,n);
 
     
    if(c==0)
         printf("The number is not found.\n");
    else
         printf("The number is found at position %d\n",pos+1);
 
    return 0;
}
