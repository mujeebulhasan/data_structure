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

struct node* reverseList(struct node *head){
	struct node *prev = NULL , *current = head , *next;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

void reverseListRecursive(struct node *head){
	
	
}

int main(){
	
	struct node *head=NULL;
	push(&head,40);
	push(&head,30);
	push(&head,20);
	push(&head,10);
	printList(head);
	printf("\n");
	/* 10 20 30 40 */
	head = reverseList(head);
	printList(head);
	
	return 0;
}