// Addition and deletion in linked list

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node **head_ref,int new_value){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_value;
	new_node->next=(*head_ref);
	(*head_ref) = new_node;
}

void printList(struct node *head_ref){
	while(head_ref!= NULL){
		printf("%d  ",head_ref->data);
		head_ref=head_ref->next;
	}
}

void append(struct node **head_ref,int new_value){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_value;
	new_node->next = NULL;
	if((*head_ref)==NULL){
		(*head_ref) = new_node;
		return;
	}
	struct node *last=NULL;
	last = (*head_ref);
	while(last->next != NULL){
		last=last->next;
	}
	last->next = new_node;
}

void insertAfter(struct node **head_ref,int new_value,int afterThis){
	
	if((*head_ref)==NULL){
		printf("List is empty.\n");
		return;
	}
	
	struct node *afterThisNode=(*head_ref);
	while(afterThisNode->data != afterThis && afterThisNode->next != NULL){
		afterThisNode = afterThisNode->next;
	}
	
	if(afterThisNode->data == afterThis){
		struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_value;
	
	new_node->next = afterThisNode->next;
	afterThisNode->next = new_node;
	}
	else{
		printf("Value %d is not in list.\n",afterThis);
	}
	
	
}

void delete(struct node **head_ref,int value){
	
	if((*head_ref)==NULL){
		printf("List is empty.\n");
		return;
	}
	
	struct node *prevNode=NULL;
	struct node *nodeToBeDeleted=(*head_ref);
	if (nodeToBeDeleted != NULL && nodeToBeDeleted->data == value)
    {
        *head_ref = nodeToBeDeleted->next;   //Make it null
        free(nodeToBeDeleted);
        return;
    }
	while( nodeToBeDeleted != NULL && nodeToBeDeleted->data != value ){
		prevNode = nodeToBeDeleted;
		nodeToBeDeleted = nodeToBeDeleted->next;
	}
	if(nodeToBeDeleted->data == value){
		prevNode->next = nodeToBeDeleted->next;
		free(nodeToBeDeleted);
	}else{
		printf("Value %d is not in list.\n",value);
	}
	
}

void deleteNode(struct node **head_ref,int position){
	if((*head_ref)==NULL){
		printf("List is empty.\n");
		return;
	}
	struct node *prevNode,*temp = (*head_ref);
	if(position==0){
		(*head_ref)=temp->next;
		free(temp);
		return;
	}
	
	int i;
	for(i=1;temp!=NULL && i<=position;i++){
		prevNode = temp;
		temp=temp->next;
	}
	if(temp != NULL){
		prevNode->next = temp->next;
		free(temp);
	}else{
		printf("Not a valid position.\n");
	}
	
}

int getCount(struct node *head_ref){
	int count=0;
	struct node *temp=head_ref;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	return count;
}

int getCountRecursive(struct node *head_ref){
	if(head_ref==NULL){
		return 0;
	}else return 1+getCountRecursive(head_ref->next);
}

bool search(struct node *head_ref,int key){
	struct node *temp=head_ref;
	while(temp !=NULL){
		if(temp->data == key){
			return true;
		}else{
			temp = temp->next;
		}
	}
	return false;
}

bool searchRecursive(struct node *head_ref,int key){
	if(head_ref == NULL) return false;
	if(head_ref->data == key) return true;
	return searchRecursive(head_ref->next,key);
}

void swapNodes(struct node **head_ref,int x,int y){
	if(x==y) {
		printf("Nothing to swap.\n");
		return;
	}
	
	struct node *prevX=NULL,*curX=*head_ref;
	
	while(curX && curX->data != x){
		prevX=curX;
		curX = curX->next;
	}
	
	struct node *prevY=NULL,*curY=*head_ref;
	
	while(curY && curY->data != y){
		prevY=curY;
		curY = curY->next;
	}
	
	if (curX == NULL || curY == NULL){
       printf("One of the node is not present in the list.\n");
	   return;
	}
	
	if(prevX != NULL){
		prevX->next = curY;
	}else{
		*head_ref = curY;
	}
	
	if(prevY != NULL){
		prevY->next = curX;
	}else{
		*head_ref = curX;
	}
	struct node *temp = curY->next;
	curY->next = curX->next;
	curX->next = temp;
	
}

void printMiddle(struct node *head_ref){
	struct node *fastptr = head_ref,*slowptr = head_ref;
	if(head_ref!=NULL){
		while(fastptr!=NULL && fastptr->next !=NULL){
			fastptr = fastptr->next->next;
			slowptr = slowptr->next;
		}
		printf("The middle element is [%d]\n\n", slowptr->data);
	}
}

int main(){
	struct node *head=NULL;
	
	append(&head,50);
	append(&head,60);
	append(&head,70);
	push(&head,40);
	push(&head,30);
	push(&head,20);
	push(&head,10);
	insertAfter(&head,45,40);
	/*
	Now linked list is 
	10 20 30 40 45 50 60 70 
	*/
	printf("Created list is :\n");
	printList(head);
	delete(&head,45);
	printf("\n\nList after deleting node 45\n");
	printList(head);
	printf("\n\nList after deleting node at position 2\n");
	deleteNode(&head,2);
	printList(head);
	/*
	Now linked list is 
	10 20 40 50 60 70 
	*/
	int count = getCount(head);
	printf("\n\nNumber of nodes using non recursive function = %d\n",count);
	int count1 = getCountRecursive(head);
	printf("\nNumber of nodes using recursive function = %d\n",count1);
	
	
	printf("\nSearching for the element 70\n");
	search(head,70)?printf("Found\n"):printf("Not found\n");
	printf("\nSearching for the element 35\n");
	search(head,35)?printf("Found\n"):printf("Not found\n\n");
	printf("\nSearching for the element recursively 70\n");
	searchRecursive(head,70)?printf("Found\n"):printf("Not found\n");
	printf("\nSearching for the element recursively 35\n");
	searchRecursive(head,35)?printf("Found\n"):printf("Not found\n");
	
	printf("\nSwap nodes in a linked list without swapping data.\n");
	printf("Linked list is :\n");
	printList(head);
	printf("\n\nSwap(20,60)\n");
	swapNodes(&head,20,60);
	printList(head);
	printf("Middle of the linked list is:\n");
	printMiddle(head);
	
	return 0;
}

