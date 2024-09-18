#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}node;

struct node* create(){
    struct node* new = (struct node*)malloc(sizeof(node));
    return new;
}

struct node* insert(struct node* head,char item){
    //struct node* new = malloc(sizeof(node));
    struct node* new =create();
    if(head == NULL){
        head = new;
        new->data = item;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else{
        new->left = head;
        new->right =NULL;
        new->data = item;
        head->right = new;
        head = new;
        return new;
    }
}


void display(struct node* head){
    struct node* eg = head;
    while(eg != NULL){
        printf("%c",eg->data);
        eg = eg->left;
    }
}
void checkpall(struct node* head){
    struct node* temp = head;
    struct node* temp2 = head;
    int flag =0;
    while(temp->left != NULL){
        temp = temp->left;
    }
    while(temp != NULL && temp2 != NULL){
        if(temp->data != temp2->data){
            flag =1;
            break;
        }
        temp = temp->left;
        temp2 = temp2->right;
    }
    if(flag){
        printf("not pallindrome");
    }
    else{
        printf("is pallindrome");
    }
}
int main(){
    struct node* head=NULL ;
    char str[50];
    int i;
    printf("enter the string: ");
    scanf("%[^\n]",str);

    for(i=0;str[i] != '\0';i++){
        head = insert(head,str[i]);
    }
    printf("REVERSING THE STRING\n");
    display(head);
    printf("\n");
    printf("CHECKING IF PALLINDROME\n");
    checkpall(head);

    return 0;
}