#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Stack
{
    private:

        int size;
        int arr[100];
        int top;
        
    public:

        Stack(int size)
        {
            this->size = size;
            this->top = -1;
        }

        int getNoElem()
        {
            int count{0};
            while(count <= top)
            {
                ++count;
            }
            return count;
        }

        void push(int data)
        {
            if(top < size)
            {
                top++;
                this->arr[top] = data;
            }
            else
            {
                cout << "stack_Overflow" << endl;
            }
        }

        int pop()
        {
            int data = 0;
            if(top > -1)
            {
                data = this->arr[top];
                top--;
                return data;
            }
            else
            {
                cout << "empty" << endl;
            }
            return data;
        }

        int getTop()
        {
            if(top > -1)
            {
                return arr[top];
            }

            return 0;
        }

        void display()
        {
            for(int i=this->top; i >= 0; --i)
            {
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.display();
    return 0;
}
