#include <iostream>
using namespace std;
int counter = 0;
class node
{
public:
    int data;
    node *left;
    node *right;
};

bool isEmpty(node *n)
{
    if (n == NULL)
    {
        return true;
    }
    return false;
}

void insert(node **n, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    node *temp = *n;
    node *y = NULL;
    if (*n == NULL)
    {
        *n = new_node;
        return;
    }

    while (temp != NULL)
    {
        y = temp;
        if (temp->data < data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if (data > y->data)
    {
        y->right = new_node;
    }
    else
    {
        y->left = new_node;
    }
}

void tree_search(node **n, int x)
{
    node *temp = *n;
    if (temp->data == x)
    {
        cout << "Data found at root !" << endl;
        return;
    }
    while (temp != NULL && temp->data != x)
    {
        if (temp->data < x)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if (temp == NULL)
    {
        cout << "Element not found !" << endl;
        return;
    }
    cout << "Element found !" << endl;
}

void inorder(node *n)
{
    if (n != NULL)
    {
        inorder(n->left);
        cout << n->data << *" ";
        inorder(n->right);
    }
}

void preorder(node *n)
{
    if (n != NULL)
    {
        cout << n->data << *" ";
        preorder(n->left);
        preorder(n->right);
    }
}

void postorder(node *n)
{
    if (n != NULL)
    {
        postorder(n->left);
        postorder(n->right);
        cout << n->data << *" ";
    }
}

int internal_count(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    if (n->left == NULL && n->right == NULL)
    {
        return 0;
    }
    return 1 + internal_count(n->left) + internal_count(n->right);
}

int leaf_count(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    if (n->left != NULL || n->right != NULL)
    {
        return leaf_count(n->left) + leaf_count(n->right);
    }
    return 1 + leaf_count(n->left) + leaf_count(n->right);
}

node *minval(node *n)
{
    while (n->left != nullptr)
    {
        n = n->left;
    }
    return n;
}
node *deletenode(node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            free(root);
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node *temp = minval(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
};