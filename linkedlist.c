//written by anurag kumar
#include<stdio.h>
#include<stdlib.h>
struct list
{
int data;
struct list * next;
};
typedef struct list* NODE;
NODE getnode();
void freenode(NODE);
NODE insert_front(NODE,int);
NODE delet_front(NODE,int *);
NODE insert_rear(NODE,int);
NODE delet_rear(NODE,int *);
NODE del_pos(NODE,int *,int);
NODE del_val(NODE,int *,int);
NODE insert_pos(NODE,int,int);
void traverse(NODE);
void traverse_reverse(NODE);
NODE rev_list(NODE);
void main()
{
int p,ch,x,y=0;
NODE head;
head= NULL;
while(1)
{
printf("\n1. Insert front 2.Insert rear. 3. Delete front 4. Delete rear 5. Insert at postion
6. Delete at postion 7.Delete based on value 8. Display 9. Display reverse 10. Reverse
list 11. Exit\n");
printf("Enter ur choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter element to be inserted:");
scanf("%d",&x);
head = insert_front(head,x);break;
case 2: printf("Enter element to be inserted:");
scanf("%d",&x);
head =insert_rear(head,x);
break;
case 3: head = delet_front(head,&y);
if(y!=-1)
printf("deleted item is %d\n",y);
break;
case 4: head = delet_rear(head,&y);
if(y!=-1)
printf("deleted item is %d\n",y);
break;
case 5: printf("Enter element to be inserted:");
scanf("%d",&x);
printf("Enter the position:");
scanf("%d",&p);
head =insert_pos(head,x,p);
break;
case 6: printf("Enter the position:");
scanf("%d",&p);
head =del_pos(head,&y,p);
break;
case 7: printf("Enter the key value:");
scanf("%d",&p);
head =del_val(head,&y,p);
if(y==-1) printf("Element not found\n");
else printf("Deleted element is %d\n",y);
break;
case 8: traverse(head);
break;
case 9: traverse_reverse(head);
break;
case 10: head = rev_list(head);
break;
case 11: exit(0);
default : printf("Invalid choice\n");
} // end of switch
} // end of while
} // end of mainNODE getnode()
{
NODE tmp;
tmp = (NODE)malloc(sizeof(struct list));
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
NODE insert_front(NODE head, int x)
{
NODE tmp;
tmp = getnode();
tmp->data = x;
if(head == NULL)
{
tmp->next = NULL;
// inserting first node
return tmp;
}
tmp->next = head;
head = tmp;
return head;
}
NODE insert_rear(NODE head, int x)
{
NODE tmp,cur,prev;
cur=head;
tmp = getnode();
tmp->data = x;
tmp->next = NULL;
if(head == NULL)
{return tmp;
// inserting first node
}
while(cur!=NULL)
{
prev = cur;
cur = cur->next;
}
prev->next = tmp;
return head;
}
NODE delet_front(NODE head, int *val)
{
NODE tmp;
tmp = head;
if(head == NULL)
*val = -1;
else
{
*val = tmp->data;
head = head->next;
freenode(tmp);
}
return head;
}
NODE delet_rear(NODE head, int *val)
{
NODE tmp,cur;
tmp = cur = head;
if(head == NULL)
*val = -1;
else
{
while(cur->next!=NULL)
{
tmp = cur;
cur = cur->next;
}
if(tmp == cur) // When there is only one node in the list{
head=NULL;
tmp=NULL;
}
else
tmp->next=NULL;
*val = cur->data;
freenode(cur);
}
return head;
}
void traverse(NODE head)
{
NODE tmp;
tmp = head;
if(head == NULL)
{
printf("List is empty\n");
return;
}
printf("List contents are \n");
while(tmp!=NULL)
{
printf("%d ",tmp->data);
tmp=tmp->next;
}
}
void traverse_reverse(NODE head)
{
NODE tmp = head;
if(tmp==NULL)
return;
else
{
traverse_reverse(tmp->next);
printf("%d ",tmp->data);
}
}
// recursive function to traverse reverseNODE insert_pos(NODE head, int x,int pos)
{
NODE tmp,cur,prev;
int k=1;
if(pos<=0)
{
printf("Invalid position\n");
return head;
}
if(pos==1)
{
head = insert_front(head,x);
return head;
}
cur=head;
tmp = getnode();
tmp->data = x;
while(cur!=NULL && k<pos)
{
k++;
prev = cur;
cur = cur->next;
}
if(cur==NULL)
{
printf("Invalid position\n");
return head;
}
prev->next = tmp;
tmp->next = cur;
return head;
}
NODE del_pos(NODE head,int *val, int pos)
{
NODE tmp,cur;
int k=1;
tmp = cur = head;if(head == NULL)
*val = -1;
else
{
if(pos<=0)
{
printf("Invalid postion\n");
*val = -1;
return head;
}
if(pos==1)
{
head = delet_front(head,val);
return head;
}
while(cur!=NULL && k<pos)
{
k++;
tmp = cur;
cur = cur->next;
}
if(cur==NULL && k==pos) // To delete last node in the list.
{
head=NULL;
tmp=NULL;
}
else if(cur==NULL && k<pos)
{
printf("Invalid postion\n");
*val = -1;
return head;
}
else
tmp->next=cur->next;
*val = cur->data;
freenode(cur);
}
return head;
}NODE del_val(NODE head, int *val, int key)
{
NODE tmp,cur,p;
tmp = cur = head;
*val = -1;
if(head == NULL)
*val = -1;
else
{
while(cur!=NULL)
{
if(head->data == key)
{
head = delet_front(head,val);
tmp = cur = head;
*val = key;
}
else
{
tmp = cur;
cur = cur->next;
if(cur==NULL || cur->next == NULL)
p=NULL;
else
p=cur->next;
if(cur==NULL) break;
if(cur->data == key)
{
tmp->next=p;
freenode(cur);
cur=p;
*val = key;
}
}
}
}
return head;
}NODE rev_list(NODE head)
{
NODE tmp=NULL, nn = NULL;
while(head!=NULL)
{
nn = head->next;
head->next = tmp;
tmp = head;
head = nn;
}
return tmp;
}
