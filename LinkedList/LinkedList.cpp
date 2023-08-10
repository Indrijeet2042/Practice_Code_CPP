#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node * START=NULL;


struct node *CreateNode()
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    return(n);
};

void insert_at_beginning()
{
    int x;
    struct node *temp,*t;
    temp=CreateNode();
    cout<<"Enter a number to be inserted";
    cin>>x;
    temp->val=x;

}
void insert_node()
{
    int x;
    struct node *temp,*t;
    temp=CreateNode();
    cout<<"Enter a number to be inserted::";
    cin>>x;
    temp->val=x;
    temp->next=NULL;
    t=START;
    if(START==NULL)
       START=temp;
    else
    {
        while(t->next !=NULL)
        {
            t=t->next;
        }
        t -> next = temp;
    }
}
void delete_first()
{
    struct node *x=new node;
    x=START;
    START=x->next;
    int num=x->val;
    delete x;
    cout<<"the deleted number is"<<num;
}
void delete_mid()
{
    int len=0;
    struct node *x=new node;
    struct node *y=new node;
    x=START;
    y=START;
    while(x->next!=NULL)
    len++;
    for(int i=0;i<int(len/2);i++)
      y=y->next;
    y->next=y->next->next;
}

void delete_end()
{
     struct node *x=new node;
    struct node *y=new node;
    x=START;
    if(x==NULL)
       cout<<"There is no node to delete";
    else
    {
    y=START->next;
    while(y->next!=NULL)
    {
        x=x->next;
    }
    }
    x->next=NULL;

}
void display()
{
    struct node *value=START;
    if(value==NULL)
        cout<<"There is no node";
    else
    {
        while(value!=NULL)
        {
        cout<<value->val<<"\t";
        value=value->next;
        }
    }
    cout << endl;
}

int main()
{
    cout << "If you want to enter a number press 1::" << endl;
    cout<<"If you want to insert a number at the beginning press 2"<<endl;
    cout<<"If you want to display the list press 3::"<<endl;
    cout<<"If you want to delete the first node press 4::"<<endl;
    cout<<"If you want to delete the mid element press 5::"<<endl;
    cout<<"If you want to delete the last element press 6::"<<endl;

     int i;
    while(1){
        cout<<"Enter your choice::";
        cin>>i;
        switch(i)
        {
            case 1:
                insert_node();
                break;
            case 2:
                insert_at_beginning();
                break;
            case 3:
                display();
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_mid();
                break;
            case 6:
                delete_end();
                break;
            default:
                exit(0);
        }
    }
    return (0);
}











