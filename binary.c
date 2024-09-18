 #include<stdio.h>

 int main(){
    int i,j,n,key,top,bott,mid,arr[50],temp,st[50];

    printf("enter the no of elements: ");
    scanf("%d",&n);

    printf("enter the elements in ascending order: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        
    }
    
    printf("enter the key: ");
    scanf("%d",&key);

    top =0;
    bott =n-1;
    while(top<=bott){
        mid =(top+bott)/2;
        if(arr[mid]==key){
            printf("key found at position %d",mid+1);
            break;
        }
        else if(arr[mid]<key){
            top =mid+1;
        }
        else{
            bott =mid-1;
        }
    }
 }