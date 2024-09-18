typedef struct node1{
    int data;
    struct node1* link;
}node;

#include <stdio.h>
#include<stdlib.h>

struct node1* top ;

void push(struct node1* head,int item){

    struct node1* newnode = malloc(sizeof(node));
    
        newnode->link = head->link;
        newnode->data = item;
        head->link = newnode;
        top = newnode;
    
}

int pop(struct node1* head){
    struct node1* temp;
    int store;
    if(head->link == NULL){
        printf("stack empty");
    }
    else{
        store = top->data;
        temp = top->link;
        head->link = temp;
        free(top);
        top = temp;
        return store;
    }
}

void display(struct node1* head){
    struct node1* ptr;
    ptr = top;
    if(head->link == NULL){
        printf("stack empty");
    }
    else{
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void main(){
    struct node1* head = malloc(sizeof(node));
    head->link = NULL;
    head->data = -1;

    int num,c;
    do{
        printf(" enter choice\n 1.push\n 2.pop\n 3.display\n");
        scanf("%d",&c);
        
        switch(c){
            case 1:
                printf("enter the value: ");
                scanf("%d",&num);
                push(head,num);
                break;
            case 2:
                pop(head);
                break;
            case 3: 
                display(head);
                break;
            default: printf("invalid option");
        }
    }while(c!=4);
    
}
