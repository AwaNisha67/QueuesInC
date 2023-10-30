/*IMPLEMENT THE OPERATIONS OF SIMPLE QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)*/
#include<stdio.h>
#include <stdlib.h>
void isEmpty(int i){
    if(i == -1){
        printf("\nQueue is empty");
    }
    else{
        printf("\nQueue is not empty yet");
    }
    
}
int peek(char arr[],int i){
    if(i == -1){
        isEmpty(i); 
        return -1;
    }
    return i;
}

void isFull(int size,int i){
    if(i == size-1){
        printf("\nQueue is Fulll");
        return;
    }
    printf("\nQueue is not yet Full");
}
int enqueue(char arr[],int size,char value[],int len,int i,int *j){
    if(i == size-1){
        isFull(size,i);
        return -1;
    }else{
        if(*j==-1){
            *j=0;
        }
        i++;
        int k;
        for(k=0;k<len;k++){
            arr[k] = value[k];
        }
        arr[k]='\0';
    }
     return i;
}
int dequeue(char arr[],int size,int *j){
    if(*j == -1){
        isEmpty(*j);
        return -1;
    }
    (*j)++;
    
    return *j;
}
void display(char arr[],int size,int i,int j){
    if (j == -1) {
        isEmpty(j);
    }
    else{
    int k;
    for(k=j;k<=i;k++){
        printf("%s ",arr[k]);
    }
        
    }
}

int main(){
    char arr[50],value[50];
    int size,topValue,ch,len=0;
    int i=-1,j=-1;
    printf("Enter the size of Your array: ");
    scanf("%d",&size);
    printf("\nPress 1: Insert");
    printf("\nPress 2: Delete");
    printf("\nPress 3: Peek");
    printf("\nPress 4: Empty or not");
    printf("\nPress 5: Full or not");
    printf("\nPress 6: Display");
    printf("\nPress 7: exit");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        
    switch(ch){
        case 1:printf("\nEnter value to insert: ");
        scanf("%s",&value);
        for(int i=0;value[i];i++){
            len++;
        }
        i=enqueue(arr,size,*value,len,i,&j);
        break;
        
        case 2:j=dequeue(arr,size,&j);
        break;
        
        case 3:topValue=peek(arr,i);
        printf("Value at %d is %s",topValue,arr[topValue]);
        break;
        
        case 4:isEmpty(j);
        break;
        
        case 5:isFull(size,i);
        break;
        
        case 6:display(arr,size,i,j);
        break;
        
        case 7:printf("\n****Code has been terminated****");
        exit(1);
        break;
        
        default:printf("\nInvalid choice");
        break;
    }
    }
}