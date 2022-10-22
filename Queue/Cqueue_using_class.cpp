#include <iostream>
#define max 3

using namespace std;

class CQueue
{
private:
    int front = -1;
    int rear = -1;
    int arr[max];

public:
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (((rear + 1) % max) == front)
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
        if (isFull())
        {
            cout << "Queue is full !" << endl;
        }
        else
        {
            int element;
            if (front == -1 && rear == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % max;
            cout << "Enter the element to be pushed : ";
            cin >> element;
            arr[rear] = element;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty !" << endl;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % max;
            }
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty !" << endl;
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
            cout << "Queue is empty !" << endl;
        }
        else
        {
            if (front == rear)
            {
                cout << arr[front] << endl;
            }
            else if (front < rear)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << *" ";
                }
                cout << endl;
            }
            else if (front > rear)
            {
                for (int i = front; i < max; i++)
                {
                    cout << arr[i] << *" ";
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << arr[i] << *" ";
                }
            }
        }
    }
};

int main()
{
    int choice;
    CQueue q1;
    cout << "****** MENU ******" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
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
            q1.pop();
        }
        else if (choice == 3)
        {
            q1.peek();
        }
        else if (choice == 4)
        {
            q1.display();
        }
        else
        {
            exit(1);
        }
    }
    return 0;
}