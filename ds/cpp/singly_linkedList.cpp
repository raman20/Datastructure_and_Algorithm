#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:

        int data;
        Node* next;

        Node(int data)
        {
            setData(data);
            next = NULL;
        }

        void setData(int data)
        {
            this->data = data;
        }

        int getData()
        {
            return this->data;
        }

        void setNext(Node* node)
        {
            this->next = node;
        }

        Node* getNext()
        {
            return this->next;
        }
};

class LinkedList
{
    public:
        Node* head;

        LinkedList()
        {
            this->head = NULL;
        }
        
        int getSize()
        {
            Node* temp = this->head;
            int count{0};
            
            while(temp)
            {
                temp = temp->next;
                count++;
            }
            
            return count;
        }

        bool isEmpty()
        {
            return this->head == NULL;
        }

        void addNodeByPos(int data, int pos)
        {
            Node* node = new Node(data);
            Node* temp = this->head;
            int index(0);

            if(this->head == NULL)
            {
                addNodeBegin(data);
            }
            else
            {
                if(pos < this->getSize())
                {
                    while(index < pos)
                    {
                        temp = temp->next;
                        ++index;
                    }
                    node->next = temp->next;
                    temp->next = node;
                }
            }
        }
        
        void addNodeBegin(int data)
        {
            Node* node = new Node(data);
            node->next = head;
            this->head = node;
        }

        void addNodeEnd(int data)
        {
            this->addNodeByPos(data, this->getSize()-1);  
        }

        void deleteNodeByPos(int pos)
        {
            int index(0);
            Node* temp = this->head;
                
            if(pos < this->getSize())
            {
                if(pos == 0)
                {
                    this->head = this->head->next;
                    return;
                }
                while(index < pos)
                {
                    temp = temp->next;
                    index++;
                }
                temp->next = temp->next->next;
            }
        }

        void deleteNodeByData(int data)
        {
            Node* temp = this->head;
            Node* prev;
            while(temp)
            {
                if(data==temp->getData())
                {
                    prev->next = temp->next;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        void display()
        {
            Node* temp = this->head;

            if(this->isEmpty())
            {
                cout << "empty\n";
                return;
            }
            cout << "head-> ";
            while(temp)
            {
                cout << temp->getData() << "-> ";
                temp = temp->next;
            }
            cout << "tail" << endl;
        }
};

int main()
{
    LinkedList ll;
    ll.display();
    ll.addNodeBegin(1);
    ll.addNodeBegin(2);
    ll.addNodeBegin(3);
    ll.display();
    ll.addNodeEnd(4);
    ll.addNodeEnd(5);
    ll.display();
    ll.deleteNodeByData(4);
    ll.deleteNodeByData(5);
    ll.display();
    ll.deleteNodeByPos(0);
    ll.display();
    ll.deleteNodeByPos(1);
    cout << ll.getSize() << endl; 
    return 0;
}
