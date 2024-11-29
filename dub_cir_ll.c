#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *header=NULL;
struct Node *top=NULL;


void create(int n){
    header=(struct Node *)malloc(sizeof(struct Node));
    header->data=0;
    header->next=header;
    header->prev=header;
    top=header;
    for(int i=1;i<n;i++){
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=i;
        top->next=newNode;
        newNode->prev=top;
        newNode->next=header;
        header->prev=newNode;
        top=newNode;
    }
}
void display()
{
    struct Node *ptr=header;

    if(header!=NULL)
    {
        do{
            printf("%d-",ptr->data);
            ptr=ptr->next;
        }while(ptr!=header);
    }
    printf("\n");
}
void insert_front(){
    if(header!=NULL){
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        (header->prev)->next=newNode;
        newNode->prev=header->prev;
        newNode->data=10;
        newNode->next=header;
        header->prev=newNode;
        header=newNode;
    }
    else{
        header=(struct Node *)malloc(sizeof(struct Node));
        header->data=0;
        header->next=header;
        header->prev=header;
        top=header;
    }
}
void insert_end(){
    struct Node *ptr=header;
    if(header!=NULL){
        while(ptr->next!=header)
            ptr=ptr->next;
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=11;
        ptr->next=newNode;
        newNode->prev=ptr;
        newNode->next=header;
        header->prev=newNode;
        top=newNode;
    }
    else{
        header=(struct Node *)malloc(sizeof(struct Node));
        header->data=1;
        header->next=header;
        header->prev=header;
        top=header;
    }
}
void delete_at(int pos){
    struct Node *ptr=header;

    if(header!=NULL){
        for(int i=1;i<pos-1;i++){
            ptr=ptr->next;
        }
    struct Node *temp;

    if(ptr!=ptr->next){
        temp=ptr->next;
        ptr->next=temp->next;
        (temp->next)->prev=ptr;
        free(temp);
    }
    else{
        free(ptr);
        header=NULL;
    }
    }
    else{
        printf("The list is empty\n");
    }
}
int main(){
    create(1);
    display();
    insert_front();
    display();
    insert_end();
    display();
    delete_at(1);
    display();
    return 0;
}