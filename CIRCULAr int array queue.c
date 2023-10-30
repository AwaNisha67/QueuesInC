/*IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)*/

//Error: i dont know why its printing the size also 

#include<stdio.h>
#include<stdlib.h>
int enqueue(int arr[],int size,int value,int i,int j){
    if(((i+1)%size) == j){
        printf("Full");
        return -10;
    }else{
    if(j==-1){
        j=0;
    }
    i=(i+1)%size;
    arr[i]=value;
    return i;
  }
}
int dequeue(int arr[],int size,int i,int j){
    if(i==-1 && j==-1){
    printf("Empty");
    return -10;
    }
    else if(i == j){
        i=j=-1;
        printf("i & j is on -1");
    }else{
        j=(j+1)%size;
       
    }
     return j;
}
void display(int arr[],int size,int i,int j){
    int k;
    if(i==-1 && j==-1){
    printf("Empty");
    return;
    }else{
        k=j;
        while(k!=i){
            printf("%d->",arr[k]);
            k=(k+1)%size;
        }
        printf("%d",arr[i]);
    }
}
void main(){
    int arr[50];
 int ch,value,size=5;
 int i=-1,j=-1;
 //printf("Enter size of the queue:");
 //scanf("%d",&size);
    printf("\nPress 1: Insert");
    printf("\nPress 2: Delete");
    printf("\nPress 3: Display");
    printf("\nPress 4: Exit the code");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&ch);
    
    switch(ch){
        case 1:printf("\nEnter value to insert:");
        scanf("%d",&value);
        i=enqueue(arr,size,value,i,j);
        break;
        
        case 2:j=dequeue(arr,size,i,j);
        break;
        
        case 3:display(arr,size,i,j);
        break;
        
        case 4:printf("**Code has been terminated**");
        exit(1);
        break;
        default:printf("\nInvalid choice");
           
    }    
    }
}    
