#include <iostream>
using namespace std;
#define max 2
int front = -1;
int rear = -1;

struct craft
{
    string company;
    string model;
    int range;
    int age;
} Queue[max];

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

void enQueue()
{
    if ((rear + 1) % max == front)
    {
        cout << "Queue is Overflow !" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % max;
        cout << "Enter the company of the craft : ";
        cin >> Queue[rear].company;
        cout << "Enter the model of the craft : ";
        cin >> Queue[rear].model;
        cout << "Enter the range of the craft : ";
        cin >> Queue[rear].range;
        cout << "Enter the age of the craft : ";
        cin >> Queue[rear].age;
    }
}

void deQueue()
{
    if (front == rear) //The only element !
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

void printer(int i)
{
    cout << endl;
    cout << "Company : " << Queue[i].company << endl;
    cout << "Model : " << Queue[i].model << endl;
    cout << "Age of the Craft : " << Queue[i].age << endl;
    cout << "Range : " << Queue[i].range << endl;
    cout << "__________________________________________________________________" << endl;
}

void selector(int x)
{
    if (x == 1)
    {
        if (front == rear)
        {
            cout << "Only one craft is available !" << endl;
            printer(front);
        }
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                if (Queue[i].range >= 1000)
                {
                    printer(i);
                }
            }
        }
        else
        {
            for (int i = front; i < max; i++)
            {
                if (Queue[i].range >= 1000)
                {
                    printer(i);
                }
            }
            for (int i = 0; i <= rear; i++)
            {
                if (Queue[i].range >= 1000)
                {
                    printer(i);
                }
            }
        }
    }
    else
    {
        if (front == rear)
        {
            cout << "Only one craft is available !" << endl;
            printer(front);
        }
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                if (Queue[i].range >= 500)
                {
                    printer(i);
                }
            }
        }
        else
        {
            for (int i = front; i < max; i++)
            {
                if (Queue[i].range >= 500)
                {
                    printer(i);
                }
            }
            for (int i = 0; i <= rear; i++)
            {
                if (Queue[i].range >= 500)
                {
                    printer(i);
                }
            }
        }
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Flight Selector" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            enQueue();
        }
        else if (choice == 2)
        {
            if (isEmpty())
            {
                cout << "Queue is underflow !" << endl;
            }
            else
            {
                deQueue();
            }
        }
        else if (choice == 3)
        {
            if (isEmpty())
            {
                cout << "Queue is Underflow !" << endl;
            }
            else
            {
                int i = front;
                printer(i);
            }
        }
        else if (choice == 4)
        {
            if (front == rear)
            {
                int i = front;
                printer(i);
            }
            else if (front < rear)
            {
                for (int i = 0; i <= rear; i++)
                {
                    printer(i);
                }
            }
            else if (rear < front)
            {
                for (int i = front; i < max; i++)
                {
                    printer(i);
                }
                for (int i = 0; i <= rear; i++)
                {
                    printer(i);
                }
            }
        }
        else if (choice == 5)
        {
            if (isEmpty())
            {
                cout << "Queue is Underflow !";
            }
            else
            {
                int type;
                cout << "Enter 1 for International Travel & 2 for Domestic Travel : ";
                cin >> type;
                selector(type);
            }
        }
        else if (choice == 6)
        {
            exit(1);
        }
    }
}