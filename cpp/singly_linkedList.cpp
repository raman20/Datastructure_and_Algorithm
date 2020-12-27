#include <bits/stdc++.h>
using namespace std;

class Node
{
    private:

        int data;
        Node* next;

    public:
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
    private:
        Node* head;
    public:

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
                temp = temp->getNext();
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
                node->next = head;
                this->head = node; 
            }
            else
            {
                if(pos <= this->getSize())
                {
                    while(index < pos-1)
                    {
                        temp = temp->getNext();
                        ++index;
                    }
                    node->next = temp->getNext();
                    temp->setNext(node);
                }
            }
        }
        
        void addNodeBegin(int data)
        {
            this->addNodeByPos(data,1);
        }

        void addNodeEnd(int data)
        {
            this->addNodeByPos(data,this->getSize());  
        }

        void deleteNodeByPos(int pos)
        {
            //
        }

        void deleteNodeByData(int data)
        {
            //
        }

        void display()
        {
            Node* temp = this->head;

            if(this->isEmpty())
            {
                cout << "empty\n";
            }
            cout << "head-> ";
            while(temp)
            {
                cout << temp->getData() << "-> ";
                temp = temp->getNext();
            }
            cout << "tail" << endl;
        }
};

int main()
{
    LinkedList ll;
    ll.display();
    return 0;
}
