/*
Merge two sorted linked lists in sorted order.
*/

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

struct node* SortedMerge(struct node *list1,struct node *list2){

	struct node *merged = NULL;
    struct node **tail = &merged;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            *tail = list1;
            list1 = list1->next;
        } else {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }
    *tail = list1 ? list1 : list2;
    return merged;

}

int main(){
	
	struct node *head1=NULL;
	struct node *head2=NULL;
	push(&head1,40);
	push(&head1,30);
	push(&head1,20);
	push(&head1,10);
	
	push(&head2,80);
	push(&head2,70);
	push(&head2,60);
	push(&head2,50);
	
	printList(head1);
	printf("\n");
	printList(head2);
	printf("\n");
	struct node *new_head = SortedMerge(head1,head2);
	printList(new_head);
	
	printf("\n");
	
	printList(head1);
	printf("\n");
	printList(head2);
	
}














