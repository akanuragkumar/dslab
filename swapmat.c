#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,m,i,*p,j,temp,c,b,choice;
printf("ënter the array size");
scanf("%d %d",&n,&m);
printf("ënter %d elements",m*n);
p=(int*)calloc(m*n,(sizeof(int)));
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",(p+i*m+j));
}
}
printf("the array is\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",*(p+i*m+j));
}
printf("\n");
}
printf("enter the choice 1.Column Swap 2.Row Swap");
scanf("%d",&choice);
if(choice==1)
{
printf("enter the column to be swapped\t");
scanf("%d %d",&c,&b);
for(i=0;i<n;i++)
{temp=*(p+i*m+(c-1));
*(p+i*m+(c-1))=*(p+i*m+(b-1));
*(p+i*m+(b-1))=temp;
}
}
else if(choice==2)
{
printf("ënter the rows to be swapped\t");
scanf("%d %d",&c,&b);
for(i=0;i<m;i++)
{
temp=*(p+(c-1)*m+i);
*(p+(c-1)*m+i)=*(p+(b-1)*m+i);
*(p+(b-1)*m+i)=temp;
}
}
printf("the elements after swapping\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",*(p+i*m+j));
}
printf("\n");
}
free(p);
return 1;
}
