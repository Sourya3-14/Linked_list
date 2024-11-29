#include<stdio.h>
#include<stdlib.h>

struct linked_list{
    int data;
    struct linked_list *next;
};
struct linked_list *top=NULL;
struct linked_list *header;

void create(/*struct linked_list *header,*/int n){
    header=(struct linked_list*)malloc(sizeof(struct linked_list));
    header->data=0;
    header->next=NULL;
    top=header;
    struct linked_list *newNode;
    int i;
    for(i=1;i<n;i++){
        newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
        newNode->data=i;
        newNode->next=NULL;
        top->next=newNode;
        top=newNode;
    }
}

void display(struct linked_list *node){
    while(node!=NULL)
    {
        printf("%d",node->data);
        node=node->next;
        if(node!=NULL)
            printf(" - ");
    }
}

void insert_at(int pos){
    struct linked_list *p=header;
    int i;
    for(i=1;i<pos-1;i++)
        p=p->next;
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=p->next;
    p->next=newNode;
}

void insert_front(){
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=header;
    header=newNode;
}
void insert_end(){
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=NULL;
    top->next=newNode;
    top=newNode;
}
void insert_before(int val){
    struct linked_list *p=header;
    int i;
    while((p->next)->data!=val)
        p=p->next;
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=p->next;
    p->next=newNode;
}
void insert_after(int val){
    struct linked_list *p=header;
    int i;
    while(p->data!=val)
        p=p->next;
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=p->next;
    p->next=newNode;
}
void delete_at_pos(int pos){
    struct linked_list *p=header;
    int i;
    for(i=1;i<pos-1;i++)
        p=p->next;
    struct linked_list *temp=p;
    temp=temp->next;
    p->next=temp->next;
    free(temp);
}
void delete_front(){
    struct linked_list *temp=header;
    header=header->next;
    free(temp);
}
void delete_end(){
    struct linked_list *p=header;
    while(p->next!=top)
        p=p->next;
    p->next=NULL;
    free(top);
    top=p;
}
int search(int val){
    struct linked_list *p=header;
    int pos=1;
    while(p!=NULL){
        if(p->data==val)
            return pos;
        p=p->next;
        pos++;
    }
}

int main()
{
    create(10);
    display(header);
    printf("\n");

    insert_at(3);
    display(header);
    printf("\n");

    insert_before(3);
    display(header);
    printf("\n");

    insert_after(3);
    display(header);
    printf("\n");

    insert_front();
    display(header);
    printf("\n");

    insert_end();
    display(header);
    printf("\n");
    
    delete_at_pos(3);
    display(header);
    printf("\n");

    delete_front();
    display(header);
    printf("\n");

    delete_end();
    display(header);
    printf("\n");

    int x=search(3);
    printf("%d",x);
    printf("\n");
    return 0;
}