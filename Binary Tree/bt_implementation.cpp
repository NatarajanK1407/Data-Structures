#include <iostream>
#include "binary_tree.h"
using namespace std;

int main()
{
    int choice, element;
    node *root = new node();
    root = NULL;
    cout << "1. Insert" << endl;
    cout << "2. Search an Element" << endl;
    cout << "3. Traversals" << endl;
    cout << "4. Delete Node" << endl;
    cout << "5. Counting of Nodes" << endl;
    while (true)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the data to be inserted : ";
            cin >> element;
            insert(&root, element);
        }
        else if (choice == 2)
        {
            int element;
            cout << "Enter the element to be searched : ";
            cin >> element;
            tree_search(&root, element);
        }
        else if (choice == 3)
        {
            if (isEmpty(root))
            {
                cout << "Empty Tree !" << endl;
            }
            else
            {
                char choice;
                cout << "\n\tTypes of Traversals" << endl;
                cout << "\ta. In-Order" << endl;
                cout << "\tb. Pre-Order" << endl;
                cout << "\tc. Post-Order" << endl;
                cout << "\tEnter your choice : ";
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {
                    cout << "\t";
                    inorder(root);
                    cout << endl;
                    break;
                }
                case 'b':
                {
                    preorder(root);
                    cout << endl;
                    break;
                }
                case 'c':
                {
                    postorder(root);
                    cout << endl;
                    break;
                }
                }
                cout << endl;
            }
        }
        else if (choice == 4)
        {
            int element;
            if (isEmpty(root))
            {
                cout << "Empty Tree !" << endl;
            }
            else
            {
                cout << "Enter the element to be deleted : ";
                cin >> element;
                deletenode(root, element);
            }
        }
        else if (choice == 5)
        {
            cout << endl;
            cout << "Count of Internal nodes is : " << internal_count(root) << endl;
            cout << "Count of Leaf nodes is : " << leaf_count(root) << endl;
        }
    }
}