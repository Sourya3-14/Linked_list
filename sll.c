#include<stdio.h>
#include<stdlib.h>

struct linked_list{
    int data;
    struct linked_list *next;
};
struct linked_list *top=NULL;

struct linked_list * create(struct linked_list *header,int n){
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
    return header;
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
struct linked_list* insert_front(struct linked_list *header){
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=header;
    header=newNode;

    return header;
}
struct linked_list* insert_at(struct linked_list *header,int pos){
    struct linked_list *p=header;
    int i;
    for(i=1;i<pos-1;i++)
        p=p->next;
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=p->next;
    p->next=newNode;

    return header;
}



struct linked_list* insert_end(struct linked_list *header){
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=NULL;
    top->next=newNode;
    top=newNode;

    return header;
}

struct linked_list* insert_before(struct linked_list *header,int val){
    struct linked_list *pnext=header;
    struct linked_list *prev=header;
    
    while(pnext->data!=val){
        prev=pnext;
        pnext=pnext->next;
    }
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=pnext;
    prev->next=newNode;

    return header;
}

struct linked_list* insert_after(struct linked_list *header,int val){
    struct linked_list *p=header;
    int i;
    while(p->data!=val)
        p=p->next;
    struct linked_list *newNode;
    newNode=(struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data=10;
    newNode->next=p->next;
    p->next=newNode;

    return header;
}

struct linked_list * delete_at_pos(struct linked_list *header,int pos){
    struct linked_list *p=header;
    int i;
    for(i=1;i<pos-1;i++)
        p=p->next;
    struct linked_list *temp=p;
    temp=temp->next;
    p->next=temp->next;
    free(temp);

    return header;
}
struct linked_list * delete_front(struct linked_list *header){
    struct linked_list *temp=header;
    header=header->next;
    free(temp);

    return header;
}
struct linked_list *delete_end(struct linked_list *header){
    struct linked_list *p=header;
    while(p->next!=top)
        p=p->next;
    p->next=NULL;
    free(top);
    top=p;

    return header;
}
int search(struct linked_list *header,int val){
    struct linked_list *p=header;
    int pos=1;
    while(p!=NULL){
        if(p->data==val)
            return pos;
        p=p->next;
        pos++;
    }
    return -1;
}

int main()
{
    struct linked_list *header=NULL;

    header=create(header,10);
    display(header);
    printf("\n");

    header=insert_at(header,2);
    display(header);
    printf("\n");

    header=insert_before(header,3);
    display(header);
    printf("\n");

    header=insert_after(header,5);
    display(header);
    printf("\n");

    header=insert_front(header);
    display(header);
    printf("\n");

    header=insert_end(header);
    display(header);
    printf("\n");
    
    header=delete_at_pos(header,3);
    display(header);
    printf("\n");

    header=delete_front(header);
    display(header);
    printf("\n");

    header=delete_end(header);
    display(header);
    printf("\n");

    int x=search(header,3);
    printf("%d",x);
    printf("\n");
    
    return 0;
}