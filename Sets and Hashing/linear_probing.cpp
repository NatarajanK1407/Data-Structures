#include <iostream>
using namespace std;
int del_pos;

int hash_key(int x, int size)
{
    return x % size;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == NULL)
        {
            cout << "--" << endl;
        }
        else
        {
            cout << arr[i] << endl;
        }
    }
}

void insert(int ele, int size, int arr[])
{
    int x = hash_key(ele, size);
    if (arr[x] == NULL)
    {
        arr[x] = ele;
        return;
    }
    while (arr[x] != NULL && x < size)
    {
        x++;
    }
    if (x == size)
    {
        cout << ele << " can't be inserted !" << endl;
    }
    arr[x] = ele;
}

bool search(int target, int arr[], int size)
{
    int key = hash_key(target, size);
    if (arr[key] == target)
    {
        del_pos = key;
        return true;
    }
    while (key < size)
    {
        if (arr[key] == target)
        {
            del_pos = key;
            return true;
        }
        key++;
    }
    if (key == size)
    {
        return false;
    }
}

void delete_cell(int arr[])
{
    arr[del_pos] = NULL;
}

int main()
{
    int size;
    cout << "Enter the size of the table : ";
    cin >> size;
    int element[size];
    int arr[size] = {NULL};
    cout << "Input " << size << " elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> element[i];
    }
    for (int i = 0; i < size; i++)
    {
        insert(element[i], size, arr);
    }
    cout << "-: The Hash Table [Linear Probing] for the input :-" << endl;
    display(arr, size);
    cout << "*  *   *   * MENU *    *   *   *" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Display" << endl;
    int choice;
    while (true)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            int solo_ele;
            cout << "Enter an element : ";
            cin >> solo_ele;
            insert(solo_ele, size, arr);
        }
        else if (choice == 2)
        {
            int elem;
            cout << "Enter the element to be searched : ";
            cin >> elem;
            if (search(elem, arr, size))
            {
                cout << "Element Found !" << endl;
            }
            else
            {
                cout << "Element not found !" << endl;
            }
        }
        else if (choice == 3)
        {
            int elem;
            cout << "Enter the element to be deleted : ";
            cin >> elem;
            if (search(elem, arr, size))
            {
                delete_cell(arr);
            }
            else
            {
                cout << "Element not found !" << endl;
            }
        }
        else if (choice == 4)
        {
            display(arr, size);
        }
        else
        {
            exit(1);
        }
    }
    return 0;
}