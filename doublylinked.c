#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *lLink;
	struct node *rLink;
};

typedef struct node NODE;

NODE* getNode(){
	return ((NODE*)malloc(sizeof(NODE)));
}

//adding each node in the front

NODE* insertFront(NODE *first,int item){
	NODE *temp = getNode();
	temp->info = item;
	if(first == NULL){
		temp->lLink = NULL;
		temp->rLink = NULL;
		return temp;
	}
	temp->lLink = NULL;
	temp->rLink = first;
	first->lLink = temp;
	return temp;
}


//insert new node to the left of the ode whose key is read as input
NODE* insertKey(NODE *first,int key,int item){
	NODE *temp,*trav;
	if(first == NULL){
		printf("Element not found as list is empty.\n");
		return first;
	}
	if(first->info == key){
		temp = getNode();
		temp->info = item;
		temp->lLink = NULL;
		temp->rLink = first;
		first->lLink = temp;
		return temp;
	}

	trav = first;
	while(trav!= NULL){
		if(trav->info==key){
			temp = getNode();
			temp->info = item;
			(trav->lLink)->rLink = temp;
			temp->lLink = trav->lLink;
			temp->rLink = trav;
			trav->lLink = temp;
			return first;
		}
		trav = trav->rLink;
	}
	printf("Element not found.\n");
	return first;
}

NODE* getlast(NODE *first){
	NODE *a;
	a = first;
	while (a->rLink!=NULL){
		a = a->rLink;
	}
	return a;
}

//delete the node node of a given data
NODE* del(NODE *first,NODE *last,int key){
	NODE *temp;
	//list is empty
	if(first==NULL){
		printf("Empty.\n");
		return first;
	}
	//first element is to be deleted
	if(first->info==key){
		temp=first->rLink;
		free(first);
		return temp;
	}

	//last element is to be deleted
	if(last->info==key){
		temp = last->lLink;
		free(last);
		last = temp;
		return first;
	}

	//node to be deleted is somewhere in  the middle or does not exist
	temp = first->rLink;
	while(temp!=last){
		if(temp->info == key){
			(temp->lLink)->rLink = temp->rLink;
			(temp->rLink)->lLink = temp->lLink;
			free(temp);
			return first;			
		}		
		temp = temp->rLink;
	}
	//element not found
	printf("Element not found.\n");
	return first;
}
//display contents of the list
void display(NODE *first){
	NODE *temp;
	if(first==NULL){
		printf("Empty.\n");
		return;
	}
	temp = first;
	while(temp != NULL){
		printf("%d\n",temp->info);
		temp=temp->rLink;
	}
}

int main(){
	int op,item,key;
	NODE *a;
	a = NULL;
	while(1){
		printf("Enter your choice\n1.Insert to Front\n2. Insert to left of key\n3. Delete key\n4. Display\n5. Exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter the item to insert\n");
				scanf("%d",&item);
				a = insertFront(a,item);
				break;
			case 2:
				printf("Enter the key and the item to insert\n");
				scanf("%d%d",&key,&item);
				a = insertKey(a,key,item);
				break;
			case 3:
				printf("Enter the key to delete\n");
				scanf("%d",&key);
				a = del(a,getlast(a),key);
				break;
			case 4:
				printf("The linked list\n");
				display(a);
				break;
			case 5:
				return 0;
		}
	}
	return 0;
}
