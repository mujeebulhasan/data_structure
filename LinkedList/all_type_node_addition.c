// Addition and deletion in linked list

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

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
	printf("\nList after deleting node 45\n");
	printList(head);
	printf("\nList after deleting node at position 2\n");
	deleteNode(&head,2);
	printList(head);
	int count = getCount(head);
	printf("\nNumber of nodes = %d\n",count);
	return 0;
}

