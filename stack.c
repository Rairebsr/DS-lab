#include<stdio.h>
int stack[50];
int top =-1;

void push(int item){
    
    
        top++;
        stack[top]=item;
        
    
}

int pop(){
    int store;
    if(top==-1){
        printf("stack is empty");
    }
    else{
        store=stack[top];
        top--;
    }
    return store;
}

int display(){
    int i;
    if(top==-1){
        printf("stack is empty");
    }
    else{
        for(i=0;i<=top;i++){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}



int main(){
    int arra[50];
    
    int num,c;
    do{
        printf(" enter choice\n 1.push\n 2.pop\n 3.display\n");
        scanf("%d",&c);
        
        switch(c){
            case 1:
                printf("enter the value: ");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3: 
                display();
                break;
            default: printf("invalid option");
        }
    }while(c!=4);
    
}