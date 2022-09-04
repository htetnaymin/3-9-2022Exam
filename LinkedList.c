#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
void print();
void insertAfter();
void insertTop();
void insertBottom();
void insertwithindex();
void delAfter();
void delTop();
void delBottom();
void delwithindex();
void editfirst();
void editCurrent();
void editwithindex();
void opt();
void opt1();
void opt2();
void opt3();
void pause();
int option=0;
int index1=0;
struct Node
{
    int data;
    int age;
    struct Node* next;
};
int main()
{
    printf("Welcome to my linkedlist.\n");
    int index=0;
    struct Node* first=NULL;
    struct Node* second=NULL;
    struct Node* third=NULL;
    first=(struct Node*)malloc(sizeof (struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof (struct Node));

    first->data=10;
    first->age=1000;
    first->next=second;

    second->data=20;
    second->age=2000;
    second->next=third;

    third->data=30;
    third->age=30000;
    third->next=NULL;

    insertAfter(first,15);
    insertTop(&first,5);
    insertBottom(first,35);
    print(first);
    opt(&first);
//    printf("Enter index to edit : ");
//    scanf("%d",&index);
//    editwithindex(first,index,100000);
//    insertwithindex(&first,index,99);
//    editCurrent(third,333);
    print(first);
    // delwithindex(&first,index);
//    delTop(&first);
//    delTop(&first);
//    delAfter(second);
//    delBottom(first);
    return 0;
}
void print(struct Node* first_node)
{
    while(first_node!=NULL)
    {
        printf("%d : ",first_node->data);
        first_node=first_node->next;
    }
    printf("NULL\n");
}
void insertAfter(struct Node* prev_node,int data)
{
    if(prev_node==NULL)
    {
        return;
    }
    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=prev_node->next;
    prev_node->next=newNode;
}
void insertTop(struct Node** head_ref , int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof (struct Node));

    newNode->data = data;
    newNode->next = (*head_ref);

    (*head_ref)=newNode;

}
void insertBottom(struct Node* first_node,int data)
{
    if(first_node==NULL)
    {
        printf("Error in delBottom!\n");
        return;
    }
    while(first_node!=NULL)
    {
        if(first_node->next==NULL)
        {
            struct Node* newNode=(struct Node*) malloc(sizeof (struct Node));
            newNode->data=data;
            newNode->next=NULL;
            first_node->next=newNode;
            return;
        }
        first_node=first_node->next;
    }
}
void insertwithindex(struct Node** first_node,int index,int data)
{
    int i =1;
    struct Node* temp=(struct Node*) malloc(sizeof (struct Node*));
    temp=(*first_node);
    while(temp!=NULL)
    {
        if(index==0)
        {
            insertTop(first_node,data);
            return;
        }
        if(i==index && temp!=NULL)
        {
            insertAfter(temp,data);
            return;
        }
        i++;
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Cannot insert your data.\n");
            return;
        }
    }
}
void delAfter(struct Node* prev_node)
{
    if(prev_node==NULL || prev_node->next==NULL)
    {
        printf("Error in delAfter!\n");
        return;
    }
    struct Node* newNode=(struct Node*) malloc(sizeof (struct Node));
    newNode=prev_node->next;
    prev_node->next=prev_node->next->next;
    free(newNode);
}
void delTop(struct Node** prev_node)
{
    if(prev_node==NULL)
    {
        return;
    }
    struct Node* newNode=(struct Node*) malloc(sizeof (struct Node));
    newNode=(*prev_node)->next;
    (*prev_node)->next=NULL;
    free((*prev_node));
//    printf("%d\n",(*prev_node)->data);
    (*prev_node)=newNode;
}
void delBottom(struct Node* first_node)
{
    if(first_node==NULL || first_node->next==NULL )
    {
        printf("Error in delBottom!\n");
        return;
    }
    int i=0;
    struct Node* newNode=(struct Node*) malloc(sizeof (struct Node));
    newNode=first_node;
    while(newNode!=NULL)
    {
        if(newNode->next->next==NULL)
        {
            struct Node* temp=(struct Node*)malloc(sizeof (struct Node));
            temp=newNode->next;
            newNode->next=NULL;
            free(temp);
            return;
        }
        newNode=newNode->next;
    }
}
void delwithindex(struct Node** first_node,int index)
{
    int i =1;
    struct Node* temp=(struct Node*) malloc(sizeof (struct Node*));
    temp=(*first_node);
    while(temp!=NULL)
    {
        if(index==0)
        {
            delTop(first_node);
            return;
        }
        if(i==index && temp!=NULL)
        {
            delAfter(temp);
        }
        i++;
        temp=temp->next;
    }
}
void editfirst(struct Node* first_node,int data)
{
    editCurrent(first_node,data);
}
void editCurrent(struct Node* curr_node,int data)
{
    if(curr_node==NULL)
    {
        printf("Error in editCurrent!\n");
        return;
    }
    curr_node->data=data;
}
void editwithindex(struct Node* first_node,int index,int data)
{
    int i =0;
    struct Node* temp=(struct Node*) malloc(sizeof (struct Node*));
    temp=first_node;
    while(temp!=NULL)
    {
        if(i==index && temp!=NULL)
        {
            editCurrent(temp,data);
            return;
        }
        i++;
        temp=temp->next;
    }
}
void opt(struct Node** first_node)
{

    printf("Chooose options :\n1.Insert\n2.Edit\n3.Delete\n0.Exit\n->");
    scanf("%d",&option);
    switch (option)
    {
        case 0:
            exit(0);
        case 1:
            opt1(first_node);
            break;
        case 2:
            opt2(first_node);
            break;
        case 3:
            opt3(first_node);
            break;
        default:
            printf("Invalid number!\n");
            opt(first_node);
    }
}
void opt1(struct Node** first_node)
{
    int data=0;
    printf("Choose options:\n1.Insert with index\n2.Insert Top\n3.Insert Bottom\nEnter 0 to go back\n->");
    scanf("%d",&option);
    switch (option)
    {
        case 0:
            opt(first_node);
            break;
        case 1:
            printf("Enter index to insert : ");
            scanf("%d",&index1);
            printf("Enter data : ");
            scanf("%d",&data);
            insertwithindex(first_node,index1,data);
            pause(*first_node);
            opt1(first_node);
            break;
        case 2:
            printf("Enter data : ");
            scanf("%d",&data);
            insertTop(first_node,data);
            pause(*first_node);
            opt1(first_node);
            break;
        case 3:
            printf("Enter data : ");
            scanf("%d",&data);
            insertBottom((*first_node),data);
            pause(*first_node);
            opt1(first_node);
            break;
        default:
            printf("Invalid option!\n");
            opt1(first_node);
            break;
    }
}
void opt2(struct Node** first_node)
{
    int data=0;
    printf("Choose options:\n1.Edit with index\nEnter 0 to go back\n->");
    scanf("%d",&option);
    switch (option)
    {
        case 0:
            opt(first_node);
            break;
        case 1:
            printf("Enter index to edit : ");
            scanf("%d",&index1);
            printf("Enter data : ");
            scanf("%d",&data);
            editwithindex(*first_node,index1,data);
            pause(*first_node);
            opt2(first_node);
            break;
        default:
            printf("Invalid option!\n");
            opt2(first_node);
            break;
    }
}
void opt3(struct Node** first_node)
{
    int data=0;
    printf("Choose options:\n1.Delete with index\n2.Delete Top\n3.Delete Bottom\nEnter 0 to go back\n->");
    scanf("%d",&option);
    switch (option)
    {
        case 0:
            opt(first_node);
            break;
        case 1:
            printf("Enter index to delete : ");
            scanf("%d",&index1);
            delwithindex(first_node,index1);
            pause(*first_node);
            opt3(first_node);
            break;
        case 2:
            delTop(first_node);
            pause(*first_node);
            opt3(first_node);
            break;
        case 3:
            delBottom(*first_node);
            pause(*first_node);
            opt3(first_node);
            break;
        default:
            printf("Invalid option!\n");
            opt3(first_node);
            break;
    }
}
void pause(struct Node* first_node)
{
    print(first_node);
    printf("Press enter to continue:");
    getch();
}
