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
                cout<<ptr->data<<endl;
            }
            ptr->next=n;
        }

        void print()
        {
            Node *ptr=this;
            while(ptr)
            {
                // cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
        }

        
};


int main()
{
    Node LL=Node(1);
    LL.insert(2);
    LL.insert(3);
    LL.insert(3);
    LL.insert(3);
    LL.print();
    return 0;
}