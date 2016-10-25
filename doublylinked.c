#include<stdio.h>
#include<stdlib.h>
struct dll
{
int data;
struct dll * rlink;
struct dll * llink;
};
typedef struct dll * NODE;
NODE getnode();
void freenode(NODE);
NODE ins_f(NODE,int);
NODE del_f(NODE,int *);
NODE ins_r(NODE,int);
NODE del_r(NODE,int *);
void search(NODE,int);
void disp(NODE);
NODE getnode()
{
NODE tmp;
tmp = (NODE)malloc(sizeof(struct dll));
if(tmp == NULL)
{
printf("Out of memory\n");
exit(0);
}
return tmp;
}
void freenode(NODE p)
{
free(p);
}
void main()
{
int p,ch,x,y=0;
NODE head;
head= NULL;
while(1)
{
printf("\n1. Insert front 2. Delete front 3. Insert rear 4. Delete rear 5. Display 6. Search 7. Exit \n");
printf("Enter ur choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter element to be inserted:");scanf("%d",&x);
head = ins_f(head,x);
break;
case 2: head = del_f(head,&y);
if(y!=-1)
printf("deleted item is %d\n",y);
break;
case 3: printf("Enter element to be inserted:");
scanf("%d",&x);
head = ins_r(head,x);
break;
case 4: head = del_r(head,&y);
if(y!=-1)
printf("deleted item is %d\n",y);
break;
case 5: disp(head);
break;
case 6: printf("Enter element to be searched:");
scanf("%d",&x);
search(head,x);
break;
case 7: exit(0);
default: printf("Invalid choice\n");
}
}
}
NODE ins_f(NODE head, int x)
{
NODE tmp;
tmp = getnode();
tmp->data = x;
tmp->llink = NULL;
if(head == NULL)
{
tmp->rlink = NULL; // inserting first node
return tmp;
}
tmp->rlink = head;
head->llink = tmp;
head = tmp;
return head;
}
NODE del_f(NODE head, int * val)
{
NODE tmp;
tmp = head;if(head == NULL)
{
*val= -1;
return head;
}
if(head->rlink == NULL)
{
head = NULL; // deleting last node of the list
}
else
{
head = head->rlink;
head->llink = NULL;
}
*val = tmp->data;
freenode(tmp);
return head;
}
NODE ins_r(NODE head, int x)
{
NODE tmp,cur;
cur=head;
tmp = getnode();
tmp->data = x;
tmp->rlink = NULL;
if(head == NULL)
{
tmp->llink = NULL; // inserting first node
return tmp;
}
while(cur->rlink!=NULL)
{
cur=cur->rlink;
}
cur->rlink = tmp;
tmp->llink = cur;
return head;
}
NODE del_r(NODE head, int *val)
{
NODE tmp,cur;
tmp = head;
if(head == NULL)
{
*val= -1;
return head;
}
while(tmp->rlink!=NULL){
tmp = tmp->rlink;
}
if(tmp==head)
head=NULL; // deleting last node
else
{
cur=tmp->llink;
cur->rlink = NULL;
}
*val = tmp->data;
freenode(tmp);
return head;
}
void disp(NODE head)
{
NODE tmp=head;
if(head == NULL)
{
printf("List is empty\n");
return;
}
for(tmp=head;tmp!=NULL;tmp=tmp-> rlink)
printf("%d ",tmp->data);
}
void search(NODE head, int key)
{
NODE tmp;
int c=0;
if(head == NULL)
{
printf("List is empty\n");
return;
}
for(tmp=head;tmp!=NULL;tmp=tmp-> rlink)
{
c++;
if(tmp->data == key)
{
printf("Key found at position %d\n",c);
return;
}
}
printf("Key not found\n");
}
