#include <iostream>
using namespace std;
#define max 3

struct Queue
{
    int front = -1;
    int rear = -1;
    int arr[max];
} q1, q2;

void enQueue(Queue *q)
{
    int element;
    if ((q->rear + 1) % max == q->front)
    {
        cout << "Overflow !" << endl;
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % max;
        cout << "Enter an element : ";
        cin >> element;
        q->arr[q->rear] = element;
    }
}

void deQueue(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        cout << "Underflow !" << endl;
    }
    else if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % max;
    }
}

bool compare(Queue *a, Queue *b) /*Before comparing copy values to other dup. variables, so that it does not affect queue operations after comparing*/
{
    if (a->front == -1 && b->front == -1)
    {
        cout << "Queue is empty !" << endl;
        return true;
    }
    if (a->front == -1 || b->front == -1)
    {
        return false;
    }
    while (a->front != a->rear && b->front != b->rear)
    {
        if (a->arr[a->front] != b->arr[b->front])
        {
            return false;
        }
        a->front = (a->front + 1) % max;
        b->front = (b->front + 1) % max;
    }
    if (a->arr[a->front] != b->arr[b->front])
    {
        return false;
    }
    if (a->front != a->rear || b->front != b->rear)
    {
        return false;
    }
    return true;
}

int main()
{
    int choice;
    cout << "1. Enqueue <Q1>" << endl;
    cout << "2. Enqueue <Q2>" << endl;
    cout << "3. Dequeue <Q1>" << endl;
    cout << "4. Dequeue <Q2>" << endl;
    cout << "5. Compare" << endl;
    cout << "6. Exit" << endl;
    while (true)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            enQueue(&q1);
        }
        else if (choice == 2)
        {
            enQueue(&q2);
        }
        else if (choice == 3)
        {
            deQueue(&q1);
        }
        else if (choice == 4)
        {
            deQueue(&q2);
        }
        else if (choice == 5)
        {
            if (compare(&q1, &q2))
            {
                cout << "Queues are equal !" << endl;
            }
            else
            {
                cout << "Queues are not equal !" << endl;
            }
        }
        else if (choice == 6)
        {
            exit(1);
        }
    }
}