#include<stdio.h>
#include<string.h>
int stack[50];
int top =-1;

void push(char item,int n){
    if(top == n-1 ){
        printf("stack overflow");
    }
    else{
        top+=1;
        stack[top]=item;
    }
}

int pop(){
    if(top==-1){
        printf("stack empty");
    }
    else{
        int item =stack[top];
        top-=1;
        return item;
    }
}

int main(){
    char chr[50],arr[50];
    int pall=1,i;
    printf("Enter an string: ");
    scanf(" %[^\n]",chr);

    for(i=0;i<strlen(chr);i++){
        push(chr[i],strlen(chr));
    }
    for(i=0;i<strlen(chr);i++){
        arr[i]=pop();
    }
    

    //to check if pallindrome
    for(i=0;i<strlen(chr);i++){
        if(chr[i]!=arr[i]){
            pall=0;
            break;
    }
}
    if(pall==1){
    printf("string is pallindrome");
    }
    else{
    printf("string is not pallindrome");
    }
}