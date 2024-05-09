#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Node{
    private:
        Node *next;
        int data;
    public:

        Node()
        {
            this->next=NULL;
            this->data=-1;
        }
        Node(int data)
        {
            this->next=NULL;
            this->data=data;
        }

        void insert(int data)
        {
            
            
            if(this->data==-1)
            {
                this->data=data;
                return;
            }
            Node *n=new Node(data);
            Node *ptr=this;
            while(ptr->next)
            {
                ptr=ptr->next;
                // cout<<ptr->data<<endl;
            }
            ptr->next=n;
        }

        void print()
        {
            Node *ptr=this;
            while(ptr)
            {
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
        }

        void deleteMiddle()
        {
            Node *ptr1=this;
            Node *ptr2=this->next;

            while(ptr2 and ptr2->next)
            {
                ptr1=ptr1->next;
                ptr2=ptr2->next->next;
            }
            cout<<"Here"<<ptr1->data<<endl;
            while(ptr1->next and ptr1->next->next)
            {
                ptr1->data=ptr1->next->data;
                ptr1=ptr1->next;
            }
            ptr1->data=ptr1->next->data;
            delete ptr1->next;
            ptr1->next=NULL;
        }
        ~Node(){
            
        }

        
};


int main()
{
    Node LL=Node(1);
    LL.insert(2);
    LL.insert(3);
    LL.deleteMiddle();
    LL.print();
    return 0;
}