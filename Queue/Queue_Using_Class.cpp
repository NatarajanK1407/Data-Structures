#include <iostream>
#define max 5
using namespace std;

class Queue
{
private:
    int front = -1;
    int rear = -1;
    int arr[max];

public:
    bool isFull()
    {
        if (rear == max - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (rear == -1 && front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push()
    {
        int x;
        if (isFull())
        {
            cout << "Queue is full !" << endl;
        }
        else
        {
            cout << "Enter the element : ";
            cin >> x;
            if (isEmpty())
            {
                front = 0;
            }
            rear++;
            arr[rear] = x;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is underflow !" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is underflow !" << endl;
        }
        else
        {
            cout << arr[front] << endl;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is underflow !" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << *" ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue q1, q2;
    int choice;
    cout << "******* MENU *******" << endl;
    cout << "1. Push <Q1>"
         << "\t";
    cout << "2. Push <Q2>" << endl;
    cout << "3. Pop <Q1>"
         << "\t";
    cout << "4. Pop <Q2>" << endl;
    cout << "5. Peek <Q1>"
         << "\t";
    cout << "6. Peek <Q2>" << endl;
    cout << "7. Display <Q1>"
         << "\t";
    cout << "8. Display <Q2>" << endl;
    while (true)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            q1.push();
        }
        else if (choice == 2)
        {
            q2.push();
        }
        else if (choice == 3)
        {
            q1.pop();
        }
        else if (choice == 4)
        {
            q2.pop();
        }
        else if (choice == 5)
        {
            q1.peek();
        }
        else if (choice == 6)
        {
            q2.peek();
        }
        else if (choice == 7)
        {
            q1.display();
        }
        else if (choice == 8)
        {
            q2.display();
        }
        else
        {
            exit(1);
        }
    }
}