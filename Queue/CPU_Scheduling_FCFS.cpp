#include <iostream>
using namespace std;
#define max 10

int front = -1;
int rear = -1;
int clock;

struct CPU
{
    string jobname;
    int time;
} fcfs[max];

void enQueue()
{
    if ((rear + 1) % max == front)
    {
        cout << "Queue is already full, delete a job to enqueue a new one !" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % max;
        cout << "Enter the job name : ";
        cin >> fcfs[rear].jobname;
        cout << "Enter the time : ";
        cin >> fcfs[rear].time;
        clock = clock + fcfs[rear].time;
        cout << "Total Time : " << clock << endl;
    }
}

void printer(int i)
{
    cout << "The job dequeued is : " << fcfs[i].jobname << endl;
    clock = clock - fcfs[i].time;
    cout << "Total <updated> time : " << clock << endl;
}

void deQueue()
{
    if (front == -1 && rear == -1)
    {
        cout << "No jobs at queue for CPU !" << endl;
    }
    else if (front == rear)
    {
        int i = front;
        printer(i);
        front = -1;
        rear = -1;
    }
    else
    {
        int i = front;
        printer(i);
        front = (front + 1) % max;
    }
}

int main()
{
    int choice;
    cout << "#### JOB SCHEDULING ####" << endl;
    cout << "1. Enqueue <job>" << endl;
    cout << "2. Dequeue <job>" << endl;
    cout << "3. Exit" << endl;
    while (true)
    {
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
            exit(1);
        }
    }
}