#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

int top =-1;

void insert(struct node* head,int item){
    struct node* newnode = malloc (sizeof(node));
    struct node* temp;
    if(head->link == NULL){
        head->link = newnode;
        newnode->link = NULL;
        newnode->data = item;
    }
    else{
        newnode->link = head->link;
        newnode->data = item;
        head->link = newnode;
    }
}

int delete(struct node* head){
    int temp;
    if(head->link == NULL){
        printf("stack empty");
        return -1;
    }
    else{
        temp = head->link->data;
        head->link = head->link->link;
        return temp;
    }
}

void display(struct node* head){
    struct node* ptr =  head;
    if(head->link == NULL){
        printf("stack empty");
    }
    while(ptr != NULL){
        printf("%d",ptr->data);
        ptr = ptr->link;
    }
}

int main(){
    struct node* head = malloc(sizeof(node));
    head->data = 0;
    head->link = NULL;
    int num,rem,rev=0;
    struct node* ptr1 ;

    printf("enter number to be reversed: ");
    scanf("%d",&num);
    while(num != 0){
        rem = num % 10;
        rev = rev*10 +rem;
        num = num/10;
    }
    int no;
    while(rev != 0){
        no = rev % 10;
        insert(head,no);
        rev = rev/10;
    }
    while(head->link != NULL){
        int val = delete(head);
        printf("%d",val);
    }

}