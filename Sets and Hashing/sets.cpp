#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class setOperations
{
public:
    void intersection(int s1[], int size1, int s2[], int size2)
    {
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if (s1[i] == s2[j])
                {
                    cout << s1[i] << *" ";
                }
            }
        }
        cout << endl;
    }

    void union_set(int s1[], int size1, int s2[], int size2)
    {
        for (int i = 0; i < size1; i++)
        {
            cout << s1[i] << *" ";
        }
        for (int i = 0; i < size2; i++)
        {
            int flag = 0;
            for (int j = 0; j < size1; j++)
            {
                if (s2[i] == s1[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
            {
                cout << s2[i] << *" ";
            }
        }
        cout << endl;
    }

    void difference(int s1[], int size1, int s2[], int size2)
    {
        for (int i = 0; i < size1; i++)
        {
            int flag = 0;
            for (int j = 0; j < size2; j++)
            {
                if (s1[i] == s2[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << s1[i] << *" ";
            }
        }
        cout << endl;
    }

    void searcher(int s[], int x, int size)
    {
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == x)
            {
                flag = 1;
                cout << "The given element is a member of the set !" << endl;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "The given element is  not a member of the set !" << endl;
        }
    }
};

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    setOperations OP;
    int n, m, choice;
    cout << "Enter the size of Set 1 : ";
    cin >> n;
    cout << "Enter the size of Set 2 : ";
    cin >> m;
    int s1[n];
    int s2[m];
    cout << "Set 1 input : ";
    input(s1, n);
    cout << "Set 2 input : ";
    input(s2, m);
    cout << "1. Intersection" << endl;
    cout << "2. Union" << endl;
    cout << "3. Difference" << endl;
    cout << "4. Cardinality" << endl;
    cout << "5. Membership" << endl;
    while (true)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            OP.intersection(s1, n, s2, m);
        }
        else if (choice == 2)
        {
            OP.union_set(s1, n, s2, m);
        }
        else if (choice == 3)
        {
            OP.difference(s1, n, s2, m);
        }
        else if (choice == 4)
        {
            cout << "Cardinality of Set 1 : " << n << endl;
            cout << "Cardinality of Set 2 : " << m << endl;
        }
        else if (choice == 5)
        {
            int element, choices;
            cout << "Enter the element to be checked : ";
            cin >> element;
            cout << "1. Set 1" << endl;
            cout << "2. Set 2" << endl;
            cout << "Enter your choice : ";
            cin >> choices;
            if (choices == 1)
            {
                OP.searcher(s1, element, n);
            }
            else
            {
                OP.searcher(s2, element, m);
            }
        }
    }
}