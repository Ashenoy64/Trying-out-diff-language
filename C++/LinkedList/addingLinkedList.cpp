#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class node
{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    node()
    {
        this->data=-1;
        this->next=NULL;
    }
    ~node()
    {

    }

};

class linkedList
{
    public:
    node *head;
    linkedList()
    {
        this->head=NULL;
    }

    void append(int data)
    {
        node *n=new node(data);
        if(this->head==NULL)
        {
            this->head=n;
            return;
        }
        node *ptr=this->head;
        while(ptr->next)
        {
            ptr=ptr->next;
        }
        ptr->next=n;

    }

    void print(){
        node *ptr=this->head;
        while(ptr)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    ~linkedList()
    {}

    void add(linkedList a,linkedList b)
    {
        int carry=0;
        node *ptr1=a.head;
        node *ptr2=b.head;

        while(ptr1 and ptr2)
        {
            int sum=carry+ptr1->data+ptr2->data;
            this->append(sum%10);
            carry=sum/10;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1)
        {
            int sum=carry+ptr1->data;
            this->append(sum%10);
            carry=sum/10;
            ptr1=ptr1->next;
        }
        while(ptr2)
        {
            int sum=carry+ptr2->data;
            this->append(sum%10);
            carry=sum/10;
            ptr2=ptr2->next;
        }

    }
};


int main()
{
    linkedList a;
    a.append(1);
    a.append(9);
    a.append(3);
    a.append(3);
    a.print();

    linkedList b;
    b.append(4);
    b.append(1);
    b.append(6);
    b.print();

    linkedList c;
    c.add(a,b);
    c.print();
    return 0;
}