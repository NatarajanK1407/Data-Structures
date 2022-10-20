#include <iostream>
using namespace std;

#define max 10

class table
{
public:
    int data;
    table *next;
};

int hash_key(int x) // hashing key -> returns the position.
{
    return x % max; // hash function
}

void insert(table *hash[], int element)
{
    int i = hash_key(element);
    table *temp = hash[i];
    table *new_element = new table();
    new_element->data = element;
    new_element->next = NULL;
    if (hash[i] == NULL)
    {
        hash[i] = new_element;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_element;
}

bool search(table *hash[], int x)
{
    int i = hash_key(x);
    table *temp = hash[i];
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

void del(table *hash[], int element)
{
    int i = hash_key(element);
    table *temp = hash[i];
    table *prev = hash[i];
    if (hash[i]->data == element)
    {
        if (hash[i]->next == NULL)
        {
            hash[i] = NULL;
        }
        else
        {
            hash[i] = hash[i]->next;
        }
        return;
    }
    while (temp->data != element && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == element)
    {
        prev->next = temp->next;
        delete temp;
        return;
    }
}

void display(table *hash[])
{
    for (int i = 0; i < max; i++)
    {
        table *temp = hash[i];
        if (temp == NULL)
        {
            cout << "0" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data;
                if (temp->next != NULL)
                {
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

int main()
{
    table *hash[max] = {NULL};
    int choice;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
    while (true)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            int element;
            cout << "Enter the element to be inserted : ";
            cin >> element;
            insert(hash, element);
        }
        else if (choice == 2)
        {
            int element;
            cout << "Enter the element to be searched : ";
            cin >> element;
            if (search(hash, element))
            {
                cout << "Element Found !" << endl;
            }
            else
            {
                cout << "Element not Found !" << endl;
            }
        }
        else if (choice == 3)
        {
            int element;
            cout << "Enter the element to be deleted  : ";
            cin >> element;
            if (search(hash, element))
            {
                del(hash, element);
            }
            else
            {
                cout << "Element not found !" << endl;
            }
        }
        else if (choice == 4)
        {
            display(hash);
        }
        else if (choice == 5)
        {
            break;
        }
    }
}