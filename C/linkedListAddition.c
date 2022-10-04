#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void llTraversal(struct node *head){
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
}

struct node * additionIndex(struct node * head, int ele, int index){
    struct node * p = head->next;
    struct node * q = head;
    int curr = 1;
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = ele;
    while(curr < index){
        q = q->next;
        p = p->next;
        curr ++;
    }
    q->next = ptr;
    ptr->next = p;

    return(head);
}

int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node ));
    struct node * second = (struct node *)malloc(sizeof(struct node ));
    struct node * third = (struct node *)malloc(sizeof(struct node ));

    int index, ele;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Enter the index and the element : \n");
    printf("Index : ");
    scanf("%d", &index);
    printf("Element : ");
    scanf("%d", &ele);

    printf("linked list before insertion : \n");
    llTraversal(head);

    printf("linked list after insertion : \n");
    head = additionIndex(head, ele, index);
    llTraversal(head);


    return 0;
}