#include <iostream>
#include <stack>
using namespace std;

int key = 1;
stack<int> s1, s2, displayStack;

void enQueue()
{
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    int x;
    key = 0;
    cout << "Enter the element to be pushed : ";
    cin >> x;
    s1.push(x);
}

void deQueue()
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    key = 1;
    if (s2.empty())
    {
        cout << "Underflow !" << endl;
    }
    else
    {
        cout << "The popped element is : " << s2.top() << endl;
    }
    s2.pop();
}

void peek()
{
    if (key == 0)
    {
        if (s1.size() == 0)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            while (!s1.empty())
            {
                displayStack.push(s1.top());
                s1.pop();
            }
            cout << "The front element of the queue is : " << displayStack.top() << endl;
            while (!displayStack.empty())
            {
                s1.push(displayStack.top());
                displayStack.pop();
            }
        }
    }
    else
    {
        if (s2.size() == 0)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            cout << "The front element of the queue is : " << s2.top() << endl;
        }
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "### Queue Operation ###" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            enQueue();
        }
        else if (choice == 2)
        {
            deQueue();
        }
        else if (choice == 3)
        {
            peek();
        }
        else if (choice == 4)
        {
            exit(1);
        }
    }
    return 0;
}