/* IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE DYNAMICALLY OF INTEGERS (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)*/
#include<stdio.h>
#include<stdlib.h>
struct Priorityqueue{
    int data;
    int prio;
    struct Priorityqueue *next;
};
typedef struct Priorityqueue pq;
pq *front=NULL,*rear=NULL,*nn;
void pqenqueue(int value ,int prio){
    pq *sl,*search,*temp;
    nn=(pq*)malloc(sizeof(pq));
    nn->data=value;
    nn->prio=prio;
    nn->next=NULL;
    
    temp=nn;
    if(front==NULL && rear==NULL){
        front=rear=nn;
    }else{
        sl=NULL;
        search=front;
        while(temp->prio > search->prio && search != NULL){
            sl=search;
            search=search->next;
        }
        if(sl != NULL){
            temp->next=sl->next;
            sl->next=temp;
        }else{
            //agr sl==NULL to already ek hi node exist karta hai
            temp->next=front;
            front=temp;
        }
    }
}
void dequeue(){
    pq *temp;
    temp=front;
    if(rear==0 && front==0){
        printf("\nEmpty");
        return;
    }else if(rear == front){
        rear=front=NULL;
        free(temp);
    }else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void display(){
    pq *temp;
    temp=rear;
     if(rear==0 && front==0){
        printf("\nEmpty");
        return;
     }
     else{
         do{
             printf("%d->",temp->data);
             temp=temp->next;
         }while(temp != front);
         
     }
}
void main(){
    int value,prio,ch;
    printf("\nPress 1: To insert value");
    printf("\nPress 2: To delete value");
    printf("\nPress 3: To display values");
    printf("\nPress 4: Exit the code");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
    switch(ch){
        case 1: printf("\nEnter value to insert: ");
        scanf("%d",&value);
        printf("\nEnter the priority");
        scanf("%d",&prio);
        pqenqueue(value,prio);
        break;
        
        case 2:dequeue();
        break;
        
        case 3:display();
        break;
        
        case 4:printf("***Code has been terminated***");
        exit(1);
        break;
        
        default:printf("\nInvalid choice");
        break;
    }
    }
}