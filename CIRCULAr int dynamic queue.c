/*IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN INTEGER Dynamically (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)*/
#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int data;
    struct circularQueue *next;
};
typedef struct circularQueue cq;
cq *i=NULL,*j=NULL,*nn;

void enqueue(int value){
nn=(cq*)malloc(sizeof(cq));
nn->data=value;
nn->next=NULL;

if(i==NULL && j==NULL){
    i=j=nn;
    i->next=j;//contains address of the 1st node ie "j";
}
else{
    i->next=nn;
    i=nn;
    i->next=j;
}
}
void dequeue(){
    cq *temp;
    temp=j;
    if(i==0 && j==0){
        printf("\nEmpty");
        return;
    }else if(i==j){
        i=j=NULL;
        free(temp);
    }else{
        j=j->next;
        i->next=j;
        free(temp);
    }
}
void display(){
    cq *temp;
    temp=j;
     if(i==0 && j==0){
        printf("\nEmpty");
        return;
     }
     else{
         do{
             printf("%d->",temp->data);
             temp=temp->next;
         }while(temp != j);
         
     }
}
void main(){
    int ch,value;
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
        enqueue(value);
        break;
        
        case 2:dequeue();
        break;
        
        case 3:display();
        break;
        
        case 4:printf("**Code has been terminated**");
        exit(1);
        break;
        default:printf("\nInvalid choice");
           
    }    
    }
}