//
// Created by heutlett on 7/5/20.
//

#ifndef DYNAMIC_LIBRARY_LIST_H
#define DYNAMIC_LIBRARY_LIST_H


class list
{
    struct node
    {
        int data;
        node *next;
    };

private:
            node *head, *tail;


public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    void createnode(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
};


#endif //DYNAMIC_LIBRARY_LIST_H
