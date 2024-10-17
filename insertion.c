#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

int traversal(struct node * ptr){
    while(ptr != NULL){
    printf("element : %d\n",ptr->data);
    ptr = ptr->next;
    }
}

struct node * atFirst(struct node *head,int data){
    struct node * ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct node * inBetween(struct node *head,int data,int index){
    struct node * ptr = (struct node * ) malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr -> data = data;
    ptr->next = p->next;
    p ->next = ptr;
    return head;
}

struct node * atEnd(struct node * head,int data){
    struct node * ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node *p = head;
    while(p -> next != NULL){
        p = p->next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

struct node * afterNode(struct node * head,struct node * prevNode,int data){
    struct node * ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    
    return head;
}



int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth; 
    head = (struct node*)malloc(sizeof(struct node));
    second  = (struct node*)malloc(sizeof(struct node));
    third  = (struct node*)malloc(sizeof(struct node));
    fourth  = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head -> next = second;

    second -> data = 8;
    second -> next = third;

    third -> data = 90;
    third -> next = fourth;

    fourth -> data = 9;
    fourth -> next = NULL;
    printf("before modification :\n ");
    traversal(head);
    // head = atFirst(head,56);
    // head = inBetween(head,26,1);
    // head = atEnd(head,26);
    head = afterNode(head,second,45);
    printf("after modification :\n ");
    traversal(head);
    return 0;
}