#include<stdio.h>
#define SIZE 10
struct st
{
 int a[SIZE];
 int top;
};
void push(struct st *s,int x)
{
 if(s->top==SIZE-1)
 printf("overflow");
 else
 {
 s->top++;
 s->a[s->top]=x;
 }
}
int pop(struct st *s)
{
 int y;
 if(s->top==-1)
 {
 printf("underflow");
 return 0;
 }
 else
 {
 y=s->a[s->top];
 s->top--;
 }
 return y;
}
void display(struct st *s)
{
 int i;
 if(s->top==-1)
 printf("underflow");
 else
 {
 for(i=s->top;i>=0;i--)
 {
 printf("%d",s->a[i]);
 }
 }
}
int main()
{
 int ch,x,y,z;
 struct st s;
 s.top=-1;
 do
 {
 printf("Enter coice 1.push, 2.pop, 3.display");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:printf("Enter element");
 scanf("%d",&x);
 push(&s ,x);
 break;
 case 2:y=pop(&s);
 printf("%d",y);
 break;
 case 3:display(&s);
 break;
 default:printf("Invalid choice");
 }
 printf("To continue press 1");
 scanf("%d",&z);
 }
 while(z==1);
return 0;
}
