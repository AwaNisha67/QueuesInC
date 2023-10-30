/*IMPLEMENT THE OPERATIONS OF DOUBLE ENDED QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)*/
#include<stdio.h>
void insertatFront(int arr[],int size,int front ,int rear){
    if(rear==size-1){
        printf("\nQueue is Full");
        return;
    }else if(front == -1 && rear == -1){
        front=rear=0;
    }else if(front == 0){
        front=size-1;
        // arr[front]=value;
    }else{
        front=front-1;
        // arr[front]=value;
    }
    arr[front]=value;
    return front;
}
void insertatRear(int arr[],int size,int front,int rear){
    if(rear==size-1){
        printf("\nQueue is Full");
        return;
    }
    rear++;
    arr[rear]=value;
    return rear;
}
void deleteatFront(int arr[],int size,int front){
    if(front == -1){
        printf("Queue is empty");
        return;
    }else if(front==rear)    
    {    
        //printf("\nThe deleted element is %d", deque[f]);    
        front=-1;    
        rear=-1;    
            
    }else if(front == (size-1)){
        front = 0;
    }else{
        front++;
        
    }
    return front;
}
void deleteatEnd(int arr[],int size,int front){
    if(front == -1){
        printf("Queue is empty");
        return;
    }else if(front==rear)    
    {    
        //printf("\nThe deleted element is %d", deque[f]);    
        front=-1;    
        rear=-1;    
            
    }else{
        rear--;
    }
    return rear;
}
void display(int arr[],int size,int front , int rear)    
{    
    int temp=front;    
    printf("\nElements in a deque are: ");    
        
    while(temp != rear)    
    {    
        printf("%d ",arr[temp]);    
        temp=(temp+1)%size;    
    }    
     printf("%d",arr[rear]);    
} 
void main(){
    printf("\n**************Double Ended Queue**************");
    printf("\nPress 1: To insert at front end");
    printf("\nPress 2: To insert at rear");
    printf("\nPress 3: To delete value at front");
    printf("\nPress 4: To delete value at rear");
    printf("\nPress 5: Display");
    printf("\nPress 6: Exit the code");
    while(1){
        printf("Enter your choice: ");
        scanf("%d ",&ch);
    switch(ch){
        case 1: 
    }
    }
}