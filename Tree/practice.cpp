#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *root;

node *create()
{
    int val;
    cout << "Enter data ( -1 for no node ) : ";
    cin >> val;
    node *newNode;
    newNode = new node;
    if (val == -1)
    {
        return NULL;
    }
    else
    {
        newNode->data = val;
        cout << "\nEnter left child of " << val << " , ";
        newNode->left = create();
        cout << "\nEnter right child of " << val << " , ";
        newNode->right = create();

        return newNode;
    }
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << " " << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    root = 0;
    root = create();
    preOrder(root);
    return 0;
}
