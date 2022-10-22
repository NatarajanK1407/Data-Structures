#include <iostream>
#include "binary_tree.h"
using namespace std;

void smallest(node **root)
{
    node *temp = *root;
    if (temp->left == NULL)
    {
        *root = temp->right;
        cout << temp->data << " is deleted !" << endl;
        delete temp;
        return;
    }
    node *tracer = new node();
    while (temp->left != NULL)
    {
        tracer = temp;
        temp = temp->left;
    }
    tracer->left = temp->right;
    cout << temp->data << " is deleted !" << endl;
    delete temp;
}

void largest(node **root)
{
    node *temp = *root;
    if (temp->right == NULL && temp->left == NULL)
    {
        delete temp;
        return;
    }
    if (temp->right == NULL)
    {
        *root = temp->left;
        delete temp;
        return;
    }
    node *tracer = new node();
    while (temp->right != NULL)
    {
        tracer = temp;
        temp = temp->right;
    }
    if (temp->left == NULL)
    {
        tracer->right = NULL;
        delete temp;
        return;
    }
    tracer->right = temp->left;
}

int main()
{
    node *root = new node();
    root = NULL;
    int n, num;
    cout << "Enter the count of data : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a number : ";
        cin >> num;
        insert(&root, num);
    }
    cout << "In-Order before removing : ";
    inorder(root);
    cout << "\nRemoving the smallest element !" << endl;
    smallest(&root);
    inorder(root);
    cout << "\nRemoving the largest element !" << endl;
    largest(&root);
    inorder(root);
}