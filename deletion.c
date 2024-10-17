#include<stdio.h>
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

struct node * first(struct node * head){
    struct node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct node * atIndex(struct node * head, int index){
    struct node * p = head;
    struct node * q = head->next;
    int i = 0;

    while(i<index-1){
        p = p-> next;
        q = q-> next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
} 

struct node * last(struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while(q->next != NULL){
        p = p-> next;
        q = q-> next;
    }
    p ->next = NULL;
    free(q);
    return head;
}

struct node * givenValue(struct node * head, int value){
    struct node * p = head;
    struct node * q = head->next;
    int i = 0;

    while(q -> data != value && q -> next != NULL){
        p = p-> next;
        q = q-> next;
    }

    if(q -> data == value){
        p -> next = q->next;
        free(q);
    }
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
    printf("before modification : \n");
    traversal(head);
    // head = first(head);
    // head = atIndex(head,1);
    // head = last(head);
    head = givenValue(head,21);
    printf("after modification : \n");
    traversal(head);
}